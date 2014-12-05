
# This is a sample Makefile which compiles source files named:
# - tcpechotimeserv.c
# - tcpechotimecli.c
# - time_cli.c
# - echo_cli.c
# and creating executables: "server", "client", "time_cli"
# and "echo_cli", respectively.
#
# It uses various standard libraries, and the copy of Stevens'
# library "libunp.a" in ~cse533/Stevens/unpv13e_solaris2.10 .
#
# It also picks up the thread-safe version of "readline.c"
# from Stevens' directory "threads" and uses it when building
# the executable "server".
#
# It is set up, for illustrative purposes, to enable you to use
# the Stevens code in the ~cse533/Stevens/unpv13e_solaris2.10/lib
# subdirectory (where, for example, the file "unp.h" is located)
# without your needing to maintain your own, local copies of that
# code, and without your needing to include such code in the
# submissions of your assignments.
#
# Modify it as needed, and include it with your submission.

CC = gcc

LIBS = -lresolv -lnsl -pthread -lm unpv13e/libunp.a
	
FLAGS = -g -O0 -fno-stack-protector 

CFLAGS = ${FLAGS} -I unpv13e/lib

all:rsadineni_arp  rsadineni_Tour
OBJECTS= GenericUtility.o ARPSocketUtility.o  MemoryAllocator.o  ARPUtility.o get_hw_addrs.o ARPUDSUtility.o AddressUtility.o FrameSendRecvUtility.o ARPAPI.o ArpCache.o PacketSendRecvUtility.o TourUtility.o TourSocketUtility.o ICMPUtility.o MulticastUtility.o


rsadineni_Tour: Tour.o ${OBJECTS}
	${CC} ${FLAGS} -o rsadineni_Tour Tour.o ${OBJECTS} ${LIBS}

rsadineni_arp: ARP.o $(OBJECTS)
	${CC} ${FLAGS} -o rsadineni_arp ARP.o $(OBJECTS) ${LIBS}
	

test: test.o $(OBJECTS)
	${CC} ${FLAGS} -o test test.o $(OBJECTS) ${LIBS}

test.o: test.c
	${CC} ${CFLAGS} -c test.c


GenericUtility.o: lib/GenericUtility.c
	${CC} ${CFLAGS} -c lib/GenericUtility.c

ARPAPI.o: lib/ARPAPI.c
	${CC} ${CFLAGS} -c lib/ARPAPI.c


ArpCache.o: lib/ArpCache.c
	${CC} ${CFLAGS} -c lib/ArpCache.c

FrameSendRecvUtility.o: lib/FrameSendRecvUtility.c
	${CC} ${CFLAGS} -c lib/FrameSendRecvUtility.c


ARPSocketUtility.o: lib/ARPSocketUtility.c
	${CC} ${CFLAGS} -c lib/ARPSocketUtility.c

ARPUtility.o: lib/ARPUtility.c
	${CC} ${CFLAGS} -c lib/ARPUtility.c

MemoryAllocator.o: lib/MemoryAllocator.c
	${CC} ${CFLAGS} -c lib/MemoryAllocator.c

get_hw_addrs.o: lib/Asgn3_code/get_hw_addrs.c
	${CC} ${CFLAGS} -c lib/Asgn3_code/get_hw_addrs.c
	
ARPUDSUtility.o: lib/ARPUDSUtility.c
	${CC} ${CFLAGS} -c lib/ARPUDSUtility.c

TourSocketUtility.o: lib/TourSocketUtility.c
	${CC} ${CFLAGS} -c lib/TourSocketUtility.c

TourUtility.o: lib/TourUtility.c
	${CC} ${CFLAGS} -c lib/TourUtility.c
	
MulticastUtility.o: lib/MulticastUtility.c
	${CC} ${CFLAGS} -c lib/MulticastUtility.c
	
ICMPUtility.o: lib/ICMPUtility.c
	${CC} ${CFLAGS} -c lib/ICMPUtility.c

PacketSendRecvUtility.o: lib/PacketSendRecvUtility.c
	${CC} ${CFLAGS} -c lib/PacketSendRecvUtility.c

AddressUtility.o: lib/AddressUtility.c
	${CC} ${CFLAGS} -c lib/AddressUtility.c

clean:
	rm   rsadineni_arp rsadineni_Tour ARP.o $(OBJECTS)

