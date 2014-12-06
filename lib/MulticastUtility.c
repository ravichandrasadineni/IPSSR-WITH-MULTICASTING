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
		perror("MulticastUtility.c :Opening datagram socket error");
		exit(1);
	}
	localInterface.s_addr = inet_addr(getEth0IpAddress());
	if(setsockopt(sd, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0)
	{
		perror("MulticastUtility.c :Setting local interface error");
		exit(1);
	}
	printf("MulticastUtility.c :created Multicast Sending Socket %d \n", sd);
	return sd;
}

int createMultiCastListeningsocket() {
	int sd;
	struct sockaddr_in localSock;
	struct ip_mreq group;
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sd < 0)
	{
		perror("MulticastUtility.c :Opening datagram socket error");
		exit(1);
	}
	memset((char *) &localSock, 0, sizeof(localSock));
	localSock.sin_family = AF_INET;
	localSock.sin_port = htons(MULTICASTPORT);
	localSock.sin_addr.s_addr = htons(INADDR_ANY);
	if(bind(sd, (struct sockaddr*)&localSock, sizeof(localSock)))
	{
		perror("MulticastUtility.c :Binding datagram socket error");
		close(sd);
		exit(1);
	}
	group.imr_multiaddr.s_addr = inet_addr(MULTICASTADDR);
	group.imr_interface.s_addr = inet_addr(getEth0IpAddress());
	if(setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&group, sizeof(group)) < 0)
	{
		perror("MulticastUtility.c :Adding multicast group error");
		close(sd);
		exit(1);
	}
	printf("MulticastUtility.c :created Multicast Listening  Socket %d \n", sd);
	return sd;

}

void sendMultiCastMessage(int sockFd, int type) {
	printf("Sending Multicast messages \n");
	struct sockaddr_in groupSock;
	char localAddress[INET_ADDRSTRLEN];
	char message[2];
	memset(message,'\0',2);
	memset((char *) &groupSock, 0, sizeof(groupSock));
	groupSock.sin_family = AF_INET;
	groupSock.sin_addr.s_addr = inet_addr(MULTICASTADDR);
	groupSock.sin_port = htons(MULTICASTPORT);
	populateLocalAddress(localAddress);
	if (type == MULTICAST_MESSAGE_INIT) {
		strncpy(message, "1",strlen("1"));
		printf("Node %s. Sending This is node %s. Tour has ended. Group members please identify yourselves.>>\n",localAddress,localAddress);

	}
	else {
		strncpy(message, "2",strlen("2"));
		printf("Node %s. Sending Node %s I am a member of the group\n",localAddress, localAddress);
	}
	//printf("MulticastUtility.c : sending message Type %s \n",message);
	if(sendto(sockFd, &message, strlen(message), 0, (struct sockaddr*)&groupSock, sizeof(groupSock)) < 0){
		perror("Sending datagram message error");
	}

	else
		printf("MulticastUtility.c : Sending datagram message...OK\n");

}

void recvAndReplyMulticastMessage(int recvsockfd, int sendSockfd) {
//	printf("Recieved multicast \n");
	char databuf[1024];
	char localAddr[INET_ADDRSTRLEN];
	struct sockaddr_in ipAddress;
	int addrLength = sizeof(struct sockaddr_in);
	if(recvfrom(recvsockfd, databuf, MTU,0,(SA *)&ipAddress,&addrLength) < 0)
	{
		perror("Reading datagram message error");
		close(recvsockfd);
		exit(1);
	}
	populateLocalAddress(localAddr);
	if ((databuf[0] == '1') && (!isMYIP(ipAddress)) ) {
		printf("Node %s. Received This is node %s. Tour has ended. Group members please identify yourselves.\n",localAddr,inet_ntoa(ipAddress.sin_addr));
		//		printf("Received Multicast Message from %s \n", inet_ntoa(ipAddress.sin_addr));
		sendMultiCastMessage(sendSockfd,MULTICAST_MESSAGE_REP );


	} else  {
		//		printf("Received Multicast Message from %s \n", inet_ntoa(ipAddress.sin_addr));
		if(databuf[0] == '1'){
			printf("Node %s. Received This is node %s. Tour has ended. Group members please identify yourselves.\n",localAddr, inet_ntoa(ipAddress.sin_addr));
		}
		else{
			printf("Node %s. Received  Node %s .  I am a member of the group.\n",localAddr, inet_ntoa(ipAddress.sin_addr));
		}
	}

}

void handleMulticasting(int listeningSocket, int readSocket) {
	fd_set readSet;
	struct timeval pTV;
	int maxfd, returnValue;
	pTV.tv_sec = 5;
	pTV.tv_usec =0;
	while (1) {
		FD_ZERO (&readSet);
		FD_SET(listeningSocket,&readSet);
		maxfd = listeningSocket +1;
		if((returnValue = select(maxfd,&readSet,NULL,NULL,&pTV))<0) {
			if( errno == EINTR){
				printf("Continue \n");
			}
		}
		if(returnValue == 0 ) {
			printf("Tour Done and Exiting  \n");
			exit(0);
		}
		if(FD_ISSET(listeningSocket,&readSet)) {
			recvAndReplyMulticastMessage(listeningSocket, readSocket);
		}
	}

}
