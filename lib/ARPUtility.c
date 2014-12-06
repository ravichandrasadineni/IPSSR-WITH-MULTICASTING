/*
 * ARPUtility.c
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#include "ARPUtility.h"


int isDestinedToMe(arp_hdr arpHeader) {
	char localIpAddress[INET_ADDRSTRLEN];
	populateLocalIpAddress(localIpAddress);

	if (isSameIP(localIpAddress,getIpAddStr_ARPIPFMT(arpHeader.target_ip))) {
		return TRUE;
	}
	return FALSE;
}

int isMyPacket(arp_hdr arpHeader) {

	if (arpHeader.advNumber ==ARP_ADV_NUM ) {
		return TRUE;
	}
	return FALSE;
}


int isQuery(arp_hdr arpHeader) {
	if(arpHeader.opcode == ARPOP_REQUEST) {
		return TRUE;
	}
	return FALSE;
}

int isReply(arp_hdr arpHeader) {
	if(arpHeader.opcode == ARPOP_REPLY) {
		return TRUE;
	}
	return FALSE;
}



char* buildReply(arp_hdr arpHeader) {
	struct ethhdr  *eth;
	int status;
	unsigned short type=htons(ETH_TYPE);
	char* frame = (char*) allocate_strmem(FRAME_LENGTH);
	eth = (struct ethhdr*) frame;
	eth->h_proto=type;
	populateLocalMacAddress(eth->h_source);
	memcpy(eth->h_dest, arpHeader.sender_mac,HADDR_LEN);
	arp_hdr*  newArpHeader = (arp_hdr*)(eth+1);
	memcpy(newArpHeader->target_mac, arpHeader.sender_mac,HADDR_LEN);
	strncpy(newArpHeader->target_ip,arpHeader.sender_ip,INETP_LEN );
	populateLocalMacAddress(newArpHeader->sender_mac);
	strncpy(newArpHeader->sender_ip,arpHeader.target_ip,INETP_LEN );
	newArpHeader->opcode = ARPOP_REPLY;
	newArpHeader->advNumber = arpHeader.advNumber;
	newArpHeader->hlen = arpHeader.hlen;
	newArpHeader->htype = arpHeader.htype;
	newArpHeader->plen = arpHeader.plen;
	newArpHeader->ptype = arpHeader.ptype;
	return frame;
}


char *marshallMessage(char ipAddress[INET_ADDRSTRLEN], const char macAddress[HADDR_LEN]) {
	int messageLength = INET_ADDRSTRLEN + HADDR_LEN;
	char*  marshelledMessage = (char*)allocate_strmem(messageLength);
	memcpy(marshelledMessage,macAddress,HADDR_LEN);
	strncpy(marshelledMessage+HADDR_LEN,ipAddress,INET_ADDRSTRLEN);
	return marshelledMessage;
}

void  unMarshallMessage(char *marshelledMessage, char ipAddress[INET_ADDRSTRLEN], char macAddress[HADDR_LEN]) {
	memcpy(macAddress,marshelledMessage,HADDR_LEN);
	strncpy(ipAddress,marshelledMessage+HADDR_LEN,INET_ADDRSTRLEN);
}

char* buildRequest(char* sourceMac,char* sourceIp, char* destinationIp, ARPDetails cacheEntry) {
	struct ethhdr  *eth;
	int status;
	arp_hdr* arpHeader;
	unsigned short type=htons(ETH_TYPE);
	char* frame = (char*) allocate_strmem(FRAME_LENGTH);
	eth = (struct ethhdr*) frame;

	memcpy(eth->h_dest,BRODCAST_MAC,HADDR_LEN);
	memcpy(eth->h_source,sourceMac,HADDR_LEN);
	eth->h_proto = type;
	arpHeader = (arp_hdr*)(eth+1);
	arpHeader->hlen = HADDR_LEN;
	arpHeader->htype = ETHERNET;
	arpHeader->opcode = ARPOP_REQUEST;
	arpHeader->plen = IPADDR_LEN;
	memcpy (&arpHeader->sender_mac, sourceMac, HADDR_LEN);
	memcpy (&arpHeader->target_mac, BRODCAST_MAC, HADDR_LEN);
	struct in_addr sinAddr;
	if ((status = inet_pton (AF_INET, sourceIp, &sinAddr)) != 1) {
		fprintf (stderr, "inet_pton() failed for source IP address.\nError message: %s", strerror (status));
		exit (EXIT_FAILURE);
	}
	setARPIPBlock(sinAddr,arpHeader->sender_ip);
	if ((status = inet_pton (AF_INET, destinationIp, &sinAddr)) != 1) {
		fprintf (stderr, "inet_pton() failed for destination IP address.\nError message: %s", strerror (status));
		exit (EXIT_FAILURE);
	}
	setARPIPBlock(sinAddr,arpHeader->target_ip);
	arpHeader->advNumber = ARP_ADV_NUM;
	return frame;
}


void printFrame(char *Frame) {
	struct ethhdr  *eth = (struct ethhdr  *)Frame;
	printf("Ethernet Source Mac : ");
	printMacAddress(eth->h_source);
	printf("\t");
	printf("Ethernet Destination Mac : ");
	printMacAddress(eth->h_dest);
	printf("\t");
	printf("ethernet type %d \n", ntohs(eth->h_proto));
	arp_hdr* arpHeader = (arp_hdr*)(eth+1);
	printf("ARP Source Mac :");
	printMacAddress(arpHeader->sender_mac);
	printf("\t");
	printf("ARP Dest Mac :");
	printMacAddress(arpHeader->target_mac);
	printf("\n");
	struct in_addr sinAddr1;
	struct in_addr sinAddr2;
	sinAddr1.s_addr = getSaddr(arpHeader->sender_ip);
	sinAddr2.s_addr = getSaddr(arpHeader->target_ip);
	//printf("ARP Destination ip : %s \n",inet_ntoa(sinAddr2));
	//printf("Advertisement Number : %d \t",arpHeader->advNumber);
	//printf("Hardware Length : %d \t",arpHeader->hlen);
	//printf("Hardware Type : %d \n",arpHeader->htype);
	//printf("Protocol Length : %d \t",arpHeader->plen);
	//printf("Protocol Type : %d \t",arpHeader->ptype);
	//printf("Operation Code : %d \n",arpHeader->opcode);
	if(arpHeader->opcode == 1) {
		printf("%s requested %s  for MacAddress \n", getDomainNameFromIpAddress(sinAddr1), getDomainNameFromIpAddress(sinAddr2));
	}else {
		printf("%s replied %s  with MacAddress \n", getDomainNameFromIpAddress(sinAddr1), getDomainNameFromIpAddress(sinAddr2));
	}



}



arp_hdr breakFrame(char *frame) {
	ARPDetails  newEntry;
	struct ethhdr  *eth;
	arp_hdr* arpHeader;
	eth = (struct ethhdr*) frame;
	arpHeader = (arp_hdr*)(eth+1);
	return *arpHeader;
}


