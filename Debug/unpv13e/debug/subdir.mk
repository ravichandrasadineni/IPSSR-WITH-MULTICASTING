################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/debug/backlog.c \
../unpv13e/debug/qlen.c \
../unpv13e/debug/test01.c \
../unpv13e/debug/test02.c \
../unpv13e/debug/test03.c \
../unpv13e/debug/test04.c \
../unpv13e/debug/test05.c \
../unpv13e/debug/test06.c 

OBJS += \
./unpv13e/debug/backlog.o \
./unpv13e/debug/qlen.o \
./unpv13e/debug/test01.o \
./unpv13e/debug/test02.o \
./unpv13e/debug/test03.o \
./unpv13e/debug/test04.o \
./unpv13e/debug/test05.o \
./unpv13e/debug/test06.o 

C_DEPS += \
./unpv13e/debug/backlog.d \
./unpv13e/debug/qlen.d \
./unpv13e/debug/test01.d \
./unpv13e/debug/test02.d \
./unpv13e/debug/test03.d \
./unpv13e/debug/test04.d \
./unpv13e/debug/test05.d \
./unpv13e/debug/test06.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/debug/%.o: ../unpv13e/debug/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


