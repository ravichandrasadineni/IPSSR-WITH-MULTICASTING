/*
 * ArpCache.c
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */
#include "ArpCache.h"


ARPCacheEntry *head=NULL, *tail=NULL;
int aRPCachecurrentSize;


copyARPDetails(ARPCacheEntry *arpCachce1, ARPCacheEntry arpCachce2) {
	memcpy(arpCachce1->HW_address,arpCachce2.HW_address,HADDR_LEN);
	strncpy(arpCachce1->IP_address,arpCachce2.IP_address,INET_ADDRSTRLEN);
	arpCachce1->sll_hatype = ETHERNET;
	arpCachce1->sll_ifindex = arpCachce2.sll_ifindex;
	arpCachce1->udsSocket = arpCachce2.udsSocket;
}


void addEntry(ARPCacheEntry arpCachce) {
	if (head == NULL) {
		head = (ARPCacheEntry*)(allocate_void(sizeof(ARPCacheEntry)));
		tail = head;
	}
	else {
		tail->next = (ARPCacheEntry*)(allocate_void(sizeof(ARPCacheEntry)));
		tail = tail->next;
	}
	copyARPDetails(tail ,arpCachce);
	tail->next=NULL;
	aRPCachecurrentSize++;

}
void purgeEntry(int uSockkFd) {
	int i;
	ARPCacheEntry *currentPosition = head;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if(currentPosition->udsSocket == uSockkFd) {
			currentPosition->udsSocket =ARP_NO_UDS_SOCKET;
			return;
		}
		currentPosition = currentPosition->next;
	}

}
int doesEntryExist(char ipAddress[INET_ADDRSTRLEN]) {
	ARPCacheEntry *currentPosition = head;
	int i;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if (isSameIP(currentPosition->IP_address,ipAddress)) {
			return TRUE;
		}
		currentPosition = currentPosition->next;
	}
	return FALSE;
}

ARPCacheEntry getARPCacheEntry(char ipAddress[INET_ADDRSTRLEN]) {
	ARPCacheEntry *currentPosition = head;
	ARPCacheEntry newEntry;
	int i;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if (isSameIP(currentPosition->IP_address,ipAddress)) {
			return *currentPosition;
		}
		currentPosition = currentPosition->next;
	}
	return newEntry;
}

