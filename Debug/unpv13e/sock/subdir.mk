################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/sock/buffers.c \
../unpv13e/sock/cliopen.c \
../unpv13e/sock/crlf.c \
../unpv13e/sock/error.c \
../unpv13e/sock/loop.c \
../unpv13e/sock/looptcp.c \
../unpv13e/sock/loopudp.c \
../unpv13e/sock/main.c \
../unpv13e/sock/multicast.c \
../unpv13e/sock/pattern.c \
../unpv13e/sock/servopen.c \
../unpv13e/sock/sinktcp.c \
../unpv13e/sock/sinkudp.c \
../unpv13e/sock/sleepus.c \
../unpv13e/sock/sockopts.c \
../unpv13e/sock/sourceroute.c \
../unpv13e/sock/sourcesink.c \
../unpv13e/sock/sourcetcp.c \
../unpv13e/sock/sourceudp.c \
../unpv13e/sock/strerror.c \
../unpv13e/sock/tellwait.c \
../unpv13e/sock/write.c \
../unpv13e/sock/writen.c 

OBJS += \
./unpv13e/sock/buffers.o \
./unpv13e/sock/cliopen.o \
./unpv13e/sock/crlf.o \
./unpv13e/sock/error.o \
./unpv13e/sock/loop.o \
./unpv13e/sock/looptcp.o \
./unpv13e/sock/loopudp.o \
./unpv13e/sock/main.o \
./unpv13e/sock/multicast.o \
./unpv13e/sock/pattern.o \
./unpv13e/sock/servopen.o \
./unpv13e/sock/sinktcp.o \
./unpv13e/sock/sinkudp.o \
./unpv13e/sock/sleepus.o \
./unpv13e/sock/sockopts.o \
./unpv13e/sock/sourceroute.o \
./unpv13e/sock/sourcesink.o \
./unpv13e/sock/sourcetcp.o \
./unpv13e/sock/sourceudp.o \
./unpv13e/sock/strerror.o \
./unpv13e/sock/tellwait.o \
./unpv13e/sock/write.o \
./unpv13e/sock/writen.o 

C_DEPS += \
./unpv13e/sock/buffers.d \
./unpv13e/sock/cliopen.d \
./unpv13e/sock/crlf.d \
./unpv13e/sock/error.d \
./unpv13e/sock/loop.d \
./unpv13e/sock/looptcp.d \
./unpv13e/sock/loopudp.d \
./unpv13e/sock/main.d \
./unpv13e/sock/multicast.d \
./unpv13e/sock/pattern.d \
./unpv13e/sock/servopen.d \
./unpv13e/sock/sinktcp.d \
./unpv13e/sock/sinkudp.d \
./unpv13e/sock/sleepus.d \
./unpv13e/sock/sockopts.d \
./unpv13e/sock/sourceroute.d \
./unpv13e/sock/sourcesink.d \
./unpv13e/sock/sourcetcp.d \
./unpv13e/sock/sourceudp.d \
./unpv13e/sock/strerror.d \
./unpv13e/sock/tellwait.d \
./unpv13e/sock/write.d \
./unpv13e/sock/writen.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/sock/%.o: ../unpv13e/sock/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


