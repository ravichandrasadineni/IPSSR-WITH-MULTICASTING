################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/streams/strlist_sock.c \
../unpv13e/streams/strlist_xti.c \
../unpv13e/streams/tpi_bind.c \
../unpv13e/streams/tpi_close.c \
../unpv13e/streams/tpi_connect.c \
../unpv13e/streams/tpi_daytime.c \
../unpv13e/streams/tpi_read.c 

OBJS += \
./unpv13e/streams/strlist_sock.o \
./unpv13e/streams/strlist_xti.o \
./unpv13e/streams/tpi_bind.o \
./unpv13e/streams/tpi_close.o \
./unpv13e/streams/tpi_connect.o \
./unpv13e/streams/tpi_daytime.o \
./unpv13e/streams/tpi_read.o 

C_DEPS += \
./unpv13e/streams/strlist_sock.d \
./unpv13e/streams/strlist_xti.d \
./unpv13e/streams/tpi_bind.d \
./unpv13e/streams/tpi_close.d \
./unpv13e/streams/tpi_connect.d \
./unpv13e/streams/tpi_daytime.d \
./unpv13e/streams/tpi_read.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/streams/%.o: ../unpv13e/streams/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


