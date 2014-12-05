/*
 * PacketSendRecvUtility.h
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */

#ifndef LIB_PACKETSENDRECVUTILITY_H_
#define LIB_PACKETSENDRECVUTILITY_H_
#include "Constants.h"
#include <stdlib.h>
#include <stdio.h>
#include<netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "MemoryAllocator.h"

char* recv_packet(int recvfd);
void send_packet(int sendfd, char* sendBuff);
#endif /* LIB_PACKETSENDRECVUTILITY_H_ */
