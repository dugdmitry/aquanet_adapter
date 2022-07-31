/**************************************************************************
 * Developed by Zheng (James) Peng                                         *
 * This is a research project from University of Connecticut               *
 * Copyright (C) 2010, all rights reserved                                 *
 **************************************************************************/

#ifndef AQUA_SOCKET
#define AQUA_SOCKET

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "aquanet_pdu.h"
#include "aquanet_log.h"

extern char* log_file_name;
extern const char* __progname;

#define MAX_SOCK_QUEUE 5
#define AQUA_SOCK_TIMEOUT 10
#define BUFSIZE	1024

#define AQUA_APP	"AQUA_APP"
#define AQUA_TRA	"AQUA_TRA"
#define AQUA_NET	"AQUA_NET"
#define AQUA_MAC	"AQUA_MAC"
#define AQUA_PHY	"AQUA_PHY"


/* Address families. */
#define AF_AQUANET	64 /* 64 hasn't been used by system yet*/
#define AF_INET     PF_INET

/* socket_family or Protocol families */
#define PF_INET     2   /* IP protocol family.  */
#define PF_AQUANET AF_AQUANET

/* socket_type */
#define SOCK_AQUANET 61

/* socket size */
#define DATASIZE MAX_DATA_PAYLOAD_SIZE

/* socket address */
#define __SOCK_ADDR_SIZE__   16              /* sizeof(struct sockaddr)      */

struct aqua_addr {
    unsigned short int s_addr; /*	source address	*/
    unsigned short int d_addr; /*	destination address	*/
};

struct sockaddr_aquanet {
    unsigned short int sin_family; /* Address family               */
    struct aqua_addr sin_addr; /* Aqua-Net address             */
    /* Pad to size of `struct sockaddr'. */
    unsigned char __pad[__SOCK_ADDR_SIZE__ - sizeof (unsigned short int) - sizeof (struct aqua_addr) ];
};

/* Define the following as global variables
 * to make it easier to close them	*/
unsigned short int local_addr, remote_addr;
int socket_type;
int aqua_socket_fd;

int aqua_socket(int socket_family, int type, int protocol) {
    int errno;
    struct sockaddr_un aqua_name;
    /* Create the socket.  */
    aqua_socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
    /* Store the path name in the socket address.  */
    aqua_name.sun_family = AF_LOCAL;
    /* Decide the socket type */
    socket_type = type;

    if (socket_type == SOCK_AQUANET) {
        /* Socket of Aqua-Net protocol stack
         * working as a client	*/
        strcpy(aqua_name.sun_path, AQUA_APP);
        /* Connect the socket.  */
        if((errno = connect(aqua_socket_fd, (struct sockaddr *) & aqua_name, SUN_LEN(&aqua_name))) < 0) {
            logger(log_file_name, "[%10s]\tconnect failed: %s", __progname, strerror(errno));
            return (-1);
        }
        return aqua_socket_fd;
    } else {
        logger(log_file_name, "[%10s]\tsocket type not supported", __progname);
        return (-1);
    }
}

/* @len is the size of the application data in @buf, note that tailing '\0' should not be counted in @len	*/
int aqua_sendto(int sockfd, const void *buf, int len, int flags, const struct sockaddr *to, int tolen) {
    int send_num = 0;
    if (len > DATASIZE) {
        logger(log_file_name, "[%10s]\tSending packet is bigger than buffer", __progname);
        return -1;
    }
    /* Create an empty PDU_BUFF */
    struct pdu_buff pbuf;
    memset(&pbuf, 0, sizeof (pbuf));

    /*	Get the addresses  */
    struct sockaddr_aquanet *addr = (struct sockaddr_aquanet *) to;

    /* Fill the addresses into the PDU_BUFF */
    pbuf.hdr_net.src_addr = addr->sin_addr.s_addr;
    pbuf.hdr_net.dst_addr = addr->sin_addr.d_addr;

    /* Copy application data into PDU_BUFF */
    memcpy(pbuf.pkt_data, buf, len);
    pbuf.frame_len = len;

    /*	Send the packet  */
    write(sockfd, &pbuf, sizeof (pbuf));

    return send_num;
}

/* @len is the size of the @buf 
 * Return the size of payload 
 * -1 when fail and 0 when timeout */
int aqua_recvfrom(int sockfd, void *buf, int len, int flags, struct sockaddr *from, int *fromlen) {
    int recv_num = 0;
    int data_num = 0;
    int fdmax, error; /* maximum file descriptor number */
    fd_set read_fds; /* file descriptor list for select() */
    struct timeval timeout; /* Timeout for select */

    /* Create an empty PDU_BUFF */
    struct pdu_buff pbuf;
    char recv_buf[BUFSIZE];
    memset(&pbuf, 0, sizeof (pbuf));
    memset(recv_buf, 0, sizeof (recv_buf));

    /* Prepare to do select() */
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    fdmax = sockfd;
    timeout.tv_sec = AQUA_SOCK_TIMEOUT;
    timeout.tv_usec = 0;

    if ((error = select(fdmax + 1, &read_fds, NULL, NULL, &timeout)) < 0) {
        logger(log_file_name, "[%10s]\tSelect() failed: %s", __progname, strerror(error));
        return -1;
    } else if (error == 0) {
        //fprintf(stderr, "[aqua_recvfrom]\t\tSelect() timeout\n");
        fprintf(stderr, ".");
        fflush(stderr);
        return 0;
    }
    fprintf(stderr, "\n");
    /* Read from the socket */
    recv_num = read(sockfd, recv_buf, sizeof (recv_buf));
    if (recv_num < 0) {
        logger(log_file_name, "[%10s]\tfailed to read from socket: %s", __progname, strerror(error));
        return -1;
    }
    if (recv_num == 0) {
        logger(log_file_name, "[%10s]\tread nothing from the socket", __progname);
        return -1;
    }
    if (recv_num > sizeof (struct pdu_buff)) {
        logger(log_file_name, "[%10s]\treceived more data than buffer can hold", __progname);
        return -1;
    }
    memcpy(&pbuf, recv_buf, recv_num);

    /* Get the addresses  */
    /* Fill the Aqua-Net socket address */
    ((struct sockaddr_aquanet *) from)->sin_addr.s_addr = pbuf.hdr_net.src_addr;
    ((struct sockaddr_aquanet *) from)->sin_addr.d_addr = pbuf.hdr_net.dst_addr;

    /* Got a packet for a host, extract application data */
    memcpy(buf, &(pbuf.pkt_data), pbuf.frame_len);
    return pbuf.frame_len;
}

void aqua_close(int client_sockfd) {
    close(client_sockfd);
}

#endif
