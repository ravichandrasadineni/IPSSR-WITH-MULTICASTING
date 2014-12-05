################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/ssntp/main.c \
../unpv13e/ssntp/sntp_proc.c 

OBJS += \
./unpv13e/ssntp/main.o \
./unpv13e/ssntp/sntp_proc.o 

C_DEPS += \
./unpv13e/ssntp/main.d \
./unpv13e/ssntp/sntp_proc.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/ssntp/%.o: ../unpv13e/ssntp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


