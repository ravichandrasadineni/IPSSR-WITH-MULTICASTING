################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/libgai/old/ga_unixstruct.c \
../unpv13e/libgai/old/savecopy.c 

OBJS += \
./unpv13e/libgai/old/ga_unixstruct.o \
./unpv13e/libgai/old/savecopy.o 

C_DEPS += \
./unpv13e/libgai/old/ga_unixstruct.d \
./unpv13e/libgai/old/savecopy.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/libgai/old/%.o: ../unpv13e/libgai/old/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


