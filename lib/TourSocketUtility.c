/*
 * TourSocketUtility.c
 *
 *  Created on: Dec 3, 2014
 *      Author: ravichandrasadineni
 */

#include "TourSocketUtility.h"


int isEth0(char* name) {
	if(!strncmp(ETHERNET0,name,16)) {
		return 1;
	}
	return 0;
}

void populateEth0Mac(char macAddress[HADDR_LEN]) {
	memset(macAddress,"\0",HADDR_LEN);
	struct hwa_info	*hwa, *hwahead;
		for (hwahead = hwa = Get_hw_addrs(); hwa != NULL; hwa = hwa->hwa_next) {
			if (isEth0(hwa->if_name)) {
				memcpy(macAddress,hwa->if_haddr,HADDR_LEN);
			}
		}
		free_hwa_info(hwahead);
		return;
}


char* getEth0IpAddress() {
	struct hwa_info	*hwa, *hwahead;
	for (hwahead = hwa = Get_hw_addrs(); hwa != NULL; hwa = hwa->hwa_next) {
		if (isEth0(hwa->if_name)) {
			struct sockaddr_in *ipAddress = (struct sockaddr_in *)hwa->ip_addr;
			free_hwa_info(hwahead);
			return inet_ntoa(ipAddress->sin_addr);
		}
	}
	free_hwa_info(hwahead);
	return NULL;
}

int getEth0Index() {
	struct hwa_info	*hwa, *hwahead;
	for (hwahead = hwa = Get_hw_addrs(); hwa != NULL; hwa = hwa->hwa_next) {
		if (isEth0(hwa->if_name)) {
			return hwa->if_index;
		}
	}
	return -1;
}



int createICMPSocket(){
	int sockfd, on = 1;
	struct sockaddr_in tourAddr;
	char localAddr[INET_ADDRSTRLEN];
	if( (sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0){
		perror("Creating ICMP Socket Failed:");
		exit(0);
	}
	tourAddr.sin_family = AF_INET;
	tourAddr.sin_port = 0;
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

int createTourSocket() {
	int sockfd, on = 1;
	struct sockaddr_in tourAddr;
	char localAddr[INET_ADDRSTRLEN];

	if( (sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_CONSTANT)) < 0){
		perror("Creating IPRAW Socket Failed:");
		exit(0);
	}
	setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on,sizeof(on));
	tourAddr.sin_port = 0;

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



int createPFPacketSocket() {
	int s = socket(PF_PACKET, SOCK_RAW,htons(ETH_P_IP));
	if(s == -1) {
		perror("socket Error: ");
		exit(0);
	}
	return s;
}

void bindPfPacketSocket(int sockfd, int interfaceIndex) {
	struct sockaddr_ll sADDR;
	memset(&sADDR,'\0', sizeof(sADDR));
	sADDR.sll_ifindex =  interfaceIndex;
	sADDR.sll_halen = ETH_ALEN;
	sADDR.sll_protocol = htons(ETH_P_IP);
	sADDR.sll_family = PF_PACKET;
	if(bind(sockfd,(SA*)&sADDR,sizeof(sADDR)) <0) {
		perror("BINDING SOCKET TO INTERFACE FAILED :");
		exit(1);
	}
}




