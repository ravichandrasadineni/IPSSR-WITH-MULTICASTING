################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/Asgn3_code/get_hw_addrs.c \
../lib/Asgn3_code/prhwaddrs.c 

OBJS += \
./lib/Asgn3_code/get_hw_addrs.o \
./lib/Asgn3_code/prhwaddrs.o 

C_DEPS += \
./lib/Asgn3_code/get_hw_addrs.d \
./lib/Asgn3_code/prhwaddrs.d 


# Each subdirectory must supply rules for building sources it contributes
lib/Asgn3_code/%.o: ../lib/Asgn3_code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


