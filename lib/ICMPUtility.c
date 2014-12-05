/*
 * ICMPUtility.c
 *
 *  Created on: Dec 3, 2014
 *      Author: ravichandrasadineni
 */

#include "ICMPUtility.h"


neighbours *head = NULL;
neighbours *tail = NULL;

int nsent =0;

void tv_sub(struct timeval *out, struct timeval *in)
{
	if ( (out->tv_usec -= in->tv_usec) < 0) {	/* out -= in */
		--out->tv_sec;
		out->tv_usec += 1000000;
	}
	out->tv_sec -= in->tv_sec;
}



int isAlreadyNeighbour(char* sourceAddr){
	struct Visited *temp = head;
	if(temp == NULL){
		return FALSE;
	}
	while(temp != NULL){
		if(!strncmp(temp->ipAddress, sourceAddr, INET_ADDRSTRLEN)){
			return TRUE;
			break;
		}
		temp = temp->next;
	}
	return FALSE;
}


void addNeighbours(char* sourceAddr){
	if(isAlreadyVisited(sourceAddr)) {
		return;
	}
	if(head== NULL) {
		head = (neighbours*)allocate_void(sizeof(neighbours));
		tail = head;
	}
	else {
		tail->next = (neighbours*)allocate_void(sizeof(neighbours));
		tail = tail->next;
	}
	strncpy(tail->ipAddress,sourceAddr,INET_ADDRSTRLEN);
	tail->next=NULL;
}


uint16_t ipChecksum (uint16_t *addr, int len)
{
	int nleft = len;
	int sum = 0;
	uint16_t *w = addr;
	uint16_t answer = 0;

	while (nleft > 1) {
		sum += *w++;
		nleft -= sizeof (uint16_t);
	}

	if (nleft == 1) {
		*(uint8_t *) (&answer) = *(uint8_t *) w;
		sum += answer;
	}

	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}





uint16_t icmpv4_cksum(uint16_t *addr, int len)
{
	int				nleft = len;
	uint32_t		sum = 0;
	uint16_t		*w = addr;
	uint16_t		answer = 0;

	/*
	 * Our algorithm is simple, using a 32 bit accumulator (sum), we add
	 * sequential 16 bit words to it, and at the end, fold back all the
	 * carry bits from the top 16 bits into the lower 16 bits.
	 */
	while (nleft > 1)  {
		sum += *w++;
		nleft -= 2;
	}

	/* 4mop up an odd byte, if necessary */
	if (nleft == 1) {
		*(unsigned char *)(&answer) = *(unsigned char *)w ;
		sum += answer;
	}

	/* 4add back carry outs from top 16 bits to low 16 bits */
	sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
	sum += (sum >> 16);			/* add carry */
	answer = ~sum;				/* truncate to 16 bits */
	return(answer);
}


void buildIcmp(char *icmpString) {
	int			len;
	struct icmp	*icmp;
	icmp = (struct icmp *) sendbuf;
	icmp->icmp_type = ICMP_ECHO;
	icmp->icmp_code = 0;
	icmp->icmp_id = ICMPID;
	icmp->icmp_seq = nsent++;
	memset(icmp->icmp_data, 0xa5, DATA_LENGTH);	/* fill with pattern */
	Gettimeofday((struct timeval *) icmp->icmp_data, NULL);
	len = ICMP_HDRLEN + DATA_LENGTH;		/* checksum ICMP header and data */
	icmp->icmp_cksum = 0;
	icmp->icmp_cksum = icmpv4_cksum((u_short *) icmp, len);

}


