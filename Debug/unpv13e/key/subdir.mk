################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/key/add.c \
../unpv13e/key/dump.c \
../unpv13e/key/name.c \
../unpv13e/key/printsadbmsg.c \
../unpv13e/key/register.c 

OBJS += \
./unpv13e/key/add.o \
./unpv13e/key/dump.o \
./unpv13e/key/name.o \
./unpv13e/key/printsadbmsg.o \
./unpv13e/key/register.o 

C_DEPS += \
./unpv13e/key/add.d \
./unpv13e/key/dump.d \
./unpv13e/key/name.d \
./unpv13e/key/printsadbmsg.d \
./unpv13e/key/register.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/key/%.o: ../unpv13e/key/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


