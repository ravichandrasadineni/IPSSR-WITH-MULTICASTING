/*
 * ARPSocketUtility.c
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */
#include "ARPSocketUtility.h"

int ipToInfMapperSize =0;
ifInfo* ipToInfMapper=NULL;

int openSocketList[OPEN_SOCKET_LIST_SIZE];
int currentOpenSocketListSize =0;


void addtoOpenSocketList(int sockFd) {
	openSocketList[currentOpenSocketListSize] = sockFd;
	currentOpenSocketListSize++;
}

int getSetSocket(fd_set* readSet) {
	int i;
	for(i=0; i<currentOpenSocketListSize; i++ ) {
		if(FD_ISSET(openSocketList[i],readSet)) {
			return openSocketList[i];
		}
	}
	return -1;
}

void deleteFromOpenSocketList(int sockFd) {
	int i;
	int socketIndex = -1;
	for(i=0; i<currentOpenSocketListSize; i++) {
		if(openSocketList[i] == sockFd) {
			socketIndex = i;
		}
	}
	for(i=socketIndex; i<currentOpenSocketListSize-1;i++ ) {
		openSocketList[i] = openSocketList[i+1];
	}
	currentOpenSocketListSize--;
}


void setReadSetForOpenSockets(fd_set* readSet, int* maxfd) {
	int i ;
	for (i=0; i<currentOpenSocketListSize; i++) {
		FD_SET(openSocketList[i],readSet);

		*maxfd = MAX(*maxfd,openSocketList[i]);
	}
}

int createNewSocket() {
	int s = socket(PF_PACKET, SOCK_RAW,htons(ETH_TYPE));
	if(s == -1) {
		perror("socket Error: ");
		exit(0);
	}
	return s;
}

int createAndBindSocketsPF_PACKETSOCKET() {
	int sockfd = createNewSocket();
	struct sockaddr_ll sADDR;
	memset(&sADDR,'\0', sizeof(sADDR));
	sADDR.sll_ifindex =getEth0Index() ;
	sADDR.sll_halen = ETH_ALEN;
	sADDR.sll_protocol = htons(ETH_TYPE);
	sADDR.sll_family = PF_PACKET;
	if(bind(sockfd,(SA*)&sADDR,sizeof(sADDR)) <0) {
		perror("BINDING SOCKET TO INTERFACE FAILED :");
		exit(1);
	}
	return sockfd;
}
int getNumOfAliases() {
	struct hwa_info	*hwa, *hwahead;
	int size =0;
	for (hwahead = hwa = Get_hw_addrs(); hwa != NULL; hwa = hwa->hwa_next) {
		if (isEth0(hwa->if_name)) {
			size++;
		}
	}
	free_hwa_info(hwahead);
	return size;
}

void populateLocalMacAddress(char macAddress[HADDR_LEN]) {
	if (ipToInfMapperSize> 0) {
		memcpy(macAddress, ipToInfMapper[0].if_haddr, HADDR_LEN);
	}
	else {
		printf("ARPSocketUtility.c : Interface List not initialized \n");
		exit(0);
	}
}


void populateLocalIpAddress(char ipAddress[INET_ADDRSTRLEN]) {

	if (ipToInfMapperSize> 0) {
		memcpy(ipAddress, ipToInfMapper[0].ip_address, INET_ADDRSTRLEN);
	}
	else {
		printf("ARPSocketUtility.c : Interface List not initialized \n");
		exit(0);
	}
}


void getDetailsOfInterfaces() {
	struct hwa_info	*hwa, *hwahead;
	struct sockaddr	*sa;
	char   *ptr;
	int    i, prflag;
	printf("interfaceList : \n");
	ifInfo* currentipToInfMapper = ipToInfMapper;
	for (hwahead = hwa = Get_hw_addrs(); hwa != NULL; hwa = hwa->hwa_next) {
		if (isEth0(hwa->if_name)) {
			memcpy(currentipToInfMapper->if_haddr,hwa->if_haddr,HADDR_LEN);
			struct sockaddr_in *ipAddress = (struct sockaddr_in *)hwa->ip_addr;
			strncpy(currentipToInfMapper->ip_address,inet_ntoa(ipAddress->sin_addr), INET_ADDRSTRLEN);
			currentipToInfMapper->if_index = hwa->if_index;
			printMacAddress(currentipToInfMapper->if_haddr);
			printf("-------> %s \n",currentipToInfMapper->ip_address);
			currentipToInfMapper++;
			ipToInfMapperSize++;
		}
	}
	free_hwa_info(hwahead);
}

void initializeList() {
	int numOfinterfaces = getNumOfAliases();
	ipToInfMapper = (ifInfo*)allocate_void(numOfinterfaces*sizeof(ifInfo));
	getDetailsOfInterfaces();
}

int isMyIP(char ipAddress[INET_ADDRSTRLEN]) {
	int i;
	for(i=0; i<ipToInfMapperSize;i++) {
		if(isSameIP(ipAddress,ipToInfMapper[i].ip_address)) {
			return TRUE;
		}
	}
	return FALSE;
}
void populateMacForIP(char ipAddress[INET_ADDRSTRLEN],char macAddress[HADDR_LEN]) {
	memset(macAddress, '\0', HADDR_LEN);
	int i;
	for(i=0; i<ipToInfMapperSize;i++) {

		if(isSameIP(ipAddress,ipToInfMapper[i].ip_address)) {
			memcpy(macAddress, ipToInfMapper[i].if_haddr, HADDR_LEN);
		}
	}
}
