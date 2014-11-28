/*
 * ARP.h
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#ifndef ARPAPI_H_
#define ARPAPI_H_

#include"unp.h"
#include "Constants.h"
#include "UDSUtility.h"


typedef struct hwaddr {
		     int             sll_ifindex;	 /* Interface number */
		     unsigned short  sll_hatype;	 /* Hardware type */
		     unsigned char   sll_halen;		 /* Length of address */
		     unsigned char   sll_addr[8];	 /* Physical layer address */
} arpstruct;

int areq (struct sockaddr *IPaddr, socklen_t sockaddrlen, struct hwaddr *HWaddr);

#endif /* ARP_H_ */
