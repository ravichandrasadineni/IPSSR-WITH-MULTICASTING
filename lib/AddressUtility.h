/*
 * AddressUtility.h
 *
 *  Created on: Nov 29, 2014
 *      Author: harsha
 */

#ifndef LIB_ADDRESSUTILITY_H_
#define LIB_ADDRESSUTILITY_H_

#include "unp.h"
#include <stdio.h>
#include "GenericUtility.h"

void getIpAddressFromDomainName(char* string, char* ipAddress) ;
void populateLocalAddress(char localAddress[INET_ADDRSTRLEN]);
void getIPAddress(u_int32_t *ipAddress);

#endif /* LIB_ADDRESSUTILITY_H_ */
