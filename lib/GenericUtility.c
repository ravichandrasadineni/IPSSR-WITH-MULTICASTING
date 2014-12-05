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

int isEth0(char* name) {
	if(!strncmp(ETHERNET0,name,16)) {
		return 1;
	}
	return 0;
}

unsigned int malarm (unsigned int milliseconds)
{

	struct itimerval old, new;
	new.it_interval.tv_usec = 0;
	new.it_interval.tv_sec = 0;
	new.it_value.tv_usec = 0;
	new.it_value.tv_sec = 0;
	if(milliseconds >= 1000 ) {
		new.it_value.tv_sec = milliseconds/1000;
	}
	new.it_value.tv_usec = (milliseconds%1000)*1000;
	if (setitimer (ITIMER_REAL, &new, &old) < 0) {
		perror("setitimer failed ErrorNo :");
		exit(2);
	}
	else
		return old.it_value.tv_sec;
}


void intTochar( int number, char* string) {
	snprintf(string, 10,"%d",number);
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



char* getIpAddStr_ARPIPFMT(u_int8_t ipAddr[4]) {
	struct in_addr sinAddr;
	sinAddr.s_addr =getSaddr(ipAddr);
	return inet_ntoa(sinAddr);
}

void setARPIPBlock(struct in_addr sAddr, u_int8_t ipAddr[4]) {
	memcpy (ipAddr, &sAddr, 4 * sizeof (uint8_t));
}

int getSaddr(u_int8_t ipAddr[4]) {
	u_int32_t ipAdrress;
	memcpy (&ipAdrress,ipAddr, 4 * sizeof (uint8_t));
	return ipAdrress;
}


void printMacAddress (char haddr[HADDR_LEN]) {
	int i;
	for (i=0; i<HADDR_LEN-1; i++) {
		printf ("%02x:", (unsigned char)haddr[i]);
	}

	printf ("%02x", (unsigned char)haddr[i]);

}





int isSameIP(char IpAddr1[INET_ADDRSTRLEN], char IpAddr2[INET_ADDRSTRLEN]) {
	int i;
	if (!strncmp(IpAddr1, IpAddr2, INET_ADDRSTRLEN)) {
		return TRUE;
	}
	return FALSE;
}

int isMYIP (struct sockaddr_in ipAddress) {
	char localipaddress[INET_ADDRSTRLEN];
	char receivedipAddr[INET_ADDRSTRLEN];
	populateLocalIpAddress(localipaddress);
	inet_ntop(AF_INET, &(ipAddress.sin_addr), receivedipAddr, INET_ADDRSTRLEN);
	return isSameIP(localipaddress, receivedipAddr);
}

