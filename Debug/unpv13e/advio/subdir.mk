################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/advio/daytimetcpcli.c \
../unpv13e/advio/daytimeudpcli3.c \
../unpv13e/advio/daytimeudpcli4.c \
../unpv13e/advio/dgclitimeo.c \
../unpv13e/advio/dgclitimeo1.c \
../unpv13e/advio/dgclitimeo2.c \
../unpv13e/advio/dgclitimeo3.c \
../unpv13e/advio/dgechoaddr.c \
../unpv13e/advio/recvfromflags.c \
../unpv13e/advio/sig_chld_waitpid.c \
../unpv13e/advio/str_cli_kqueue04.c \
../unpv13e/advio/str_cli_poll03.c \
../unpv13e/advio/str_cli_select02.c \
../unpv13e/advio/str_echo_stdio02.c \
../unpv13e/advio/tcpcli01.c \
../unpv13e/advio/tcpcli02.c \
../unpv13e/advio/tcpcli03.c \
../unpv13e/advio/tcpcli04.c \
../unpv13e/advio/tcpserv02.c \
../unpv13e/advio/udpcli01.c \
../unpv13e/advio/udpcli02.c \
../unpv13e/advio/udpcli03.c \
../unpv13e/advio/udpserv01.c \
../unpv13e/advio/udpserv03.c \
../unpv13e/advio/udpserv04.c 

OBJS += \
./unpv13e/advio/daytimetcpcli.o \
./unpv13e/advio/daytimeudpcli3.o \
./unpv13e/advio/daytimeudpcli4.o \
./unpv13e/advio/dgclitimeo.o \
./unpv13e/advio/dgclitimeo1.o \
./unpv13e/advio/dgclitimeo2.o \
./unpv13e/advio/dgclitimeo3.o \
./unpv13e/advio/dgechoaddr.o \
./unpv13e/advio/recvfromflags.o \
./unpv13e/advio/sig_chld_waitpid.o \
./unpv13e/advio/str_cli_kqueue04.o \
./unpv13e/advio/str_cli_poll03.o \
./unpv13e/advio/str_cli_select02.o \
./unpv13e/advio/str_echo_stdio02.o \
./unpv13e/advio/tcpcli01.o \
./unpv13e/advio/tcpcli02.o \
./unpv13e/advio/tcpcli03.o \
./unpv13e/advio/tcpcli04.o \
./unpv13e/advio/tcpserv02.o \
./unpv13e/advio/udpcli01.o \
./unpv13e/advio/udpcli02.o \
./unpv13e/advio/udpcli03.o \
./unpv13e/advio/udpserv01.o \
./unpv13e/advio/udpserv03.o \
./unpv13e/advio/udpserv04.o 

C_DEPS += \
./unpv13e/advio/daytimetcpcli.d \
./unpv13e/advio/daytimeudpcli3.d \
./unpv13e/advio/daytimeudpcli4.d \
./unpv13e/advio/dgclitimeo.d \
./unpv13e/advio/dgclitimeo1.d \
./unpv13e/advio/dgclitimeo2.d \
./unpv13e/advio/dgclitimeo3.d \
./unpv13e/advio/dgechoaddr.d \
./unpv13e/advio/recvfromflags.d \
./unpv13e/advio/sig_chld_waitpid.d \
./unpv13e/advio/str_cli_kqueue04.d \
./unpv13e/advio/str_cli_poll03.d \
./unpv13e/advio/str_cli_select02.d \
./unpv13e/advio/str_echo_stdio02.d \
./unpv13e/advio/tcpcli01.d \
./unpv13e/advio/tcpcli02.d \
./unpv13e/advio/tcpcli03.d \
./unpv13e/advio/tcpcli04.d \
./unpv13e/advio/tcpserv02.d \
./unpv13e/advio/udpcli01.d \
./unpv13e/advio/udpcli02.d \
./unpv13e/advio/udpcli03.d \
./unpv13e/advio/udpserv01.d \
./unpv13e/advio/udpserv03.d \
./unpv13e/advio/udpserv04.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/advio/%.o: ../unpv13e/advio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


