/*
 * TourUtility.c
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */
#include "TourUtility.h"

struct isVisited *head = NULL;
struct isVisited *tail = NULL;


int isLastNodeinTour(char *recvBuffer, int *count){
	char *token = strtok(recvBuffer, DELIMITER);
	int noOfTokens;
	while(token != NULL){
		noOfTokens++;
		token = strtok(NULL, DELIMITER);
	}
	if(*count >= noOfTokens-3)
		return 1;
	else
		return 0;
}

void inititatePing(char* recvBuffer){
	struct iphdr *ipHeader = malloc(sizeof(struct iphdr));
	char sourceAddr[INET_ADDRSTRLEN];
	ipHeader = (struct iphdr *)recvBuffer;
	memcpy(sourceAddr, &(ipHeader->saddr), INET_ADDRSTRLEN);

}

void unmarshallMessage(char *recvBuffer, char *destination, int *count){
	char Buffer[MTU];
	strncpy(Buffer, recvBuffer, MTU);
	int noOfTokens;
	if(!isLastNodeinTour(Buffer, count)){
		char *token = strtok(Buffer, DELIMITER);
		*count = atoi(token);
		while(token != NULL){
			noOfTokens++;
			token = strtok(NULL, DELIMITER);
			if(noOfTokens == *count){
				destination = token;
			}
		}
	}
	else{
		printf("This is last node:");
	}
}

int isAlreadyVisited(char* sourceAddr){
	struct isVisited *temp = head;
	if(temp == NULL){
		return 0;
	}
	while(temp != NULL){
		if(!strncmp(temp->ipAddress, sourceAddr, INET_ADDRSTRLEN)){
			return 1;
			break;
		}
		temp = temp->next;
	}
	return 0;
}

void addnodetoVisited(char* sourceAddr){
	struct isVisited *add = tail;
	//if isVisited is empty add it to the first node
	if(add == NULL){
		add->Visited = 1;
		memcpy(add->ipAddress, sourceAddr, INET_ADDRSTRLEN);
		add->next = NULL;
	}
	else{
		//if isVisited is not empty we can add new values at the end of the list
		while(add != NULL){
			add = add->next;
		}
		add->Visited = 1;
		memcpy(add->ipAddress, sourceAddr, INET_ADDRSTRLEN);
		add->next = NULL;
	}
}

void createandBindUDPScoket(int port, char mulcastAddr[INET_ADDRSTRLEN],int *sockfd){
	sockfd = allocate_intmem(2);
	char localAddress[INET_ADDRSTRLEN];
	struct sockaddr_in cliaddr;
	struct in_addr sourceAddress;
	if( (sockfd[0] = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("Creation of socket Failed :");
		exit(0);
	}
	if((sockfd[1] = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("Creation of second UDP Socket Failed :");
		exit(0);
	}
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(INADDR_ANY);
	populateLocalAddress(localAddress);
	if (inet_pton(localAddress, &sourceAddress, INET_ADDRSTRLEN ) < 0){
		perror("inet_pton failed :");
		exit(0);
	}
	cliaddr.sin_addr.s_addr = inet_addr(sourceAddress);
	if(bind(sockfd[0],(struct sockaddr *)&cliaddr, sizeof(cliaddr))< 0){
		perror("Bind Failed while creating UDP Socket:");
		exit(0);
	}
}

void joinMulticastgroup(int sockfd){
	struct ip_mreq multicastgroup;
	struct in_addr mulcast_addr;
	int mulcast_join = sockfd;
	bzero(&multicastgroup,sizeof(multicastgroup));
	multicastgroup.imr_interface.s_addr = htonl(INADDR_ANY);
	//inet_pton(mulcastAddr, &mulcast_addr, INET_ADDRSTRLEN );
	multicastgroup.imr_multiaddr.s_addr = inet_addr(MULTICASTADDR);
	setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &multicastgroup, sizeof(multicastgroup));
}

void recvmessage(int recvfd, char* recvBuffer ){
	struct ip *ipPacket;
	struct iphdr *ipHeader;
	int count,sockfd[2];
	char destination[INET_ADDRSTRLEN], sourceAddr[INET_ADDRSTRLEN];
	recv_packet(recvfd, recvBuffer);
	unmarshallMessage(recvBuffer, destination, &count);
	ipHeader = (struct iphdr *)recvBuffer;
	memcpy(sourceAddr, &(ipHeader->saddr), INET_ADDRSTRLEN);
	if(isLastNodeinTour(recvBuffer, &count)){
		//isAlready visited True we got nothing to update except to print the message
		if(!isAlreadyVisited(sourceAddr)){
			//Join mulitcast group ping the previous source and send the multicast message
			//Since this is the last node there is no harm even need to add source to isVisited
			joinMulticastgroup(sockfd[0]);
			inititatePing(recvBuffer);

		}
		else{
			//send Multicast message
		}
	}
	else{
		if(!isAlreadyVisited(sourceAddr)){
			//Join mulitcast group ping the previous source and add the Source to isVisited
			addnodetoVisited(sourceAddr);
		}
		else{
			//do nothing
		}
	}
}
