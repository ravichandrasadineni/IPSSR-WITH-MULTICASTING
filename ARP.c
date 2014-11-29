/*
 * ARP.c
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */


#include "lib/ARPAPI.h"
#include "lib/ARPSocketUtility.h"
#include "lib/ARPUDSUtility.h"

int main(int argc, char *argv) {
	initializeList();
	int pfPacketSocket = createAndBindSocketsPF_PACKETSOCKET();
	int udsSocket = getARPBindedsocket();
	int maxfd=0;
	fd_set readSet;
	FD_ZERO (&readSet);
	maxfd = MAX(udsSocket,pfPacketSocket) + 1;
	while(1) {
		FD_SET(pfPacketSocket,&readSet);
		FD_SET(udsSocket,&readSet);
		if((select(maxfd,&readSet,NULL,NULL,NULL))<0) {
			perror("ARPAPI.c : Select in the client Failed :");
		}

	}

}
