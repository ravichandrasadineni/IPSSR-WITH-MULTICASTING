/*
 * ARPUtility.h
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_ARPUTILITY_H_
#define LIB_ARPUTILITY_H_
#include "unp.h"
#include "Constants.h"
#include "GenericUtility.h"
#include "MemoryAllocator.h"

#include "unp.h"
#include "ARPSocketUtility.h"

struct ARPCACHEENTRY{
	char HW_address[HADDR_LEN];
	char IP_address[INET_ADDRSTRLEN];
	int sll_ifindex;
	char sll_hatype;
	int udsSocket;
	struct ARPCACHEENTRY *next;
};

typedef struct _arp_hdr arp_hdr;
struct _arp_hdr {
	uint16_t htype;
	uint16_t ptype;
	uint8_t hlen;
	uint8_t plen;
	uint16_t opcode;
	uint16_t advNumber;
	uint8_t sender_mac[HADDR_LEN];
	uint8_t sender_ip[4];
	uint8_t target_mac[HADDR_LEN];
	uint8_t target_ip[4];
};
typedef struct hwaddr hwaddr;

struct hwaddr {
		     int             sll_ifindex;	 /* Interface number */
		     unsigned short  sll_hatype;	 /* Hardware type */
		     unsigned char   sll_halen;		 /* Length of address */
		     unsigned char   sll_addr[8];	 /* Physical layer address */
};





typedef struct ARPCACHEENTRY ARPDetails;

arp_hdr getArpHeader(char* frame);

void printFrame(char *Frame) ;

char* marshallMessage(char ipAddress[INET_ADDRSTRLEN], const char macAddress[HADDR_LEN]);

void  unMarshallMessage(char *marshelledMessage, char ipAddress[INET_ADDRSTRLEN], char macAddress[HADDR_LEN]);

char* buildRequest(char* sourceMac,char* sourceIp, char* destinationIp, ARPDetails cacheEntry);
int isReply(arp_hdr arpHeader);
int isMyPacket(arp_hdr arpHeader);
char* buildReply(arp_hdr arpHeader);
int isDestinedToMe(arp_hdr arpHeader);
int isQuery(arp_hdr arpHeader);
arp_hdr breakFrame(char *Message);



#endif /* LIB_ARPUTILITY_H_ */
