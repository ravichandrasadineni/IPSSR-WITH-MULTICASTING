/*
 * FrameSendRecvUtility.h
 *
 *  Created on: Nov 29, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_FRAMESENDRECVUTILITY_H_
#define LIB_FRAMESENDRECVUTILITY_H_

#include "unp.h"
#include "Constants.h"

void send_rawpacket (int raswSock, unsigned char * frame);

int recv_rawpacket(int rawsock, unsigned char *pkt);




#endif /* LIB_FRAMESENDRECVUTILITY_H_ */
