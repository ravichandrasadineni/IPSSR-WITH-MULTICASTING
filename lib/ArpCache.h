/*
 * ArpCache.h
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_ARPCACHE_H_
#define LIB_ARPCACHE_H_
#include "unp.h"
#include "MemoryAllocator.h"
#include "Constants.h"
struct ARPCACHEENTRY{
	char HW_address[HADDR_LEN];
	char IP_address[INET_ADDRSTRLEN];
	int sll_ifindex;
	char sll_hatype;
	int udsSocket;
	struct ARPCACHEENTRY *next;
};
typedef struct ARPCACHEENTRY ARPCacheEntry;

void addEntry(ARPCacheEntry arpCachce);
void purgeEntry(int sockFd);
int doesEntryExist(char ipAddress[INET_ADDRSTRLEN]);
ARPCacheEntry getARPCacheEntry(char ipAddress[INET_ADDRSTRLEN]);

#endif /* LIB_ARPCACHE_H_ */
