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
#include "TourUtility.h"
#include <sys/types.h>
#include <sys/socket.h>
void recv_packet(int recvfd, char* readBuff, char *sourceAddr);
void send_packet(int sendfd, char* sendBuff, char destination[INET_ADDRSTRLEN]);
#endif /* LIB_PACKETSENDRECVUTILITY_H_ */
