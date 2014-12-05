################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/ipopts/dgechoprintroute.c \
../unpv13e/ipopts/sigchldwaitpid.c \
../unpv13e/ipopts/sourceroute.c \
../unpv13e/ipopts/sourceroute6.c \
../unpv13e/ipopts/tcpcli01.c \
../unpv13e/ipopts/tcpserv01.c \
../unpv13e/ipopts/udpcli01.c \
../unpv13e/ipopts/udpserv01.c 

OBJS += \
./unpv13e/ipopts/dgechoprintroute.o \
./unpv13e/ipopts/sigchldwaitpid.o \
./unpv13e/ipopts/sourceroute.o \
./unpv13e/ipopts/sourceroute6.o \
./unpv13e/ipopts/tcpcli01.o \
./unpv13e/ipopts/tcpserv01.o \
./unpv13e/ipopts/udpcli01.o \
./unpv13e/ipopts/udpserv01.o 

C_DEPS += \
./unpv13e/ipopts/dgechoprintroute.d \
./unpv13e/ipopts/sigchldwaitpid.d \
./unpv13e/ipopts/sourceroute.d \
./unpv13e/ipopts/sourceroute6.d \
./unpv13e/ipopts/tcpcli01.d \
./unpv13e/ipopts/tcpserv01.d \
./unpv13e/ipopts/udpcli01.d \
./unpv13e/ipopts/udpserv01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/ipopts/%.o: ../unpv13e/ipopts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


