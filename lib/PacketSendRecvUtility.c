/*
 * PacketSendRecvUtility.c
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */
#include "PacketSendRecvUtility.h"

void recv_packet(int recvfd, char* readBuff, char *sourceAddr){
	int size = MTU;
	char read_buff[MTU];
	readBuff = read_buff;
	struct sockaddr source;
	socklen_t len;
	printf("Before read : recvfd is %d\n",recvfd);
	if (recvfrom(recvfd, (void *)readBuff, MTU, 0, &source, &len) < 0){
		perror("Read Failed: ");
		exit(0);
	}
	struct ipPacket *Message = (struct ipPacket *)readBuff;
	if(IP_IDENTIFICATION == ntohs(Message->ip_id)){
		printf("The packet is destined to me \n");
	}
	printf("Packet successfully received with size %ld\n",sizeof(readBuff));
}

void send_packet(int sendfd, char* sendBuff, char destination[INET_ADDRSTRLEN]){
	int s;
	printf("sendBuff is %s\n",sendBuff);
	printf("Before send : sendfd is %d\tdestination is %s\n",sendfd,destination);
	struct sockaddr_in dest;
	dest.sin_addr.s_addr = inet_addr(destination);
	dest.sin_family = AF_INET;
	dest.sin_port = htons(PORT);
	if((s = sendto(sendfd, (void*)sendBuff, sizeof(sendBuff), 0, (struct sockaddr *)&dest, sizeof(dest))) < sizeof(sendBuff)){
		printf("Could not send total packet only part of the packet of size %d is sent\n",s);
		exit(0);
	}
	printf("Packet SENT:\n");
}
