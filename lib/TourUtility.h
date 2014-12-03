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




struct isVisited{
	char ipAddress[INET_ADDRSTRLEN];
	int Visited;
	struct isVisited *next;
};

struct ipPacket{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int ip_hl:4;		/* header length */
	unsigned int ip_v:4;		/* version */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
	unsigned int ip_v:4;		/* version */
	unsigned int ip_hl:4;		/* header length */
#endif
	u_int8_t ip_tos;			/* type of service */
	u_short ip_len;			/* total length */
	u_short ip_id;			/* identification */
	u_short ip_off;			/* fragment offset field */
#define	IP_RF 0x8000			/* reserved fragment flag */
#define	IP_DF 0x4000			/* dont fragment flag */
#define	IP_MF 0x2000			/* more fragments flag */
#define	IP_OFFMASK 0x1fff		/* mask for fragmenting bits */
	u_int8_t ip_ttl;			/* time to live */
	u_int8_t ip_p;			/* protocol */
	u_short ip_sum;			/* checksum */
	struct in_addr ip_src, ip_dst;	/* source and dest address */
	char Payload[1516];
};

#endif /* LIB_TOURUTILITY_H_ */
