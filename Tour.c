/*
 * Tour.c
 *
 *  Created on: Nov 28, 2014
 *      Author: harsha
 */
#include "lib/TourUtility.h"
#include "lib/Constants.h"
#include "lib/MemoryAllocator.h"
#include "lib/TourSocketUtility.h"

int main(int argc, char* argv[]){
	int i, on=1, rt, pg, includeHeader = 1, donotincludeHeader = 0;
	int multicastListeningSocket = MULTICAST_NOT_SET;
	int multicastSendingSocket = createSendingSocket();
	char Payload[MTU];
	char *recvBuffer, sendBuffer[MTU];
	memset(Payload,'\0',MTU);
	pg = createICMPSocket();
	rt = createTourSocket();
	struct timeval* tv = NULL;
	if(argc >= 2) {
		initateTour(rt,argc,argv);
		multicastListeningSocket =createMultiCastListeningsocket();
	}
	fd_set readSet;
	FD_ZERO (&readSet);
	int maxfd = MAX(pg,rt) + 1;
	FD_SET(pg,&readSet);
	FD_SET(rt,&readSet);
	if(argc>=2) {
		FD_SET(multicastListeningSocket,&readSet);
	}
	int returnvalue;
	while (1) {
		if((returnvalue = select(maxfd,&readSet,NULL,NULL,tv))<0) {
			perror("Tour.c : Select Failed :");
		}
		if(returnvalue == 0) {
			sendIcmpMessages();

		}
		if(FD_ISSET(pg,&readSet)) {
			recvandPrintIcmpMessage(pg);
		}
		if(FD_ISSET(rt,&readSet)) {
			char* message = recv_packet(rt);
			tourInfo ti = breakTourPayload(message);
			if(isLastNode(ti) ) {
				if(isVisited(ti)){
					//Send Multicast message
					sendMultiCastMessage(multicastListeningSocket);
				}
				else{
					//join Multicast group
					multicastListeningSocket = createMultiCastListeningsocket();
					//send ping message to source node
					sendIcmpMessages();
					//Send Multicast message
					sendMultiCastMessage(multicastListeningSocket);
					//Add source to Visite (Not needed)
					addsourcetoVisited(ti);
				}

			} else {//Not last node
				if(isVisited(ti)){
					//forward message
					forwardTourIPPacket(rt, ti);
				}
				else{
					//Join Multicast group
					multicastListeningSocket = createMultiCastListeningsocket();
					//send ping message to source node
					sendIcmpMessages();
					//Add source address to isVisited
					addsourcetoVisited(ti);
					//forward message
					forwardTourIPPacket(rt, ti);

				}

			}
		}
		if(multicastListeningSocket != MULTICAST_NOT_SET) {
			if(FD_ISSET(multicastListeningSocket,&readSet)){
				recvAndReplyMulticastMessage(multicastSendingSocket, multicastListeningSocket);
			}
		}
	}
}
