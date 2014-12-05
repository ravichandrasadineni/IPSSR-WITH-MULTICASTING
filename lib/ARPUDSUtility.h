/*
 * UDSUtility.h
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_ARPUDSUTILITY_H_
#define LIB_ARPUDSUTILITY_H_
#include "Constants.h"
#include "unp.h"
#include <net/ethernet.h>

int getConnectedUDSSocket(int sockFd);
int recvUDSMessage(int sockFd, char * buff);
void sendUDSMessage(int sockFd, char* buff);
void printUdsPacket(char *packet);
#endif /* LIB_ARPUDSUTILITY_H_ */
