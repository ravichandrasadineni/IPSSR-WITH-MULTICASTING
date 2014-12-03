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
#include <linux/if_ether.h>   // ETH_P_ARP = 0x0806
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <linux/if_arp.h>

int getConnectedUDSSocket(int sockFd);
int recvUDSMessage(int sockFd, char * buff);
void sendUDSMessage(int sockFd, char* buff);
void printUdsPacket(char *packet);
#endif /* LIB_ARPUDSUTILITY_H_ */
