/*
 * ARPAPI.c
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */
#include "ARPAPI.h"




int areq (struct sockaddr *IPaddr, socklen_t sockaddrlen, struct hwaddr *HWaddr) {

	int clientSocket = getARPclientBindedsocket();
	connectToARP(clientSocket);
	struct sockaddr_in* ipAddress = (struct sockaddr_in *)IPaddr;
	char* ipAddressString = inet_ntoa(ipAddress->sin_addr);
	printf("MAC ADDRESS Requested for destination : %s \n  ",ipAddressString);
	char* message = marshallMessage(ipAddressString,BRODCAST_MAC);
	struct timeval tv;
	int maxfd=0;
	fd_set readSet;
	FD_ZERO (&readSet);
	maxfd = clientSocket + 1;
	FD_SET(clientSocket,&readSet);
	tv.tv_sec = ARP_TIME_OUT_SECS;
	tv.tv_usec = ARP_TIME_OUT_USECS;
	sendUDSMessage(clientSocket,message);
	if((select(maxfd,&readSet,NULL,NULL,&tv))<0) {
		perror("ARPAPI.c : Select in the client Failed :");
	}
	char recvMessage[UDS_PACKET_MAX_LEN];
	if(FD_ISSET(clientSocket,&readSet)) {
		recvUDSMessage(clientSocket,recvMessage);
		unMarshallMessage(recvMessage,ipAddressString, HWaddr->sll_addr );
		HWaddr->sll_halen = HADDR_LEN;
		HWaddr->sll_ifindex = getEth0Index();
		HWaddr->sll_hatype = ETHERNET;
		printf("MAC ADDRESS for destination : %s  is   ",ipAddressString);
		printMacAddress(HWaddr->sll_addr );
		printf("\n");
		return 1;
	} else {
		printf("ARPAPI.c : MAC ADDRESS retrieval failed");
		return -1;
	}
	unLinkSocket(clientSocket);
	return 1;
}
