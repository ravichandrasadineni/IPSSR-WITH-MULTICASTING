################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/inetd/daytimetcpsrv2.c \
../unpv13e/inetd/daytimetcpsrv3.c 

OBJS += \
./unpv13e/inetd/daytimetcpsrv2.o \
./unpv13e/inetd/daytimetcpsrv3.o 

C_DEPS += \
./unpv13e/inetd/daytimetcpsrv2.d \
./unpv13e/inetd/daytimetcpsrv3.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/inetd/%.o: ../unpv13e/inetd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


