################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/streams/stream_dg/client.c \
../unpv13e/streams/stream_dg/net_stream.c \
../unpv13e/streams/stream_dg/server.c 

OBJS += \
./unpv13e/streams/stream_dg/client.o \
./unpv13e/streams/stream_dg/net_stream.o \
./unpv13e/streams/stream_dg/server.o 

C_DEPS += \
./unpv13e/streams/stream_dg/client.d \
./unpv13e/streams/stream_dg/net_stream.d \
./unpv13e/streams/stream_dg/server.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/streams/stream_dg/%.o: ../unpv13e/streams/stream_dg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


