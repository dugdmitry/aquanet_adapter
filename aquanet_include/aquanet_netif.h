/**************************************************************************
* Developed by Zheng (James) Peng                                         *
* This is a research project from University of Connecticut               *
* Copyright (C) 2010, all rights reserved                                 *
**************************************************************************/

#ifndef IF_AQUANET
#define IF_AQUANET


/* Packet types */ 
 
 #define PACKET_HOST		0 /* To us */ 
 #define PACKET_BROADCAST	1 /* To all */ 
 #define PACKET_MULTICAST	2 /* To group */ 
 #define PACKET_OTHERHOST	3 /* To someone else */ 
 #define PACKET_OUTGOING	4 /* Outgoing of any type */ 
 #define PACKET_INCOMING	7 /* Incoming of any type */
 /* These ones are invisible by user level */ 
 #define PACKET_LOOPBACK	5 /* MC/BRD frame looped back */ 
 #define PACKET_FASTROUTE	6 /* Fastrouted frame */

 /*      These are the defined Ethernet Protocol ID's.
	*       */

 #define AQUA_P_UWALOHA	0x0001		/* Underwater ALOHA				*/
 #define AQUA_P_SROUTE	0x0002		/* Static Routing				*/
 #define AQUA_P_SYNC	0x0003		/* Synchronization Protocol		*/
 #define AQUA_P_SR		0x0801		/* Static Routing Protocol		*/
 #define AQUA_P_LOOP	0x0060      /* Ethernet Loopback packet     */
 #define AQUA_P_IP		0x0800      /* Internet Protocol packet     */
 #define AQUA_P_ARP		0x0806      /* Address Resolution packet    */
 #define AQUA_P_IPX		0x8137      /* IPX over DIX                 */
 #define AQUA_P_IPV6	0x86DD      /* IPv6 over bluebook           */

#endif
