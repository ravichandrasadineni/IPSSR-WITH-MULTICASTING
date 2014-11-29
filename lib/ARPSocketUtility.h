/*
 * ARPSocketUtility.h
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_ARPSOCKETUTILITY_H_
#define LIB_ARPSOCKETUTILITY_H_
#include "Constants.h"
#include "unp.h"
#include "MemoryAllocator.h"
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include "Asgn3_code/hw_addrs.h"
#include "GenericUtility.h"


struct interfacefInfo {
	char    if_haddr[HADDR_LEN];	/* hardware address */
	int     if_index;
	char    ip_address[INET_ADDRSTRLEN];
};

typedef struct interfacefInfo  ifInfo;
void initializeList();
int isMyIP(char ip_address[INET_ADDRSTRLEN]);
void populateMacForIP(char ip_address[INET_ADDRSTRLEN],char macAddress[HADDR_LEN]);
int createAndBindSocketsPF_PACKETSOCKET();
#endif /* LIB_ARPSOCKETUTILITY_H_ */
