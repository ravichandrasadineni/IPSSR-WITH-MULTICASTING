################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/traceroute/icmpcode_v4.c \
../unpv13e/traceroute/icmpcode_v6.c \
../unpv13e/traceroute/main.c \
../unpv13e/traceroute/recv_v4.c \
../unpv13e/traceroute/recv_v6.c \
../unpv13e/traceroute/sig_alrm.c \
../unpv13e/traceroute/traceloop.c \
../unpv13e/traceroute/tv_sub.c 

OBJS += \
./unpv13e/traceroute/icmpcode_v4.o \
./unpv13e/traceroute/icmpcode_v6.o \
./unpv13e/traceroute/main.o \
./unpv13e/traceroute/recv_v4.o \
./unpv13e/traceroute/recv_v6.o \
./unpv13e/traceroute/sig_alrm.o \
./unpv13e/traceroute/traceloop.o \
./unpv13e/traceroute/tv_sub.o 

C_DEPS += \
./unpv13e/traceroute/icmpcode_v4.d \
./unpv13e/traceroute/icmpcode_v6.d \
./unpv13e/traceroute/main.d \
./unpv13e/traceroute/recv_v4.d \
./unpv13e/traceroute/recv_v6.d \
./unpv13e/traceroute/sig_alrm.d \
./unpv13e/traceroute/traceloop.d \
./unpv13e/traceroute/tv_sub.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/traceroute/%.o: ../unpv13e/traceroute/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


