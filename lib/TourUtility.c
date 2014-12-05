#include "TourUtility.h"

char** allocateINETADDRMemory(int count) {
	int i;
	char ** tourArray;
	tourArray = (char **)allocate_void(count *sizeof(char*));
	for( i=0; i<count;i++) {
		tourArray[i] = allocate_strmem(INET_ADDRSTRLEN);
	}
	return tourArray;
}



tourInfo contstructIntTourPacket(int argc ,char *argv[]) {
	int i;
	char hostname[1024];
	tourInfo ti;
	ti.count = argc;
	ti.tourAddresses = allocateINETADDRMemory(ti.count);
	ti.currentPosition = 0;
	strncpy(ti.multicastAddress, MULTICASTADDR, INET_ADDRSTRLEN);
	ti.multicastPort = MULTICASTPORT;
	char localAddress[INET_ADDRSTRLEN];
	populateLocalAddress(localAddress);
	strncpy(ti.tourAddresses[0],localAddress, INET_ADDRSTRLEN);
	for(i=1; i<argc;i++) {
		char currIpAddress[INET_ADDRSTRLEN];
		getIpAddressFromDomainName(argv[i],currIpAddress);
		strncpy(ti.tourAddresses[i],currIpAddress, INET_ADDRSTRLEN);
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
	strncat(tourPayload,currentPositionString,4);
	strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	for(i=0;i<ti.count;i++) {
		strncat(tourPayload,ti.tourAddresses[i],INET_ADDRSTRLEN);
		strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	}
	strncat(tourPayload,ti.multicastAddress,INET_ADDRSTRLEN);
	strncat(tourPayload, DELIMITER, sizeof(DELIMITER));
	strncat(tourPayload,multicastPortString,4);
	printf("Tour Payload is %s \n", tourPayload);
	return tourPayload;
}

tourInfo breakTourPayload(char *packetMessage, int* isMyPacket) {
	struct ip  *ipHdr = (struct ip *)packetMessage;
	if(ipHdr->ip_id==IP_IDENTIFICATION) {
		*isMyPacket =TRUE;
	}
	else  {
		*isMyPacket =FALSE;
	}
	packetMessage = packetMessage+sizeof(struct iphdr);
	tourInfo ti;
	char PacketToken[TOUR_PACKET_LENGTH];
	memset(PacketToken,'\0',FRAME_LENGTH);
	strncpy(PacketToken,packetMessage, strlen(packetMessage));
	ti.count= atoi(strtok(PacketToken, DELIMETER));
	ti.currentPosition = atoi(strtok(NULL, DELIMETER));
	ti.currentPosition  += 1;
	ti.tourAddresses = allocateINETADDRMemory(ti.count);
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
	struct ip ipHdr2;
	int status;
	ipHdr = (struct ip *)Message;
	ipHdr->ip_v = IPVERSION;
	ipHdr->ip_hl = sizeof(struct iphdr)>>2;
	ipHdr->ip_ttl = 255;
	ipHdr->ip_tos = 0;
	ipHdr->ip_sum = 0;

	if ((status = inet_pton (AF_INET, destAddr, &ipHdr->ip_dst)) != 1) {
		perror("TourUtility.C destination address conversion failed");
		exit (EXIT_FAILURE);
	}

	if (( status = inet_pton (AF_INET, getEth0IpAddress(), &ipHdr->ip_src)) != 1) {
		perror("TourUtility.C source address conversion failed");
		exit (EXIT_FAILURE);
	}
	char destIpAddress[INET_ADDRSTRLEN];
	char sourceIpAddress[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &(ipHdr->ip_dst), destIpAddress, INET_ADDRSTRLEN);
	inet_ntop(AF_INET, &(ipHdr->ip_src), sourceIpAddress, INET_ADDRSTRLEN);
	printf("IP Packet : source : %s, destination : %s, ", sourceIpAddress,destIpAddress);
	ipHdr->ip_p = IP_PROTOCOL;
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
	buildTourIPMessage(tourPayload, ti.tourAddresses[ti.currentPosition +1], ipPacket);
	free(tourPayload);
	send_packet(rt, ipPacket);
	free(ipPacket);
}

void printTourUtility (tourInfo ti) {
	printf("Count : %d \t ",ti.count);
	printf("Cp: %d \t ",ti.currentPosition);
	printf("MA: %s \t ",ti.multicastAddress);
	printf("Mp: %d \n ",ti.multicastPort);
	int i;
	for(i=0;i<ti.count;i++) {
		printf ("%s \t", ti.tourAddresses[i]);
	}
}



void initateTour(int rt,int argc,char *argv[]) {
	tourInfo startTI = contstructIntTourPacket(argc,argv);
	printf("TourUtiltiy.c :TourInfo in initate TOur");
	printTourUtility(startTI);
	char *tourPayload =buildTourPayload(startTI);
	char* ipPacket= allocate_strmem(MTU);
	buildTourIPMessage( tourPayload, startTI.tourAddresses[startTI.currentPosition +1], ipPacket);
	free(tourPayload );
	send_packet(rt,ipPacket);
	free(ipPacket);
}

