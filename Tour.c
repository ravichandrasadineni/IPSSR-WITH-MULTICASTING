/*
 * Tour.c
 *
 *  Created on: Nov 28, 2014
 *      Author: harsha
 */


#include "lib/TourUtility.h"
#include "lib/Constants.h"
#include "lib/MemoryAllocator.h"
unsigned int version = 4;
u_int8_t protocol = 127;
struct isVisited Visited;
u_int8_t TTLive = 1;
int count;

int createIPRAWSocket(int headerInclude){
	int sockfd, on = 1;
	struct sockaddr_in tourAddr;
	char localAddr[INET_ADDRSTRLEN];
	if(headerInclude == 1){
		if( (sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_CONSTANT)) < 0){
			perror("Creating IPRAW Socket Failed:");
			exit(0);
		}
		setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on,sizeof(on));
		tourAddr.sin_port = htons(PORT);
	}
	else{
		if( (sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0){
			perror("Creating ICMP Socket Failed:");
			exit(0);
		}
		tourAddr.sin_port = htons(ICMP_PORT);
	}
	tourAddr.sin_family = AF_INET;
	populateLocalAddress(localAddr);
	if(inet_pton(AF_INET, localAddr, &(tourAddr.sin_addr.s_addr)) < 0){
		perror("inet_pton failed :");
		exit(0);
	}
	if( bind(sockfd, (struct sockaddr *)&tourAddr, sizeof(tourAddr)) < 0){
		perror("Bind failed :");
		exit(0);
	}
	printf("Binded Socket\n");
	return sockfd;
}

void buildIPMessage(int rt, char Payload[MTU], char destAddr[INET_ADDRSTRLEN], char* Message){
	char localAddress[INET_ADDRSTRLEN];
	Message = allocate_strmem(MTU);
	printf("The payload is %s\n",Payload);
	struct ipPacket *ipMessage = malloc(sizeof(struct ipPacket));
	memset(ipMessage, '\0', sizeof(struct ipPacket));
	memset(Message, '\0', sizeof(MTU));
	ipMessage = (struct ipPacket *)Message;
	populateLocalAddress(localAddress);
	ipMessage->ip_v = IPVERSION;
	ipMessage->ip_hl = sizeof(struct iphdr)>>2;
	ipMessage->ip_ttl = 0;
	ipMessage->ip_tos = 0;
	ipMessage->ip_sum = 0;
	ipMessage->ip_src.s_addr = inet_addr(localAddress);
	ipMessage->ip_dst.s_addr = inet_addr(destAddr);
	ipMessage->ip_p = htons(protocol);
	ipMessage->ip_len = sizeof(struct iphdr) + sizeof(Payload);
	ipMessage->ip_id = htons(IP_IDENTIFICATION);
	printf("The version is %d\thl is %d\ttos is %d\tcheck is %d\tproto is %d\tttl is %d\tid is %d\ttot_len is %d\n",ipMessage->ip_v,ipMessage->ip_hl,ipMessage->ip_tos,ipMessage->ip_sum,ipMessage->ip_p,ipMessage->ip_ttl,ipMessage->ip_id, ipMessage->ip_len);
	memcpy(ipMessage->Payload, Payload, MTU);
	printf("The payload of IpPacket is %s\n",ipMessage->Payload);
	send_packet(rt, Message, destAddr);
}

void buildPayload(char* argv[], int argc, char Message[1024]){
	int i;
	char ipAddr[INET_ADDRSTRLEN], localAddress[1024];
	char *count = "0";
	strncat(Message, count, sizeof(count));
	strncat(Message, DELIMITER, sizeof(DELIMITER));
	populateLocalAddress(localAddress);
	strncat(Message, localAddress, INET_ADDRSTRLEN);
	strncat(Message, DELIMITER, sizeof(DELIMITER));
	for (i=1; i < argc; i++){
		getIpAddressFromDomainName(argv[i], ipAddr);
		strncat(Message, ipAddr, INET_ADDRSTRLEN);
		strncat(Message, DELIMITER, sizeof(DELIMITER));
	}
	strncat(Message, MULTICASTADDR, INET_ADDRSTRLEN);
	strncat(Message, DELIMITER, sizeof(DELIMITER));
	strncat(Message, MULTICASTPORT, sizeof(MULTICASTPORT));
	printf("The message is %s \n",Message);
}



int main(int argc, char* argv[]){
	int i, on=1, rt, pg, includeHeader = 1, donotincludeHeader = 0;
	char localAddr[INET_ADDRSTRLEN], Payload[MTU];
	char *recvBuffer, sendBuffer[MTU];
	struct iphdr *Header;
	struct sockaddr_in tourAddr;
	struct ip *ipPacket;
	memset(Payload,'\0',MTU);
	rt = createIPRAWSocket(includeHeader);
	pg = createIPRAWSocket(donotincludeHeader);
	if(argc < 2){
		//This not is not meant for initiating the Tour
		recvmessage(rt, pg, recvBuffer);
	}
	buildPayload(argv, argc, Payload);
	printf("The payload in main is %s size of Payload is %ld\n",Payload, sizeof(Payload));
	buildIPMessage(rt, Payload, argv[1], sendBuffer);
	return 0;
}
