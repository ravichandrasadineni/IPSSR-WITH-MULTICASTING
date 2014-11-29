/*
 * UDSUtility.c
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#include "ARPUDSUtility.h"
#include "ARPUDSUtility.h"

int getARPclientBindedsocket() {
	int sockfd, fileFd;
	char nameBuff[32];
	struct sockaddr_un cliaddr;
	bzero(&cliaddr, sizeof(cliaddr));
	sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
	if(sockfd < 0) {
		perror("unable to create client Unix Domain Socket :");
		exit(0);
	}
	memset(nameBuff,0,sizeof(nameBuff));

	strncpy(nameBuff,ARP_CLIENT_PRE ,FILE_NAME_LENGTH);
	mkstemp(nameBuff);

	unlink(nameBuff);
	cliaddr.sun_family = AF_LOCAL;
	strncpy(cliaddr.sun_path,nameBuff,strlen(nameBuff));
	if(bind(sockfd,(SA *)&cliaddr, sizeof(cliaddr))<0) {
		perror("Failed to Bind Unix Domain Socket :");
		exit(0);
	}
	return sockfd;
}

int getARPBindedsocket() {
	int sockfd, fileFd;
	char nameBuff[32];
	struct sockaddr_un servaddr;
	bzero(&servaddr, sizeof(servaddr));
	sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
	if(sockfd < 0) {
		perror("unable to create client Unix Domain Socket :");
		exit(0);
	}
	memset(nameBuff,0,sizeof(nameBuff));
	strncpy(nameBuff,ARP_FILE_NAME,FILE_NAME_LENGTH);
	unlink(nameBuff);
	servaddr.sun_family = AF_LOCAL;
	strncpy(servaddr.sun_path,nameBuff,strlen(nameBuff));
	if(bind(sockfd,(SA *)&servaddr, sizeof(servaddr))<0) {
		perror("Failed to Bind Unix Domain Socket :");
		exit(0);
	}
	return sockfd;
}

void unLinkSocket(int sockFd) {
	struct sockaddr_un unixSocket;
	int sockLen;
	if(getsockname(sockFd, (SA*)&unixSocket	,&sockLen)<0) {
		perror("Failed to UNLINK temporary FIle ");
		return;
	}
	remove(unixSocket.sun_path);
	return;
}

void connectTO (int sockfd, char*fileName) {
	struct sockaddr_un servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sun_family = AF_LOCAL;
	strncpy(servaddr.sun_path,fileName, strlen(fileName));
	if(connect(sockfd,(SA *)&servaddr, sizeof(servaddr))<0) {
		perror("UDSUtility.C:Failed to connect Unix Domain Socket  :");
		unLinkSocket(sockfd);
		exit(0);
	}
}

void connectToARP(int sockfd) {
	connectTO(sockfd,ARP_FILE_NAME);

}



