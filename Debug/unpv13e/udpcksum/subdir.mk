################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/udpcksum/cleanup.c \
../unpv13e/udpcksum/main.c \
../unpv13e/udpcksum/pcap.c \
../unpv13e/udpcksum/senddnsquery-libnet.c \
../unpv13e/udpcksum/senddnsquery-raw.c \
../unpv13e/udpcksum/udpcksum.c \
../unpv13e/udpcksum/udpread.c \
../unpv13e/udpcksum/udpwrite.c 

OBJS += \
./unpv13e/udpcksum/cleanup.o \
./unpv13e/udpcksum/main.o \
./unpv13e/udpcksum/pcap.o \
./unpv13e/udpcksum/senddnsquery-libnet.o \
./unpv13e/udpcksum/senddnsquery-raw.o \
./unpv13e/udpcksum/udpcksum.o \
./unpv13e/udpcksum/udpread.o \
./unpv13e/udpcksum/udpwrite.o 

C_DEPS += \
./unpv13e/udpcksum/cleanup.d \
./unpv13e/udpcksum/main.d \
./unpv13e/udpcksum/pcap.d \
./unpv13e/udpcksum/senddnsquery-libnet.d \
./unpv13e/udpcksum/senddnsquery-raw.d \
./unpv13e/udpcksum/udpcksum.d \
./unpv13e/udpcksum/udpread.d \
./unpv13e/udpcksum/udpwrite.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/udpcksum/%.o: ../unpv13e/udpcksum/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


