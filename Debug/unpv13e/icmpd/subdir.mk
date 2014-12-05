################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/icmpd/dgcli01.c \
../unpv13e/icmpd/icmpd.c \
../unpv13e/icmpd/readable_conn.c \
../unpv13e/icmpd/readable_listen.c \
../unpv13e/icmpd/readable_v4.c \
../unpv13e/icmpd/readable_v6.c \
../unpv13e/icmpd/udpcli01.c 

OBJS += \
./unpv13e/icmpd/dgcli01.o \
./unpv13e/icmpd/icmpd.o \
./unpv13e/icmpd/readable_conn.o \
./unpv13e/icmpd/readable_listen.o \
./unpv13e/icmpd/readable_v4.o \
./unpv13e/icmpd/readable_v6.o \
./unpv13e/icmpd/udpcli01.o 

C_DEPS += \
./unpv13e/icmpd/dgcli01.d \
./unpv13e/icmpd/icmpd.d \
./unpv13e/icmpd/readable_conn.d \
./unpv13e/icmpd/readable_listen.d \
./unpv13e/icmpd/readable_v4.d \
./unpv13e/icmpd/readable_v6.d \
./unpv13e/icmpd/udpcli01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/icmpd/%.o: ../unpv13e/icmpd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


