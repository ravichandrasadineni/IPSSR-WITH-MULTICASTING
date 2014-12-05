/*
 * GenericUtility.h
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_GENERICUTILITY_H_
#define LIB_GENERICUTILITY_H_
#include "unp.h"
#include "Constants.h"
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include "Asgn3_code/hw_addrs.h"
int getEth0Index();
int isEth0(char* name);
int isSameMac(char mac1[HADDR_LEN], char mac2[HADDR_LEN]);
void printMacAddress (char haddr[HADDR_LEN]);
int isSameIP(char IpAddr1[INET_ADDRSTRLEN], char IpAddr2[INET_ADDRSTRLEN]);
int getSaddr(u_int8_t ipAddr[4]);
void setARPIPBlock(struct in_addr sAddr, u_int8_t ipAddr[4]);
void intTochar( int number, char* string);
char* getIpAddStr_ARPIPFMT(u_int8_t ipAddr[4]);
#endif /* LIB_GENERICUTILITY_H_ */
