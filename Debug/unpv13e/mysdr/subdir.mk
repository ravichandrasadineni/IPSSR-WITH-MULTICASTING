################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/mysdr/loop.c \
../unpv13e/mysdr/main.c 

OBJS += \
./unpv13e/mysdr/loop.o \
./unpv13e/mysdr/main.o 

C_DEPS += \
./unpv13e/mysdr/loop.d \
./unpv13e/mysdr/main.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/mysdr/%.o: ../unpv13e/mysdr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


