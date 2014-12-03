/*
 * ARP.c
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */


#include "lib/ARPAPI.h"
#include "lib/ARPSocketUtility.h"
#include "lib/ARPUDSUtility.h"
#include "lib/ArpCache.h"
#include "lib/ARPUtility.h"
#include "lib/FrameSendRecvUtility.h"


int main(int argc, char *argv) {
	initializeList();
	int pfPacketSocket = createAndBindSocketsPF_PACKETSOCKET();
	int udsSocket = getARPBindedAndListeningsocket();
	int maxfd=0;
	fd_set readSet;
	FD_ZERO (&readSet);
	maxfd = MAX(udsSocket,pfPacketSocket) + 1;
	FD_SET(pfPacketSocket,&readSet);

	FD_SET(udsSocket,&readSet);
	while(1) {
		if((select(maxfd,&readSet,NULL,NULL,NULL))<0) {
			perror("ARPAPI.c : Select in the client Failed :");
		}
		if (FD_ISSET(udsSocket,&readSet)) {
			int newSocket = getConnectedUDSSocket(udsSocket);
			addtoOpenSocketList(newSocket);
		}
		else if (FD_ISSET(pfPacketSocket,&readSet )) {
			char frame[FRAME_LENGTH];
			recv_rawpacket(pfPacketSocket, frame);
			arp_hdr arpHeader = breakFrame(frame);
			if(isMyPacket(arpHeader) && isDestinedToMe(arpHeader)) {
				printf(" \n\nRecieved ARP Frame\n");
				printFrame(frame);
				if(isQuery(arpHeader)) {
					char* frame =buildReply(arpHeader);
					printf(" \n\Sending ARP Frame\n");
					printFrame(frame);
					send_rawpacket(pfPacketSocket,frame);
					addorUpdateCacheEntry(arpHeader);
					free(frame);
				}
				else if (isReply(arpHeader)) {
					addorUpdateCacheEntry(arpHeader);
					ARPDetails newEntry  = getARPCacheEntry(getIpAddStr_ARPIPFMT(arpHeader.sender_ip));
					int relatedSock = newEntry.udsSocket;
					if(relatedSock == ARP_NO_UDS_SOCKET) {
					}
					else {
						char* marshellMessage = marshallMessage(newEntry.IP_address,newEntry.HW_address);
						sendUDSMessage(relatedSock, marshellMessage);
						purgeEntry(relatedSock);
						deleteFromOpenSocketList(relatedSock);
						close(relatedSock);
						free(marshellMessage);
					}
				}
			}
			else if (isMyPacket(arpHeader) && doesEntryExist(arpHeader.sender_ip)) {
				addorUpdateCacheEntry(arpHeader);
			}
		}
		else {
			int setSocket = getSetSocket(&readSet);
			char buff[UDS_PACKET_MAX_LEN];
			if(recvUDSMessage( setSocket, buff)==0) {
				purgeEntry(setSocket);
				deleteFromOpenSocketList(setSocket);
				close(setSocket);
			}
			else {
				ARPDetails newEntry;
				unMarshallMessage(buff,newEntry.IP_address,newEntry.HW_address);
				if(doesEntryExistForIpString(newEntry.IP_address)) {
					newEntry  = getARPCacheEntry(newEntry.IP_address);
					char* marshellMessage = marshallMessage(newEntry.IP_address,newEntry.HW_address);
					sendUDSMessage(setSocket, marshellMessage);
					free(marshellMessage);
					purgeEntry(setSocket);
					deleteFromOpenSocketList(setSocket);
					close(setSocket);
				} else {
					newEntry.sll_hatype=ETHERNET;
					newEntry.sll_ifindex=getEth0Index();
					newEntry.udsSocket = setSocket;
					addEntry(newEntry);
					char localMacAddress[HADDR_LEN];
					char localIpAddress[INET_ADDRSTRLEN];
					populateLocalIpAddress(localIpAddress);
					populateLocalMacAddress(localMacAddress);
					char* frame = buildRequest(localMacAddress, localIpAddress,newEntry.IP_address,newEntry);
					printf("\n\nSending ARP Frame \n");
					printFrame(frame);
					send_rawpacket(pfPacketSocket,frame);
				}

			}
		}
		FD_ZERO (&readSet);
		setReadSetForOpenSockets(&readSet,&maxfd);
		FD_SET(pfPacketSocket,&readSet);
		maxfd  = MAX(maxfd, pfPacketSocket);
		FD_SET(udsSocket,&readSet);
		maxfd  = MAX(maxfd, udsSocket);
		maxfd = maxfd +1;
	}

}
