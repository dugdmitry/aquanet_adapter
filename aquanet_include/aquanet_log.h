/**************************************************************************
 * Developed by Zheng (James) Peng                                         *
 * This is a research project from University of Connecticut               *
 * Copyright (C) 2010, all rights reserved                                 *
 **************************************************************************/

#ifndef AQUA_LOG
#define AQUA_LOG

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "aquanet_time.h"

#define BUF_SIZE 1024
#define LOG_BUFSIZE BUF_SIZE
#define FILENAME_SIZE 100

const float range = 1000;
//extern const char *__progname;

FILE* log_fp;

#define LOG_DIR "logs/"

void _uwsnputs(const char *fileName, const char *message) {
	char fname[200];
        strcpy(fname, LOG_DIR);
	strcat(fname, fileName);
        
    int fd = open(fname, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, message, strlen(message));
    close(fd);
}

/* Write log messages into files 
 * @filename is the name of the log file 
 * @fmt is the similar to those used in printf() 
 * NOTE that the current implmentation ONLY supports
 * string (%s), integer (%d) and character (%c) 
 * any other identifiers will not be supported, e.g. %f, %hu */

char __nodeId[100];
char __macNetId[100];

void readId(const char *fileName, char *id) {
    FILE* mac_cfg = fopen(fileName, "r");
    if (!mac_cfg) {
        id[0] = 0;
        perror(fileName);
        raise (SIGTERM);
        return;
    }
    
    while (fgets(id, 100, mac_cfg)) {
        if (*id == '#') continue; /* Use # to comment */
	int i = strlen(id) - 1;
        while (id[i] == '\r' || id[i] == '\n' || id[i] == ' ') {
		i --;
	}
	id[i + 1] = 0;
        break;
    }
    fclose(mac_cfg);
    return;
}

void delspace (char *str) {
	int i, j = 0;

	for (i = 0; str[i]; i ++) {
		if (str[i] != ' ') str[j++] = str[i];
	}
	str [j] = 0;
}

int logger(const char* filename, const char* fmt, ...) {
    static char *nodeId = NULL, *macNetId = NULL;
    if (nodeId == NULL) {
	readId("/etc/hostname", __nodeId);
	readId("config_add.cfg", __macNetId);
	delspace(__macNetId);
        nodeId = __nodeId;
	macNetId = __macNetId;
    }
    va_list ap;

    /* Prepare for file handling */
    char log_buf[LOG_BUFSIZE];
    char time_string[TIMESTR_BUFSIZE];

    /* Get time string */
    get_timestring_sec(time_string, sizeof (time_string));
    int n = sprintf(log_buf, "%s:%s-%s>", nodeId, macNetId, time_string);

    va_start(ap, fmt);
    int m = vsprintf(log_buf + n, fmt, ap);
    va_end(ap);

    log_buf[m + n] = '\n';
    log_buf[m + n + 1] = '\0';
    fputs(log_buf, stdout);

    get_fulltimestring_sec(time_string, sizeof (time_string));
    n = sprintf(log_buf, "%s:%s-%s: ", nodeId, macNetId, time_string);

    va_start(ap, fmt);
    m = vsprintf(log_buf + n, fmt, ap);
    va_end(ap);

    log_buf[m + n] = '\n';
    log_buf[m + n + 1] = '\0';
    /* Open up log file */
    _uwsnputs(filename, log_buf);

    return 0;
}

/* Get the command name of the current program, it 
 * removes all leading '/' and folder names
 * @name_string is the typically argv[0], 
 * @buf is a user provided buffer of @buf_len bytes
 * to store the name
 * return 0 when success, otherwise -1 */
/*int get_cmd_name(const char *name_string, char *buf, int buf_len) {
    char local_buf[BUF_SIZE];
    char cmd_name[256];
    char *token;

    memset(local_buf, 0, sizeof (local_buf));
    memset(cmd_name, 0, sizeof (cmd_name));
    strcpy(local_buf, name_string);

    token = strtok(local_buf, "/");
    strcpy(cmd_name, token);
    while (1) {
        if (!(token = strtok(NULL, "/")))
            break;
        memset(cmd_name, 0, sizeof (cmd_name));
        strcpy(cmd_name, token);
    }
    if (strlen(cmd_name) > buf_len) {
        printf("get_cmd_name: buffer to small for the name string\n");
        return -1;
    }
    strcpy(buf, cmd_name);
    return 0;
}*/

void logPosition(const char *logName, double latitude, double longitude, double depth) {
    char str[128];
    sprintf(str,
            "NAM n -t * -s 999 -x %f -y %f -Z %f -z 10 -v box -c black\n",
            latitude, longitude, depth);
    _uwsnputs(logName, str);
}

char* logEnqueue(const char *logName, int src_id, int dest_id) {
    struct timeval t;
    char str[128];
    gettimeofday(&t, NULL);
    sprintf(str,
            "NAM + -t %d.%6d -s %d -d %d -p NULL -e -1 -c NULL -a -1 -i -1 -k NULL\n",
            (int) t.tv_sec, (int) t.tv_usec, src_id, dest_id);
    _uwsnputs(logName, str);
}

char* logDequeue(const char *logName, int src_id, int dest_id) {
    struct timeval t;
    char str[128];
    gettimeofday(&t, NULL);
    sprintf(str,
            "NAM - -t %d.%6d -s %d -d %d -p NULL -e -1 -c NULL -a -1 -i -1 -k NULL\n",
            (int) t.tv_sec, (int) t.tv_usec, src_id, dest_id);
    _uwsnputs(logName, str);
}

char* logDrop(const char *logName, int src_id, int dest_id) {
    struct timeval t;
    char str[128];
    gettimeofday(&t, NULL);
    sprintf(str,
            "NAM d -t %d.%6d -s %d -d %d -p NULL -e -1 -c NULL -a -1 -i -1 -k NULL\n",
            (int) t.tv_sec, (int) t.tv_usec, src_id, dest_id);
    _uwsnputs(logName, str);
}

char* logHop(const char *logName, int src_id, int dest_id, int extent) {
    struct timeval t;
    char str[128];
    gettimeofday(&t, NULL);
    sprintf(str,
            "NAM h -t %d.%6d -s %d -d %d -p NULL -e -1 -c NULL -a -1 -i -1 -k NULL -R %f\n",
            (int) t.tv_sec, (int) t.tv_usec, src_id, dest_id, range);
    _uwsnputs(logName, str);
}

char* logReceive(const char *logName, int src_id, int dest_id, int extent) {
    struct timeval t;
    char str[128];
    gettimeofday(&t, NULL);
    sprintf(str,
            "NAM r -t %d.%6d -s %d -d %d -p NULL -e %d -c NULL -a -1 -i -1 -k NULL "
            "-R %f\n",
            (int) t.tv_sec, (int) t.tv_usec, src_id, dest_id, extent, range);
    _uwsnputs(logName, str);
}

#endif
