################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/ARPAPI.c \
../lib/ARPSocketUtility.c \
../lib/ARPUDSUtility.c \
../lib/ARPUtility.c \
../lib/AddressUtility.c \
../lib/ArpCache.c \
../lib/FrameSendRecvUtility.c \
../lib/GenericUtility.c \
../lib/MemoryAllocator.c \
../lib/PacketSendRecvUtility.c \
../lib/TourUtility.c 

OBJS += \
./lib/ARPAPI.o \
./lib/ARPSocketUtility.o \
./lib/ARPUDSUtility.o \
./lib/ARPUtility.o \
./lib/AddressUtility.o \
./lib/ArpCache.o \
./lib/FrameSendRecvUtility.o \
./lib/GenericUtility.o \
./lib/MemoryAllocator.o \
./lib/PacketSendRecvUtility.o \
./lib/TourUtility.o 

C_DEPS += \
./lib/ARPAPI.d \
./lib/ARPSocketUtility.d \
./lib/ARPUDSUtility.d \
./lib/ARPUtility.d \
./lib/AddressUtility.d \
./lib/ArpCache.d \
./lib/FrameSendRecvUtility.d \
./lib/GenericUtility.d \
./lib/MemoryAllocator.d \
./lib/PacketSendRecvUtility.d \
./lib/TourUtility.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


