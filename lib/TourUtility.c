#include "TourUtility.h"

Visited *head = NULL;
Visited *tail = NULL;

Visited alreadyVisited;

tourInfo contstructIntTourPacket(int argc ,char *argv[]) {
	int i;
	char hostname[1024];
	tourInfo ti;
	ti.count = argc;
	ti.tourAddresses = (char* [INET_ADDRSTRLEN])allocate_strmem(ti.count *INET_ADDRSTRLEN);
	ti.currentPosition = 0;
	strncpy(ti.multicastAddress, MULTICASTADDR, INET_ADDRSTRLEN);
	intTochar(ti.multicastPort, MULTICASTPORT);
	if (gethostname(hostname, 1023) < 0){
		perror("TourUtility.c : gethostname failed :");
		exit(0);
	}
	strncpy(ti.tourAddresses[0],hostname, INET_ADDRSTRLEN);
	for(i=1; i<argc;i++) {
		strncpy(ti.tourAddresses[i],argv[i], INET_ADDRSTRLEN);
	}
	return ti;
}



char* buildTourPayload(tourInfo ti) {
	int i;
	char countString[4];
	char *tourPayload = allocate_strmem(TOUR_PACKET_LENGTH);
	char currentPositionString[4];
	char multicastPortString[4];
	intTochar(ti.count,countString);
	intTochar(ti.currentPosition,currentPositionString);
	intTochar(ti.multicastPort,multicastPortString);
	memset(tourPayload, '\0',TOUR_PACKET_LENGTH);
	strncpy(tourPayload,countString,4);
	strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	strncpy(tourPayload,currentPositionString,4);
	strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	for(i=0;i<ti.count;i++) {
		strncpy(tourPayload,ti.tourAddresses[i],INET_ADDRSTRLEN);
		strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	}
	strncpy(tourPayload,ti.multicastAddress,INET_ADDRSTRLEN);
	strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	strncpy(tourPayload,multicastPortString,4);
	return tourPayload;
}

tourInfo breakTourPayload(char *packetMessage) {
	struct ip  *ipHdr = (struct ip *)packetMessage;
	packetMessage = packetMessage+sizeof(struct iphdr);
	tourInfo ti;
	char PacketToken[TOUR_PACKET_LENGTH];
	memset(PacketToken,'\0',FRAME_LENGTH);
	strncpy(PacketToken,packetMessage, strlen(packetMessage));
	ti.count= atoi(strtok(PacketToken, DELIMETER));
	ti.currentPosition = atoi(strtok(NULL, DELIMETER));
	ti.currentPosition  += 1;
	ti.tourAddresses = (char* [INET_ADDRSTRLEN])allocate_strmem(ti.count *INET_ADDRSTRLEN);
	int i;
	for(i=0; i<ti.count;i++) {
		strncpy(ti.tourAddresses[i],strtok(PacketToken, DELIMETER), INET_ADDRSTRLEN);
	}
	strncpy(ti.multicastAddress,strtok(PacketToken, DELIMETER), INET_ADDRSTRLEN);
	ti.multicastPort = atoi(strtok(PacketToken,DELIMETER));
	return ti;
}

int isLastNode(tourInfo tI) {
	if(tI.currentPosition == (tI.count-1)) {
		return TRUE;
	}
	return FALSE;
}

void getsourceAddress(tourInfo ti, char sourceAddress[INET_ADDRSTRLEN]){
	int position = ti.count-1;
	strncpy(sourceAddress, ti.tourAddresses[position], INET_ADDRSTRLEN);
}

void addsourcetoVisited(tourInfo ti){
	int position = ti.count;
	char sourceAddr[INET_ADDRSTRLEN];
	getsourceAddress(ti, sourceAddr);
	Visited *tmp = tail;
	Visited *newNode=malloc(sizeof(Visited));
	strncpy(newNode->sourceAddress, sourceAddr, INET_ADDRSTRLEN);
	newNode->next=NULL;
	if(tmp == NULL)
	{
		tmp = newNode;
	}
	else
	{
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=newNode;
	}
}

int isVisited(tourInfo ti){
	Visited *tmp = head;
	char sourceAddr[INET_ADDRSTRLEN];
	getsourceAddress(ti, sourceAddr);
	if(tmp == NULL){
		return FALSE;
	}
	else{
		while(tmp != NULL){
			if(!strncmp(tmp->sourceAddress, sourceAddr, INET_ADDRSTRLEN)){
				return TRUE;
			}
			tmp = tmp->next;
		}
	}
	return FALSE;
}


uint16_t
ip_Checksum (uint16_t *addr, int len)
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


void buildTourIPMessage(char Payload[TOUR_PACKET_LENGTH], char destAddr[INET_ADDRSTRLEN], char* Message){
	struct ip *ipHdr;
	ipHdr = (struct ip *)Message;
	ipHdr->ip_v = IPVERSION;
	ipHdr->ip_hl = sizeof(struct iphdr)>>2;
	ipHdr->ip_ttl = 255;
	ipHdr->ip_tos = 0;
	ipHdr->ip_sum = 0;
	if (( inet_pton (AF_INET, getEth0IpAddress(), &(ipHdr->ip_src))) != 1) {
		perror("TourUtility.C source address conversion failed");
		exit (EXIT_FAILURE);
	}
	if (( inet_pton (AF_INET, destAddr, &(ipHdr->ip_dst))) != 1) {
		perror("TourUtility.C destination address conversion failed");
		exit (EXIT_FAILURE);
	}
	ipHdr->ip_p = htons(IP_PROTOCOL);
	ipHdr->ip_len = htons (IP4_HDRLEN + TOUR_PACKET_LENGTH);
	ipHdr->ip_id = htons(IP_IDENTIFICATION);
	ipHdr->ip_sum = 0;
	ipHdr->ip_sum = ip_Checksum((uint16_t *) ipHdr, IP4_HDRLEN);
	printf("The version is %d\thl is %d\ttos is %d\tcheck is %d\tproto is %d\tttl is %d\tid is %d\ttot_len is %d\n",ipHdr->ip_v,ipHdr->ip_hl,ipHdr->ip_tos,ipHdr->ip_sum,ipHdr->ip_p,ipHdr->ip_ttl,ipHdr->ip_id, ipHdr->ip_len);
	memcpy(Message+IP4_HDRLEN,Payload,TOUR_PACKET_LENGTH);
}


void forwardTourIPPacket(int rt, tourInfo ti){
	char *tourPayload = buildTourPayload(ti);
	char *ipPacket = allocate_strmem(MTU);
	buildTourIPMessage(tourPayload, ti.tourAddresses[ti.count], ipPacket);
	free(tourPayload);
	send_packet(rt, ipPacket);
	free(ipPacket);
}


void initateTour(int rt,int argc,char *argv[]) {
	tourInfo startTI = contstructIntTourPacket(argc,argv);
	char *tourPayload =buildTourPayload(startTI);
	char* ipPacket= allocate_strmem(MTU);
	buildTourIPMessage( tourPayload, startTI.tourAddresses[1], ipPacket);
	free(tourPayload );
	send_packet(rt,ipPacket);
	free(ipPacket);
}
