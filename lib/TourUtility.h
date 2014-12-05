/*
 * TourUtility.h
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */

#ifndef LIB_TOURUTILITY_H_
#define LIB_TOURUTILITY_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PacketSendRecvUtility.h"
#include "Constants.h"
#include "MemoryAllocator.h"
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netpacket/packet.h>
#include "AddressUtility.h"
#include "unp.h"

struct tourInfo {
	int count;
	int currentPosition;
	char* tourAddresses[INET_ADDRSTRLEN];
	char multicastAddress[INET_ADDRSTRLEN];
	int multicastPort;
};
typedef struct tourInfo tourInfo;

struct Visited{
	char sourceAddress[INET_ADDRSTRLEN];
	struct Visited *next;
};
typedef struct Visited Visited;

void forwardTourIPPacket(int rt, tourInfo ti);
int isVisited(tourInfo ti);
void addsourcetoVisited(tourInfo ti);
tourInfo breakTourPayload(char *Message);
void buildTourPayload(tourInfo ti, char *tourPayload);
void buildTourIPMessage(char Payload[TOUR_PACKET_LENGTH], char destAddr[INET_ADDRSTRLEN], char* Message);
tourInfo contstructIntTourPacket(char *argv[]);
int isLastNode(tourInfo tI);


#endif /* LIB_TOURUTILITY_H_ */
