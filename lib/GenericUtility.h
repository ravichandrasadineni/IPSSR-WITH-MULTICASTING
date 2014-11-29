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
int isSameMac(char mac1[HADDR_LEN], char mac2[HADDR_LEN]);
void printMacAddress (char haddr[HADDR_LEN]);
int isSameIP(char IpAddr1[INET_ADDRSTRLEN], char IpAddr2[INET_ADDRSTRLEN]);
#endif /* LIB_GENERICUTILITY_H_ */
