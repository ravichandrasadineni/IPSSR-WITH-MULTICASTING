/*
 * ICMPUtility.h
 *
 *  Created on: Dec 3, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_ICMPUTILITY_H_
#define LIB_ICMPUTILITY_H_
#include "Constants.h"
#include "unp.h"
#include <linux/if_ether.h>
#include "ARPAPI.h"
#include "PacketSendRecvUtility.h"
#include "TourSocketUtility.h"
#include	<netinet/in_systm.h>
#include	<netinet/ip.h>
#include	<netinet/ip_icmp.h>


struct tourInfo {
	int count;
	int currentPosition;
	char** tourAddresses;
	char multicastAddress[INET_ADDRSTRLEN];
	int multicastPort;
};

typedef struct tourInfo tourInfo;

struct Visited{
	char ipAddress[INET_ADDRSTRLEN];
	struct Visited *next;
};
void addNeighbours(tourInfo ti);
int isAlreadyNeighbour(tourInfo ti);
void sendIcmpMessages();
void recvandPrintIcmpMessage(int pg);
void sendIcmpMessages();



typedef struct Visited neighbours;


#endif /* LIB_ICMPUTILITY_H_ */
