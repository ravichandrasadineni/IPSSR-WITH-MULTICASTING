################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/select/strcliselect01.c \
../unpv13e/select/strcliselect02.c \
../unpv13e/select/tcpcli01.c \
../unpv13e/select/tcpcli02.c \
../unpv13e/select/tcpcli03.c 

OBJS += \
./unpv13e/select/strcliselect01.o \
./unpv13e/select/strcliselect02.o \
./unpv13e/select/tcpcli01.o \
./unpv13e/select/tcpcli02.o \
./unpv13e/select/tcpcli03.o 

C_DEPS += \
./unpv13e/select/strcliselect01.d \
./unpv13e/select/strcliselect02.d \
./unpv13e/select/tcpcli01.d \
./unpv13e/select/tcpcli02.d \
./unpv13e/select/tcpcli03.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/select/%.o: ../unpv13e/select/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


