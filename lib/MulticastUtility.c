/*
 * MulticastUtility.c
 *
 *  Created on: Dec 4, 2014
 *      Author: ravichandrasadineni
 */

#include "MulticastUtility.h"


int  createSendingSocket() {
	int sd;

	struct in_addr localInterface;
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sd < 0)
	{
		perror("Opening datagram socket error");
		exit(1);
	}
	localInterface.s_addr = inet_addr(getEth0IpAddress());
	if(setsockopt(sd, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0)
	{
		perror("Setting local interface error");
		exit(1);
	}
	return sd;
}

int createMultiCastListeningsocket() {
	int sd;
	struct sockaddr_in localSock;
	struct ip_mreq group;
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sd < 0)
	{
		perror("Opening datagram socket error");
		exit(1);
	}
	memset((char *) &localSock, 0, sizeof(localSock));
	localSock.sin_family = AF_INET;
	localSock.sin_port = htons(MULTICASTPORT);
	localSock.sin_addr.s_addr = INADDR_ANY;
	if(bind(sd, (struct sockaddr*)&localSock, sizeof(localSock)))
	{
		perror("Binding datagram socket error");
		close(sd);
		exit(1);
	}
	group.imr_multiaddr.s_addr = inet_addr(MULTICASTADDR);
	group.imr_interface.s_addr = inet_addr(getEth0IpAddress());
	if(setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&group, sizeof(group)) < 0)
	{
		perror("Adding multicast group error");
		close(sd);
		exit(1);
	}
	return sd;

}

void sendMultiCastMessage(int sockFd) {
	struct sockaddr_in groupSock;
	memset((char *) &groupSock, 0, sizeof(groupSock));
	groupSock.sin_family = AF_INET;
	groupSock.sin_addr.s_addr = inet_addr(MULTICASTADDR);
	groupSock.sin_port = htons(MULTICASTPORT);
	if(sendto(sockFd, MULTICAST_MESSAGE, datalen, 0, (struct sockaddr*)&groupSock, sizeof(groupSock)) < 0){
		perror("Sending datagram message error");}
	else
		printf("Sending datagram message...OK\n");

}

void recvAndReplyMulticastMessage(int recvsockfd, int sendSockfd) {
	char databuf[1024];
	if(read(recvsockfd, databuf, 1024) < 0)
	{
		perror("Reading datagram message error");
		close(recvsockfd);
		exit(1);
	}
	sendMultiCastMessage(sendSockfd);
}

