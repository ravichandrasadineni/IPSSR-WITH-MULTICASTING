#include "GenericUtility.h"


int isSameMac(char mac1[HADDR_LEN], char mac2[HADDR_LEN]) {
	int i;
	for (i=0; i < HADDR_LEN; i++) {
		if(mac1[i] != mac2[i]) {
			return FALSE;
		}
	}
	return TRUE;
}


void printMacAddress (char haddr[HADDR_LEN]) {
	int i;
	for (i=0; i<HADDR_LEN; i++) {
		printf ("%02x:", (unsigned char)haddr[i]);
	}

}



int isSameIP(char IpAddr1[INET_ADDRSTRLEN], char IpAddr2[INET_ADDRSTRLEN]) {
	int i;
	if (!strncmp(IpAddr1, IpAddr2, INET_ADDRSTRLEN)) {
		return TRUE;
	}
	return FALSE;
}
