################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/rtt/dg_cli.c \
../unpv13e/rtt/dg_echo.c \
../unpv13e/rtt/dg_send_recv.c \
../unpv13e/rtt/udpcli01.c 

OBJS += \
./unpv13e/rtt/dg_cli.o \
./unpv13e/rtt/dg_echo.o \
./unpv13e/rtt/dg_send_recv.o \
./unpv13e/rtt/udpcli01.o 

C_DEPS += \
./unpv13e/rtt/dg_cli.d \
./unpv13e/rtt/dg_echo.d \
./unpv13e/rtt/dg_send_recv.d \
./unpv13e/rtt/udpcli01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/rtt/%.o: ../unpv13e/rtt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


