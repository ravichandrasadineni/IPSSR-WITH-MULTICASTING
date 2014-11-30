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
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netpacket/packet.h>

struct isVisited{
	char ipAddress[INET_ADDRSTRLEN];
	int Visited;
	struct isVisited *next;
};

#endif /* LIB_TOURUTILITY_H_ */
