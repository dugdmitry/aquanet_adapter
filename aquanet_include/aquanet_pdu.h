/**************************************************************************
* Developed by Zheng (James) Peng                                         *
* This is a research project from University of Connecticut               *
* Copyright (C) 2010, all rights reserved                                 *
**************************************************************************/

#ifndef PDU_BUFF
#define PDU_BUFF

#include "aquanet_netif.h"


/* Defining PKT_STATES	*/
#define	PKT_STATE_PHY		2
#define	PKT_STATE_MAC		3
#define	PKT_STATE_NET		4
#define	PKT_STATE_TRA		5
#define	PKT_STATE_APP		6
#define	PKT_STATE_SKT		7

#define MAX_HEADER_SIZE_MAC 32	/* same as 802.11 */
struct type_mac_hdr {
	unsigned short int hdr_len; /* Actual length of the whole header */
	unsigned short int mac_type;
	unsigned short int src_addr;
	unsigned short int dst_addr;
	/* Pad to size of type_mac_hdr  */
	char mac_data[MAX_HEADER_SIZE_MAC - 4 * sizeof(unsigned short int)];
};

#define MAX_HEADER_SIZE_NET 100	/* increased for VBF	*/
struct type_net_hdr {
	unsigned short int hdr_len; /* Actual length of the whole header */
	unsigned short int net_type;
	unsigned short int src_addr;
	unsigned short int dst_addr;
	unsigned short int next_hop;
	/* Pad to size of type_net_hdr  */
	char net_data[MAX_HEADER_SIZE_NET - 5 * sizeof(unsigned short int)];
};

/* Transport layer header */
#define MAX_HEADER_SIZE_TRA 20	/* same as TCP	*/
struct type_tra_hdr {
	unsigned short int hdr_len; /* Actual length of the whole header */
	unsigned short int tra_type;
	/* Pad to size of type_tra_hdr  */
	char tra_data[MAX_HEADER_SIZE_TRA - 2 * sizeof(unsigned short int)];
};

#define MAX_DATA_PAYLOAD_SIZE (500)

struct pdu_buff {
	unsigned short int frame_len; /* Payload size */
	struct type_mac_hdr hdr_mac;
	struct type_net_hdr hdr_net;
	struct type_tra_hdr hdr_tra;
	char pkt_data[MAX_DATA_PAYLOAD_SIZE];
	
	/* The following will not be sent over the network
		 Only useful for protocol stack handling	*/
	int pkt_type;
	int pkt_state;
};

#endif
