/*
 * Tour.c
 *
 *  Created on: Nov 28, 2014
 *      Author: harsha
 */
#include "lib/TourUtility.h"
#include "lib/Constants.h"
#include "lib/ICMPUtility.h"
#include "lib/MemoryAllocator.h"
#include "lib/GenericUtility.h"
#include "lib/TourSocketUtility.h"

int ISLASTNODEANDWAITED=FALSE;
int isListeninngSocketCreated = FALSE;
static void sig_alarm(int signo) {
	ISLASTNODEANDWAITED = TRUE;
}

int main(int argc, char* argv[]){
	int i, on=1, rt, pg, includeHeader = 1, donotincludeHeader = 0;
	struct timeval pTV;
	pTV.tv_sec = 1;
	pTV.tv_usec =0;
	int multicastListeningSocket = MULTICAST_NOT_SET;
	int multicastSendingSocket = createSendingSocket();
	signal(SIGALRM, sig_alarm);
	pg = createICMPSocket();
	rt = createTourSocket();
	struct timeval* tv = NULL;
	if(argc >= 2) {
		initateTour(rt,argc,argv);
		printf("sent Initial Tour Packet \n");

	}
	fd_set readSet;
	int returnvalue, timeoutLastNode;
	while (1) {
		FD_ZERO (&readSet);
		FD_SET(pg,&readSet);
		FD_SET(rt,&readSet);
		int maxfd = MAX(pg,rt) ;
		if(isListeninngSocketCreated) {
			FD_SET(multicastListeningSocket,&readSet);
			maxfd = MAX(maxfd,multicastListeningSocket);
		}
		maxfd +=1;
		if((returnvalue = select(maxfd,&readSet,NULL,NULL,tv))<0) {
			if( errno == EINTR){
				continue;
			}
			else {
				perror("Tour.c : Select Failed :");
			}
		}
		if(ISLASTNODEANDWAITED) {
			printf("Timed out \n");
			sendMultiCastMessage(multicastSendingSocket,MULTICAST_MESSAGE_INIT);
			break;

		}
		if(returnvalue == 0) {
			sendIcmpMessages();
			tv->tv_sec = 1;
			tv->tv_usec = 0;
		}
		if(FD_ISSET(pg,&readSet)) {
			recvandPrintIcmpMessage(pg);
		}
		if(FD_ISSET(rt,&readSet)) {
			char* message = recv_packet(rt);
			//TO DO : Check IDENTIFICATION NUMBER AND PRINT MESSAGE
			int isMyPacket;
			tourInfo ti = breakTourPayload(message, &isMyPacket);
			if(isMyPacket) {
				if(!isAlreadyNeighbour(ti)){
					addNeighbours(ti);
					if(!isListeninngSocketCreated ) {
						multicastListeningSocket =createMultiCastListeningsocket();
						isListeninngSocketCreated = TRUE;
					}

					printneighbours();
				}
				if(tv == NULL ) {
					tv = &pTV;
				}
				if(isLastNode(ti) ) {
					malarm(5000);
				}
				else {
					forwardTourIPPacket(rt, ti);
				}
			}

		}
		if (isListeninngSocketCreated && FD_ISSET(multicastListeningSocket,&readSet)) {
			printf("Multicast Socket set \n");
			break;
		}
	}

	if(multicastListeningSocket != MULTICAST_NOT_SET) {
		handleMulticasting( multicastListeningSocket,multicastSendingSocket);
	}

}
