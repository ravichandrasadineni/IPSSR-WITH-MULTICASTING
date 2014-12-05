################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../ARP.o \
../ARPSocketUtility.o \
../ARPUDSUtility.o \
../ARPUtility.o \
../AddressUtility.o \
../GenericUtility.o \
../MemoryAllocator.o \
../PacketSendRecvUtility.o \
../Tour.o \
../TourUtility.o \
../get_hw_addrs.o 

C_SRCS += \
../ARP.c \
../Tour.c \
../temp.c \
../test.c 

OBJS += \
./ARP.o \
./Tour.o \
./temp.o \
./test.o 

C_DEPS += \
./ARP.d \
./Tour.d \
./temp.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


