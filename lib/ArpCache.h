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
#include "GenericUtility.h"
#include "ARPUtility.h"

void addEntry(ARPDetails arpCachce);
void updateEntry(ARPDetails arpCachce);
void purgeEntry(int sockFd);
int doesEntryExist(uint8_t sender_ip[4]) ;
int doesEntryExistForIpString(char ipAddress[INET_ADDRSTRLEN]);
void addorUpdateCacheEntry(arp_hdr arpHeader);
ARPDetails getARPCacheEntry(char ipAddress[INET_ADDRSTRLEN]);
void printARPCache();

#endif /* LIB_ARPCACHE_H_ */
