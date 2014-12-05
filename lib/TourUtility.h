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
#include "AddressUtility.h"
#include "unp.h"
#include "TourSocketUtility.h"
#include "ICMPUtility.h"





void forwardTourIPPacket(int rt, tourInfo ti);
void addsourcetoVisited(tourInfo ti);
tourInfo breakTourPayload(char *Message);
char* buildTourPayload(tourInfo ti);
void buildTourIPMessage(char Payload[TOUR_PACKET_LENGTH], char destAddr[INET_ADDRSTRLEN], char* Message);
tourInfo contstructIntTourPacket(int argc, char *argv[]);
int isLastNode(tourInfo tI);


#endif /* LIB_TOURUTILITY_H_ */
