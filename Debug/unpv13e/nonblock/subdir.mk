################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/nonblock/daytimetcpcli.c \
../unpv13e/nonblock/home_page.c \
../unpv13e/nonblock/start_connect.c \
../unpv13e/nonblock/strclifork.c \
../unpv13e/nonblock/strclinonb.c \
../unpv13e/nonblock/tcpcli01.c \
../unpv13e/nonblock/tcpcli02.c \
../unpv13e/nonblock/tcpcli03.c \
../unpv13e/nonblock/tcpcli04.c \
../unpv13e/nonblock/tcpservselect03.c \
../unpv13e/nonblock/web.c \
../unpv13e/nonblock/write_get_cmd.c 

OBJS += \
./unpv13e/nonblock/daytimetcpcli.o \
./unpv13e/nonblock/home_page.o \
./unpv13e/nonblock/start_connect.o \
./unpv13e/nonblock/strclifork.o \
./unpv13e/nonblock/strclinonb.o \
./unpv13e/nonblock/tcpcli01.o \
./unpv13e/nonblock/tcpcli02.o \
./unpv13e/nonblock/tcpcli03.o \
./unpv13e/nonblock/tcpcli04.o \
./unpv13e/nonblock/tcpservselect03.o \
./unpv13e/nonblock/web.o \
./unpv13e/nonblock/write_get_cmd.o 

C_DEPS += \
./unpv13e/nonblock/daytimetcpcli.d \
./unpv13e/nonblock/home_page.d \
./unpv13e/nonblock/start_connect.d \
./unpv13e/nonblock/strclifork.d \
./unpv13e/nonblock/strclinonb.d \
./unpv13e/nonblock/tcpcli01.d \
./unpv13e/nonblock/tcpcli02.d \
./unpv13e/nonblock/tcpcli03.d \
./unpv13e/nonblock/tcpcli04.d \
./unpv13e/nonblock/tcpservselect03.d \
./unpv13e/nonblock/web.d \
./unpv13e/nonblock/write_get_cmd.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/nonblock/%.o: ../unpv13e/nonblock/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


