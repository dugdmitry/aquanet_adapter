/**************************************************************************
* Developed by Zheng (James) Peng                                         *
* This is a research project from University of Connecticut               *
* Copyright (C) 2010, all rights reserved                                 *
**************************************************************************/

#ifndef AQUA_TIME
#define AQUA_TIME

#include <time.h>
#include <sys/time.h>

#define TIMESTR_BUFSIZE 100 
 
/* Return the current time to the array pointed by @time_string
 * The size of the array is specified in @max_size
 * Time is accurate in seconds 
 */
void get_timestring_sec(char* time_string, int max_size) {
	time_t now;
	struct tm *tp;
	char local_string[TIMESTR_BUFSIZE];
	now = time((time_t *)NULL);
	tp = localtime(&now);
	memset(local_string, 0, sizeof(local_string));
	//strftime(local_string, sizeof(local_string), "%Y %m %d %H:%M:%S", tp);
	strftime(local_string, TIMESTR_BUFSIZE - 1, "%d%H%M%S", tp);
	if(strlen(local_string) > max_size){
		printf("\nget_timestring_sec: output buffer too small, need %d bytes in total\n", (int) strlen(local_string));
		strcpy(time_string, "9999");
	}
	else
		strcpy(time_string, local_string);
}

void get_fulltimestring_sec(char* time_string, int max_size) {
        time_t now;
        struct tm *tp;
        char local_string[TIMESTR_BUFSIZE];
        now = time((time_t *)NULL);
        tp = localtime(&now);
        memset(local_string, 0, sizeof(local_string));
        strftime(local_string, sizeof(local_string), "%Y %m %d %H:%M:%S", tp);
        if(strlen(local_string) > max_size){
                printf("\nget_timestring_sec: output buffer too small, need %d bytes in total\n", (int) strlen(local_string));
                strcpy(time_string, "9999");
        }
        else
                strcpy(time_string, local_string);
}


#endif
