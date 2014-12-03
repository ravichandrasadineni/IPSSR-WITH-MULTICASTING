/*
 * Constants.h
 *
 *  Created on: Nov 28, 2014
 *      Author: ravichandrasadineni
 */

#ifndef LIB_CONSTANTS_H_
#define LIB_CONSTANTS_H_

#define ARP_CLIENT_PRE "/tmp/file-XXXXXX"
#define ARP_FILE_NAME "/tmp/rsadineni-ArpFile"
#define FILE_NAME_LENGTH 32
#define ARP_TIME_OUT_SECS 2
#define ARP_TIME_OUT_USECS 0
#define EXIT_MEM_FAILURE 2
#define OPEN_SOCKET_LIST_SIZE 10
#define HADDR_LEN 6
#define IPADDR_LEN 4
#define ETHERNET0 "eth0"
#define ETH_TYPE 4581
#define ARP_HDRLEN 28
#define ETH_TYPE_LEN 2
#define TRUE  1
#define FALSE  0
#define ETHERNET 1
#define INETP_LEN 4
#define ETHERNET_TYPE_LEN 1
#define ARP_NO_UDS_SOCKET -1
#define FRAME_BUFFER_LENGTH 1500

#define FRAME_LENGTH 1514
#define NUM_CONNECTIONS 20
#define DELIMETER "****"
#define ARP_ADV_NUM 1854
#define UDS_PACKET_MAX_LEN 100
static const char BRODCAST_MAC[HADDR_LEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

#define IP_FRAME_LENGTH 1514
#define DELIMITER ":::"
#define MULTICASTADDR "225.0.0.1"
#define MULTICASTPORT "1036"
#define TTL 1
#define IPPROTO_CONSTANT 127
#define PORT 1234
#define MTU 1536
#define IPHEADER_LENGTH 20
#define IP_IDENTIFICATION 20008
#define ICMP_PORT 1036
#define UPD_PORT 1045


#endif /* LIB_CONSTANTS_H_ */
