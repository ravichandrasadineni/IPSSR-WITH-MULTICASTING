################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/sigio/dgcli01.c \
../unpv13e/sigio/dgecho01.c \
../unpv13e/sigio/udpcli01.c \
../unpv13e/sigio/udpserv01.c 

OBJS += \
./unpv13e/sigio/dgcli01.o \
./unpv13e/sigio/dgecho01.o \
./unpv13e/sigio/udpcli01.o \
./unpv13e/sigio/udpserv01.o 

C_DEPS += \
./unpv13e/sigio/dgcli01.d \
./unpv13e/sigio/dgecho01.d \
./unpv13e/sigio/udpcli01.d \
./unpv13e/sigio/udpserv01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/sigio/%.o: ../unpv13e/sigio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


