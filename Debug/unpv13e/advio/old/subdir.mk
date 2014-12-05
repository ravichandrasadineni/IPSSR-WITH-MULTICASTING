################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/advio/old/dgechoaddr.c \
../unpv13e/advio/old/recvfromflags.c \
../unpv13e/advio/old/test01.c 

OBJS += \
./unpv13e/advio/old/dgechoaddr.o \
./unpv13e/advio/old/recvfromflags.o \
./unpv13e/advio/old/test01.o 

C_DEPS += \
./unpv13e/advio/old/dgechoaddr.d \
./unpv13e/advio/old/recvfromflags.d \
./unpv13e/advio/old/test01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/advio/old/%.o: ../unpv13e/advio/old/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


