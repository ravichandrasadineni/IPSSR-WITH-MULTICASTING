################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/ioctl/lsif01.c \
../unpv13e/ioctl/lsif02.c \
../unpv13e/ioctl/prifinfo.c \
../unpv13e/ioctl/prmac.c \
../unpv13e/ioctl/test1.c 

OBJS += \
./unpv13e/ioctl/lsif01.o \
./unpv13e/ioctl/lsif02.o \
./unpv13e/ioctl/prifinfo.o \
./unpv13e/ioctl/prmac.o \
./unpv13e/ioctl/test1.o 

C_DEPS += \
./unpv13e/ioctl/lsif01.d \
./unpv13e/ioctl/lsif02.d \
./unpv13e/ioctl/prifinfo.d \
./unpv13e/ioctl/prmac.d \
./unpv13e/ioctl/test1.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/ioctl/%.o: ../unpv13e/ioctl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


