################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/tcpcliserv/sigchldwait.c \
../unpv13e/tcpcliserv/sigchldwaitpid.c \
../unpv13e/tcpcliserv/str_cli08.c \
../unpv13e/tcpcliserv/str_cli09.c \
../unpv13e/tcpcliserv/str_cli11.c \
../unpv13e/tcpcliserv/str_echo08.c \
../unpv13e/tcpcliserv/str_echo09.c \
../unpv13e/tcpcliserv/tcpcli01.c \
../unpv13e/tcpcliserv/tcpcli04.c \
../unpv13e/tcpcliserv/tcpcli05.c \
../unpv13e/tcpcliserv/tcpcli06.c \
../unpv13e/tcpcliserv/tcpcli07.c \
../unpv13e/tcpcliserv/tcpcli08.c \
../unpv13e/tcpcliserv/tcpcli09.c \
../unpv13e/tcpcliserv/tcpcli10.c \
../unpv13e/tcpcliserv/tcpcli11.c \
../unpv13e/tcpcliserv/tcpserv01.c \
../unpv13e/tcpcliserv/tcpserv02.c \
../unpv13e/tcpcliserv/tcpserv03.c \
../unpv13e/tcpcliserv/tcpserv04.c \
../unpv13e/tcpcliserv/tcpserv08.c \
../unpv13e/tcpcliserv/tcpserv09.c \
../unpv13e/tcpcliserv/tcpservpoll01.c \
../unpv13e/tcpcliserv/tcpservselect01.c \
../unpv13e/tcpcliserv/tsigpipe.c 

OBJS += \
./unpv13e/tcpcliserv/sigchldwait.o \
./unpv13e/tcpcliserv/sigchldwaitpid.o \
./unpv13e/tcpcliserv/str_cli08.o \
./unpv13e/tcpcliserv/str_cli09.o \
./unpv13e/tcpcliserv/str_cli11.o \
./unpv13e/tcpcliserv/str_echo08.o \
./unpv13e/tcpcliserv/str_echo09.o \
./unpv13e/tcpcliserv/tcpcli01.o \
./unpv13e/tcpcliserv/tcpcli04.o \
./unpv13e/tcpcliserv/tcpcli05.o \
./unpv13e/tcpcliserv/tcpcli06.o \
./unpv13e/tcpcliserv/tcpcli07.o \
./unpv13e/tcpcliserv/tcpcli08.o \
./unpv13e/tcpcliserv/tcpcli09.o \
./unpv13e/tcpcliserv/tcpcli10.o \
./unpv13e/tcpcliserv/tcpcli11.o \
./unpv13e/tcpcliserv/tcpserv01.o \
./unpv13e/tcpcliserv/tcpserv02.o \
./unpv13e/tcpcliserv/tcpserv03.o \
./unpv13e/tcpcliserv/tcpserv04.o \
./unpv13e/tcpcliserv/tcpserv08.o \
./unpv13e/tcpcliserv/tcpserv09.o \
./unpv13e/tcpcliserv/tcpservpoll01.o \
./unpv13e/tcpcliserv/tcpservselect01.o \
./unpv13e/tcpcliserv/tsigpipe.o 

C_DEPS += \
./unpv13e/tcpcliserv/sigchldwait.d \
./unpv13e/tcpcliserv/sigchldwaitpid.d \
./unpv13e/tcpcliserv/str_cli08.d \
./unpv13e/tcpcliserv/str_cli09.d \
./unpv13e/tcpcliserv/str_cli11.d \
./unpv13e/tcpcliserv/str_echo08.d \
./unpv13e/tcpcliserv/str_echo09.d \
./unpv13e/tcpcliserv/tcpcli01.d \
./unpv13e/tcpcliserv/tcpcli04.d \
./unpv13e/tcpcliserv/tcpcli05.d \
./unpv13e/tcpcliserv/tcpcli06.d \
./unpv13e/tcpcliserv/tcpcli07.d \
./unpv13e/tcpcliserv/tcpcli08.d \
./unpv13e/tcpcliserv/tcpcli09.d \
./unpv13e/tcpcliserv/tcpcli10.d \
./unpv13e/tcpcliserv/tcpcli11.d \
./unpv13e/tcpcliserv/tcpserv01.d \
./unpv13e/tcpcliserv/tcpserv02.d \
./unpv13e/tcpcliserv/tcpserv03.d \
./unpv13e/tcpcliserv/tcpserv04.d \
./unpv13e/tcpcliserv/tcpserv08.d \
./unpv13e/tcpcliserv/tcpserv09.d \
./unpv13e/tcpcliserv/tcpservpoll01.d \
./unpv13e/tcpcliserv/tcpservselect01.d \
./unpv13e/tcpcliserv/tsigpipe.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/tcpcliserv/%.o: ../unpv13e/tcpcliserv/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


