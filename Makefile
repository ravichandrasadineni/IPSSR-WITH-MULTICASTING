
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
	
FLAGS = -g -O0

CFLAGS = ${FLAGS} -I unpv13e/lib
all:rsadineni_arp 
OBJECTS= GenericUtility.o ARPSocketUtility.o  MemoryAllocator.o  ARPUtility.o get_hw_addrs.o ARPUDSUtility.o


rsadineni_arp: ARP.o $(OBJECTS)
	${CC} ${FLAGS} -o rsadineni_arp ARP.o $(OBJECTS) ${LIBS}

GenericUtility.o: lib/GenericUtility.c
	${CC} ${CFLAGS} -c lib/GenericUtility.c

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


clean:
	rm   rsadineni_arp ARP.o $(OBJECTS)

