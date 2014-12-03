#include "unp.h"
#include "lib/ARPAPI.h"
#include "lib/Constants.h"
#include  "lib/GenericUtility.h"

int main(int argc, char*argv[]) {

	char ipAddress[16];
	strncpy(ipAddress,argv[1], 16);
	struct in_addr saddr;
	inet_aton(ipAddress,&saddr);
	struct sockaddr_in ipaddress;
	ipaddress.sin_addr = saddr;
	struct hwaddr HWaddr;
	areq ((SA*)&ipaddress, 16, &HWaddr);
	printMacAddress(HWaddr.sll_addr);



}
