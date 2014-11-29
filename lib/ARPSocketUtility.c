/*
 * ARPSocketUtility.c
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */
#include "ARPSocketUtility.h"

int ipToInfMapperSize =0;
ifInfo* ipToInfMapper=NULL;


int isEth0(char* name) {
	if(!strncmp(ETHERNET0,name,16)) {
		return 1;
	}
	return 0;
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
int getNumOfInterfaces() {
	struct hwa_info	*hwa, *hwahead;
	int size =0;
	for (hwahead = hwa = Get_hw_addrs(); hwa != NULL; hwa = hwa->hwa_next) {
		if (isEth0(hwa->if_name)) {
			size++;
		}
	}
	return size;
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
	int numOfinterfaces = getNumOfInterfaces();
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
