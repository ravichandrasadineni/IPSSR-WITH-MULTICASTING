/*
 * ARP.h
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#ifndef ARPAPI_H_
#define ARPAPI_H_

#include "ARPUDSUtility.h"
#include"unp.h"
#include "Constants.h"
#include "ARPUtility.h"


int areq (struct sockaddr *IPaddr, socklen_t sockaddrlen, struct hwaddr *HWaddr);

#endif /* ARP_H_ */
