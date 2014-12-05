################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/oob/heartbeatcli.c \
../unpv13e/oob/heartbeatserv.c \
../unpv13e/oob/sigchldwaitpid.c \
../unpv13e/oob/strcliselect02.c \
../unpv13e/oob/strecho02.c \
../unpv13e/oob/tcpcli02.c \
../unpv13e/oob/tcprecv01.c \
../unpv13e/oob/tcprecv02.c \
../unpv13e/oob/tcprecv03.c \
../unpv13e/oob/tcprecv03p.c \
../unpv13e/oob/tcprecv04.c \
../unpv13e/oob/tcprecv05.c \
../unpv13e/oob/tcprecv06.c \
../unpv13e/oob/tcpsend01.c \
../unpv13e/oob/tcpsend02.c \
../unpv13e/oob/tcpsend03.c \
../unpv13e/oob/tcpsend04.c \
../unpv13e/oob/tcpsend05.c \
../unpv13e/oob/tcpsend06.c \
../unpv13e/oob/tcpserv02.c 

OBJS += \
./unpv13e/oob/heartbeatcli.o \
./unpv13e/oob/heartbeatserv.o \
./unpv13e/oob/sigchldwaitpid.o \
./unpv13e/oob/strcliselect02.o \
./unpv13e/oob/strecho02.o \
./unpv13e/oob/tcpcli02.o \
./unpv13e/oob/tcprecv01.o \
./unpv13e/oob/tcprecv02.o \
./unpv13e/oob/tcprecv03.o \
./unpv13e/oob/tcprecv03p.o \
./unpv13e/oob/tcprecv04.o \
./unpv13e/oob/tcprecv05.o \
./unpv13e/oob/tcprecv06.o \
./unpv13e/oob/tcpsend01.o \
./unpv13e/oob/tcpsend02.o \
./unpv13e/oob/tcpsend03.o \
./unpv13e/oob/tcpsend04.o \
./unpv13e/oob/tcpsend05.o \
./unpv13e/oob/tcpsend06.o \
./unpv13e/oob/tcpserv02.o 

C_DEPS += \
./unpv13e/oob/heartbeatcli.d \
./unpv13e/oob/heartbeatserv.d \
./unpv13e/oob/sigchldwaitpid.d \
./unpv13e/oob/strcliselect02.d \
./unpv13e/oob/strecho02.d \
./unpv13e/oob/tcpcli02.d \
./unpv13e/oob/tcprecv01.d \
./unpv13e/oob/tcprecv02.d \
./unpv13e/oob/tcprecv03.d \
./unpv13e/oob/tcprecv03p.d \
./unpv13e/oob/tcprecv04.d \
./unpv13e/oob/tcprecv05.d \
./unpv13e/oob/tcprecv06.d \
./unpv13e/oob/tcpsend01.d \
./unpv13e/oob/tcpsend02.d \
./unpv13e/oob/tcpsend03.d \
./unpv13e/oob/tcpsend04.d \
./unpv13e/oob/tcpsend05.d \
./unpv13e/oob/tcpsend06.d \
./unpv13e/oob/tcpserv02.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/oob/%.o: ../unpv13e/oob/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


