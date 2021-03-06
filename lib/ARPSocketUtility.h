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
#include "GenericUtility.h"
#include <net/ethernet.h>
#include <netpacket/packet.h>

struct interfacefInfo {
	char    if_haddr[HADDR_LEN];	/* hardware address */
	int     if_index;
	char    ip_address[INET_ADDRSTRLEN];
};

typedef struct interfacefInfo  ifInfo;
void initializeList();
int isMyIP(char ip_address[INET_ADDRSTRLEN]);
void populateMacForIP(char ip_address[INET_ADDRSTRLEN],char macAddress[HADDR_LEN]);
void populateLocalMacAddress(char macAddress[HADDR_LEN]);
void populateLocalIpAddress(char ipAddress[INET_ADDRSTRLEN]);
void addtoOpenSocketList(int sockFd);
void deleteFromOpenSocketList(int sockFd);
void setReadSetForOpenSockets(fd_set* readSet, int* maxfd);
int getSetSocket(fd_set* readSet);
int createAndBindSocketsPF_PACKETSOCKET();
#endif /* LIB_ARPSOCKETUTILITY_H_ */
