/*
 * TourSocketUtility.h
 *
 *  Created on: Dec 3, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_TOURSOCKETUTILITY_H_
#define LIB_TOURSOCKETUTILITY_H_

#include "unp.h"
#include"Constants.h"
#include <linux/if_ether.h>
#include "Asgn3_code/hw_addrs.h"

int createICMPSocket();
int getEth0Index();
void populateEth0Mac(char macAddress[HADDR_LEN]);
int createTourSocket();
int createPFPacketSocket() ;
char* getEth0IpAddress();
void bindPfPacketSocket(int sockfd, int interfaceIndex) ;


#endif /* LIB_TOURSOCKETUTILITY_H_ */
