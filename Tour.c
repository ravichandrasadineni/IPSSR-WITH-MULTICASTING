/*
 * Tour.c
 *
 *  Created on: Nov 28, 2014
 *      Author: harsha
 */


#include "lib/TourUtility.h"
#include "lib/Constants.h"
unsigned int version = 4;
u_int8_t protocol = 127;
struct isVisited Visited;
int count;

void buildIPMessage(char *Payload, char destAddr[INET_ADDRSTRLEN], char* Message){
	*Payload = allocate_strmem(1516);
	char localAddress[INET_ADDRSTRLEN];
	Message = allocate_strmem(MTU);
	struct ip *ipMessage;
	struct iphdr *ipHeader = (struct iphdr *)Payload;
	u_int32_t sourceAddr, destAddress;
	ipHeader = malloc(20);
	ipHeader->version = (unsigned int)version;
	ipHeader->tos = (unsigned int) 0;
	ipHeader->check = htons(0);
	ipHeader->tot_len = htons(sizeof(Payload) + sizeof(ipHeader));
	populateLocalAddress(localAddress);
	ipHeader->saddr = htons(inet_addr(localAddress));
	ipHeader->daddr = htons(inet_addr(destAddress));
	ipHeader->protocol = htons(IPPROTO_CONSTANT);
	ipHeader->ttl = htons(TTL);
	ipHeader->id = htons(IP_IDENTIFICATION);
	ipHeader->ihl = htons(IPHEADER_LENGTH);

}

void buildPayload(char* argv[], int argc, char Message[1024]){
	int i;
	char ipAddr[INET_ADDRSTRLEN], localAddress[1024];
	count = 0;
	strncat(Message, (char *)(&count), sizeof(count));
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
	int i, on=1, rt, pg;
	char localAddr[INET_ADDRSTRLEN], Payload[MTU];
	char *recvBuffer, sendBuffer[MTU];
	struct iphdr *Header;
	struct sockaddr_in tourAddr;
	struct ip *ipPacket;
	if( (rt = socket(AF_INET, SOCK_RAW, IPPROTO_CONSTANT)) < 0){
		perror("Creating Socket Failed:");
		exit(0);
	}
	setsockopt(rt, IPPROTO_IP, IP_HDRINCL, &on,sizeof(on));
	(recvBuffer) = allocate_strmem(MTU);
	if(argc < 2){
		recvmessage(rt, recvBuffer);
	}
	memset(Payload,'\0',MTU);
	buildPayload(argv, argc, Payload);
	printf("The payload in main is %s\n",Payload);
	tourAddr.sin_family = AF_INET;
	tourAddr.sin_port = PORT;
	populateLocalAddress(localAddr);
	if(inet_pton(AF_INET, localAddr, &(tourAddr.sin_addr.s_addr)) < 0){
		perror("inet_pton failed :");
		exit(0);
	}

	if( bind(rt, (struct sockaddr *)&tourAddr, sizeof(tourAddr)) < 0){
		perror("Bind failed :");
		exit(0);
	}
	printf("Binded Socket\n");
	buildIPMessage(Payload, argv[1], sendBuffer);
//	Header = malloc(20);
//	Header = (struct iphdr *)ipPacket;
//	Header->version = ptons(version);
//	Header->version = ptons(version);
//	Header->protocol = ptons(protocol);
//	Header->ttl = ptons(TTL);
//	Header->tos = 0;
//	Header->saddr = localAddr;

	return 1;
}
