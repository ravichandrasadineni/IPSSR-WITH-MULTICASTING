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
	struct timeval tv;
	int maxfd=0;
	fd_set readSet;
	FD_ZERO (&readSet);
	maxfd = clientSocket + 1;
	FD_SET(clientSocket,&readSet);
	tv.tv_sec = ARP_TIME_OUT_SECS;
	tv.tv_usec = ARP_TIME_OUT_USECS;
	//msg_send(clientSocket,sendingPacket);
	if((select(maxfd,&readSet,NULL,NULL,&tv))<0) {
		perror("ARPAPI.c : Select in the client Failed :");
	}
	if(FD_ISSET(clientSocket,&readSet)) {
		//msg_recv(clientSocket,&recievingPacket,NULL);
		//printRecievedMessage(userchoice, recievingPacket.message);
		break;
	}


	unLinkSocket(clientSocket);
	return 0;
}
