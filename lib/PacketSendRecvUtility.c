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
	return frame;
}

void send_packet(int sendfd, char* sendBuff){
	int s;
	if((s = send(sendfd, (void*)sendBuff, sizeof(sendBuff), 0)) < sizeof(sendBuff)){
		printf("Could not send total packet only part of the packet of size %d is sent\n",s);
		exit(0);
	}
}
