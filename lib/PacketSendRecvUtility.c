/*
 * PacketSendRecvUtility.c
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */
#include "PacketSendRecvUtility.h"

char* recv_packet(int recvfd){
	char * frame = allocate_strmem(MTU);
		int frameLength = MTU;
		if(recv(recvfd, frame,frameLength,0)<0) {
			perror("PacketSendRecvUtility.c: Packet receiving error");
		}
		printf("Packet received sucesfully \n");
	return frame;
}

void send_packet(int sendfd, char* sendBuff, char ipAddress[INET_ADDRSTRLEN]){
	int s;
	int status;
	struct sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port =0;
	if ((status = inet_pton (AF_INET, ipAddress, &(sin.sin_addr))) != 1) {
			perror("TourUtility.C destination address conversion failed");
			exit (EXIT_FAILURE);
	}
	if (sendto (sendfd, sendBuff, MTU, 0, (SA*)&sin, sizeof (struct sockaddr)) < 0)  {
	    perror ("sendto() failed ");
	    exit (EXIT_FAILURE);
	  }
	printf("Packet sent sucesfully \n");
}
