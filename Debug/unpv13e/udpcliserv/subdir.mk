################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/udpcliserv/dgcliaddr.c \
../unpv13e/udpcliserv/dgclibig.c \
../unpv13e/udpcliserv/dgcliconnect.c \
../unpv13e/udpcliserv/dgcliinetaddr.c \
../unpv13e/udpcliserv/dgcliloop1.c \
../unpv13e/udpcliserv/dgcliloop3.c \
../unpv13e/udpcliserv/dgecholoop1.c \
../unpv13e/udpcliserv/dgecholoop2.c \
../unpv13e/udpcliserv/sigchldwaitpid.c \
../unpv13e/udpcliserv/udpcli01.c \
../unpv13e/udpcliserv/udpcli02.c \
../unpv13e/udpcliserv/udpcli03.c \
../unpv13e/udpcliserv/udpcli04.c \
../unpv13e/udpcliserv/udpcli05.c \
../unpv13e/udpcliserv/udpcli06.c \
../unpv13e/udpcliserv/udpcli08.c \
../unpv13e/udpcliserv/udpcli09.c \
../unpv13e/udpcliserv/udpcli10.c \
../unpv13e/udpcliserv/udpserv01.c \
../unpv13e/udpcliserv/udpserv06.c \
../unpv13e/udpcliserv/udpserv07.c \
../unpv13e/udpcliserv/udpservselect01.c 

OBJS += \
./unpv13e/udpcliserv/dgcliaddr.o \
./unpv13e/udpcliserv/dgclibig.o \
./unpv13e/udpcliserv/dgcliconnect.o \
./unpv13e/udpcliserv/dgcliinetaddr.o \
./unpv13e/udpcliserv/dgcliloop1.o \
./unpv13e/udpcliserv/dgcliloop3.o \
./unpv13e/udpcliserv/dgecholoop1.o \
./unpv13e/udpcliserv/dgecholoop2.o \
./unpv13e/udpcliserv/sigchldwaitpid.o \
./unpv13e/udpcliserv/udpcli01.o \
./unpv13e/udpcliserv/udpcli02.o \
./unpv13e/udpcliserv/udpcli03.o \
./unpv13e/udpcliserv/udpcli04.o \
./unpv13e/udpcliserv/udpcli05.o \
./unpv13e/udpcliserv/udpcli06.o \
./unpv13e/udpcliserv/udpcli08.o \
./unpv13e/udpcliserv/udpcli09.o \
./unpv13e/udpcliserv/udpcli10.o \
./unpv13e/udpcliserv/udpserv01.o \
./unpv13e/udpcliserv/udpserv06.o \
./unpv13e/udpcliserv/udpserv07.o \
./unpv13e/udpcliserv/udpservselect01.o 

C_DEPS += \
./unpv13e/udpcliserv/dgcliaddr.d \
./unpv13e/udpcliserv/dgclibig.d \
./unpv13e/udpcliserv/dgcliconnect.d \
./unpv13e/udpcliserv/dgcliinetaddr.d \
./unpv13e/udpcliserv/dgcliloop1.d \
./unpv13e/udpcliserv/dgcliloop3.d \
./unpv13e/udpcliserv/dgecholoop1.d \
./unpv13e/udpcliserv/dgecholoop2.d \
./unpv13e/udpcliserv/sigchldwaitpid.d \
./unpv13e/udpcliserv/udpcli01.d \
./unpv13e/udpcliserv/udpcli02.d \
./unpv13e/udpcliserv/udpcli03.d \
./unpv13e/udpcliserv/udpcli04.d \
./unpv13e/udpcliserv/udpcli05.d \
./unpv13e/udpcliserv/udpcli06.d \
./unpv13e/udpcliserv/udpcli08.d \
./unpv13e/udpcliserv/udpcli09.d \
./unpv13e/udpcliserv/udpcli10.d \
./unpv13e/udpcliserv/udpserv01.d \
./unpv13e/udpcliserv/udpserv06.d \
./unpv13e/udpcliserv/udpserv07.d \
./unpv13e/udpcliserv/udpservselect01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/udpcliserv/%.o: ../unpv13e/udpcliserv/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


