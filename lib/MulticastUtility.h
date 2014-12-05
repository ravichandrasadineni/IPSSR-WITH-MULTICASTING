/*
 * MulticastUtility.h
 *
 *  Created on: Dec 4, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_MULTICASTUTILITY_H_
#define LIB_MULTICASTUTILITY_H_
#include "Constants.h"
#include "unp.h"
#include "MemoryAllocator.h"
#include "TourSocketUtility.h"
int createMultiCastListeningsocket();
int  createSendingSocket();
int createListeningsocket();
void recvAndReplyMulticastMessage(int recvsockfd, int sendSockfd);
void handleMulticasting(int listeningSocket, int readSocket) ;


#endif /* LIB_MULTICASTUTILITY_H_ */