void buildIP(char* ipString) {
	struct ip *iphdr;
	int ip_flags[4];
	iphdr = (iphdr*)ipString;
	iphdr->ip_hl = IP4_HDRLEN / sizeof (uint32_t);
	iphdr->ip_v = IPVERSION;
	iphdr->ip_tos = 0;
	iphdr->ip_len = htons (IP4_HDRLEN + ICMP_HDRLEN + DATA_LENGTH);
	iphdr->ip_id = htons (0);
	ip_flags[0] = 0;
	ip_flags[1] = 0;
	ip_flags[2] = 0;
	ip_flags[3] = 0;
	iphdr->ip_off = htons ((ip_flags[0] << 15)
			+ (ip_flags[1] << 14)
			+ (ip_flags[2] << 13)
			+  ip_flags[3]);
	iphdr->ip_ttl = htons(255);
	iphdr->ip_p = htons(IPPROTO_ICMP);
	if (( inet_pton (AF_INET, getEth0IpAddress(), &(iphdr->ip_src))) != 1) {
		perror("ICMPUTILITY.C source address conversion failed");
		exit (EXIT_FAILURE);
	}

	if (( inet_pton (AF_INET, ipString, &(iphdr->ip_dst))) != 1) {
		perror("ICMPUTILITY.C destination address conversion failed");
		exit (EXIT_FAILURE);
	}

	iphdr->ip_sum = 0;
	iphdr.ip_sum = ipChecksum((uint16_t *) iphdr, IP4_HDRLEN);
	buildIcmp(ipString+IPHEADER_LENGTH);
}


void sendIcmpMessages() {
	char * frame = (char *)allocate_void(MTU);
	struct ethhdr  *eth;
	eth = (struct ethhdr*)frame;
	eth->h_proto=(htons(ETH_P_IP));
	populateEth0Mac(eth->h_source);
	if(head == NULL) {
		printf("ICMPUtility.c Not tour packet has been received but asked to send ping. EXITING \n");
		return;
	}
	neighbours* currentPosition = head;
	while(currentPosition!=NULL) {
		hwaddr hardwareAddress;
		struct sockaddr_in ipAddress;
		inet_aton(currentPosition->ipAddress,&ipAddress.sin_addr);
		areq ((SA*)&ipAddress,sizeof(ipAddress) ,  &hardwareAddress);
		memcpy(eth->h_source,hardwareAddress.sll_addr,HADDR_LEN);
		buildIP(eth+1);
		int outgoingInf = getEth0Index();
		int socket = createPFPacketSocket();
		bindPfPacketSocket(socket,  outgoingInf);
		send_rawpacket(socket,frame);
		close(socket);
		free(frame);
	}
}


void procICMPv4(char *ptr )
{
	int				hlen1, icmplen;
	double			rtt;
	struct ip		*ip;
	struct icmp		*icmp;
	struct timeval	*tvsend;

	ip = (struct ip *) ptr;		/* start of IP header */
	hlen1 = ip->ip_hl << 2;		/* length of IP header */
	if (ip->ip_p != IPPROTO_ICMP)
		return;				/* not ICMP */

	if (icmp->icmp_type == ICMP_ECHOREPLY) {
		if (icmp->icmp_id != ICMPID)
			return;			/* not a response to our ECHO_REQUEST */
		if (icmplen < 16)
			return;			/* not enough data to use */
		struct timeval tvrecv;
		Gettimeofday(&tvrecv,NULL);
		tvsend = (struct timeval *) icmp->icmp_data;
		tv_sub(&tvrecv, tvsend);
		rtt = tvrecv.tv_sec * 1000.0 + tvrecv.tv_usec / 1000.0;

		printf("%d bytes from %s: seq=%u, ttl=%d, rtt=%.3f ms\n",
				icmplen, Sock_ntop_host(pr->sarecv, pr->salen),
				icmp->icmp_seq, ip->ip_ttl, rtt);

	} else if (verbose) {
		printf("  %d bytes from %s: type = %d, code = %d\n",
				icmplen, Sock_ntop_host(pr->sarecv, pr->salen),
				icmp->icmp_type, icmp->icmp_code);
	}
}




void recvandPrintIcmpMessage(int pg) {
	char * frame = recv_packet(pg);

	procICMPv4(frame);

}