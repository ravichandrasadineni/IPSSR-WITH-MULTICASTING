/*
 * AddressUtility.c
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */
#include "AddressUtility.h"


int isValidDomainName(char* string) {
	 char stringCopy[strlen(string)];
	 strcpy(stringCopy,string);
	 struct hostent *he;
	 he = gethostbyname(stringCopy);
	 if (he == NULL) {
         herror("Invalid Domain Name :");
         return 0;
    }
	 return 1;
}

void populateLocalAddress(char localAddress[INET_ADDRSTRLEN]) {
	char localHostname[1024];
	gethostname(localHostname, 1023);
	getIpAddressFromDomainName(localHostname,localAddress);
}

void getIpAddressFromDomainName(char* string, char* ipAddress) {
	struct hostent *he;
	struct in_addr **addr_list;
	if(!isValidDomainName(string)) {
		exit(0);
	}
	he = gethostbyname(string);
    addr_list = (struct in_addr **)he->h_addr_list;
	char* ip_address = inet_ntoa(*addr_list[0]);
    strncpy(ipAddress,ip_address, INET_ADDRSTRLEN);
}

char* getDomainNameFromIpAddress(struct in_addr ipAddress) {
	struct hostent *he;
	char* domainName = allocate_strmem(100);
	he =  gethostbyaddr(&ipAddress, sizeof(struct sockaddr_in),AF_INET);
	strncpy(domainName,he->h_name,100);
	return domainName;
}


char* getDomainName(char ipString[INET_ADDRSTRLEN]) {
	struct in_addr ipAddress;
	char* domainName = allocate_strmem(100);
	inet_pton(AF_INET, ipString, &(ipAddress));
	struct hostent *he;
	he =  gethostbyaddr(&(ipAddress), sizeof(struct sockaddr_in),AF_INET);
	strncpy(domainName,he->h_name,100);
	return domainName;;
}



