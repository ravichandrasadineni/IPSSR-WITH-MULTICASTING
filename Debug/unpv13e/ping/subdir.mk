################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/ping/bsdping.c \
../unpv13e/ping/init_v6.c \
../unpv13e/ping/main.c \
../unpv13e/ping/ping_v4.c \
../unpv13e/ping/proc_v4.c \
../unpv13e/ping/proc_v6.c \
../unpv13e/ping/readloop.c \
../unpv13e/ping/send_v4.c \
../unpv13e/ping/send_v6.c \
../unpv13e/ping/sig_alrm.c \
../unpv13e/ping/tv_sub.c 

OBJS += \
./unpv13e/ping/bsdping.o \
./unpv13e/ping/init_v6.o \
./unpv13e/ping/main.o \
./unpv13e/ping/ping_v4.o \
./unpv13e/ping/proc_v4.o \
./unpv13e/ping/proc_v6.o \
./unpv13e/ping/readloop.o \
./unpv13e/ping/send_v4.o \
./unpv13e/ping/send_v6.o \
./unpv13e/ping/sig_alrm.o \
./unpv13e/ping/tv_sub.o 

C_DEPS += \
./unpv13e/ping/bsdping.d \
./unpv13e/ping/init_v6.d \
./unpv13e/ping/main.d \
./unpv13e/ping/ping_v4.d \
./unpv13e/ping/proc_v4.d \
./unpv13e/ping/proc_v6.d \
./unpv13e/ping/readloop.d \
./unpv13e/ping/send_v4.d \
./unpv13e/ping/send_v6.d \
./unpv13e/ping/sig_alrm.d \
./unpv13e/ping/tv_sub.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/ping/%.o: ../unpv13e/ping/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


