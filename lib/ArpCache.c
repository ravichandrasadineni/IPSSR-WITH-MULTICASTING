/*
 * ArpCache.c
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */
#include "ArpCache.h"


ARPDetails *head=NULL, *tail=NULL;
int aRPCachecurrentSize;


copyARPDetails(ARPDetails *arpCachce1, ARPDetails arpCachce2) {
	memcpy(arpCachce1->HW_address,arpCachce2.HW_address,HADDR_LEN);
	strncpy(arpCachce1->IP_address,arpCachce2.IP_address,INET_ADDRSTRLEN);
	arpCachce1->sll_hatype = ETHERNET;
	arpCachce1->sll_ifindex = arpCachce2.sll_ifindex;
	arpCachce1->udsSocket = arpCachce2.udsSocket;
}

void updateEntry(ARPDetails arpCachce) {
	int i;
	ARPDetails *currentPosition = head;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if (isSameIP(arpCachce.IP_address,currentPosition->IP_address)) {
			memcpy(currentPosition->HW_address, arpCachce.HW_address,HADDR_LEN);
		}
		currentPosition = currentPosition->next;
	}

}

void printARPCache() {
	int i;
	if(head == NULL) {
		printf("ARP CACHE IS EMPTY \n");
	}
	ARPDetails *currentposition = head;
	for(i=0; i<aRPCachecurrentSize;i++) {
		printf ("Target HW_address : ");
		printMacAddress(currentposition->HW_address);
		printf("\t");
		printf("Target IP Address : %s \n", currentposition->IP_address);
		printf(" UDS SOCKET : %d \t", currentposition->udsSocket);
		printf(" HARDWARE TYPE : %d \t", currentposition->sll_hatype);
		printf(" OUTGOING INTERFACE INDEX : %d \n", currentposition->sll_ifindex);
		currentposition= currentposition->next;
	}


}



void addEntry(ARPDetails arpCachce) {
	if (head == NULL) {
		head = (ARPDetails*)(allocate_void(sizeof(ARPDetails)));
		tail = head;
	}
	else {
		tail->next = (ARPDetails*)(allocate_void(sizeof(ARPDetails)));
		tail = tail->next;
	}
	copyARPDetails(tail ,arpCachce);
	tail->next=NULL;
	aRPCachecurrentSize++;

}




void addorUpdateCacheEntry(arp_hdr arpHeader) {
	ARPDetails newEntry;
	memcpy(newEntry.HW_address, arpHeader.sender_mac, HADDR_LEN);
	char senderIpAddress[INET_ADDRSTRLEN];
	struct in_addr sin_addr;
	sin_addr.s_addr = getSaddr(arpHeader.sender_ip);
	strncpy(newEntry.IP_address,inet_ntoa(sin_addr), INET_ADDRSTRLEN);
	newEntry.sll_hatype = ETHERNET;
	newEntry.udsSocket = ARP_NO_UDS_SOCKET;
	newEntry.sll_ifindex = getEth0Index();
	if(doesEntryExist(arpHeader.sender_ip)) {
		updateEntry(newEntry);
	}
	else {
		addEntry(newEntry);
	}
}



void purgeEntry(int uSockkFd) {
	int i;
	ARPDetails *currentPosition = head;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if(currentPosition->udsSocket == uSockkFd) {
			currentPosition->udsSocket =ARP_NO_UDS_SOCKET;
			return;
		}
		currentPosition = currentPosition->next;
	}

}

int doesEntryExist(uint8_t sender_ip[4]) {
	struct in_addr sAddr;
	sAddr.s_addr = getSaddr(sender_ip);
	char* ipAddress;
	ipAddress = inet_ntoa(sAddr);
	return doesEntryExistForIpString(ipAddress );

}
int doesEntryExistForIpString(char ipAddress[INET_ADDRSTRLEN]) {

	ARPDetails *currentPosition = head;
	int i;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if (isSameIP(currentPosition->IP_address,ipAddress)) {
			return TRUE;
		}
		currentPosition = currentPosition->next;
	}
	return FALSE;
}

ARPDetails getARPCacheEntry(char ipAddress[INET_ADDRSTRLEN]) {
	ARPDetails *currentPosition = head;
	ARPDetails newEntry;
	int i;
	for(i=0;i<aRPCachecurrentSize;i++) {
		if (isSameIP(currentPosition->IP_address,ipAddress)) {
			return *currentPosition;
		}
		currentPosition = currentPosition->next;
	}
	return newEntry;
}

