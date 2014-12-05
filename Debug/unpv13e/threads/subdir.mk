################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/threads/example01.c \
../unpv13e/threads/example02.c \
../unpv13e/threads/example03.c \
../unpv13e/threads/readline.c \
../unpv13e/threads/strclithread.c \
../unpv13e/threads/strclithread2.c \
../unpv13e/threads/tcpcli01.c \
../unpv13e/threads/tcpcli02.c \
../unpv13e/threads/tcpserv01.c \
../unpv13e/threads/tcpserv02.c \
../unpv13e/threads/test01.c \
../unpv13e/threads/test02.c \
../unpv13e/threads/test03.c \
../unpv13e/threads/test04.c \
../unpv13e/threads/test05.c \
../unpv13e/threads/web01.c \
../unpv13e/threads/web02.c \
../unpv13e/threads/web03.c 

OBJS += \
./unpv13e/threads/example01.o \
./unpv13e/threads/example02.o \
./unpv13e/threads/example03.o \
./unpv13e/threads/readline.o \
./unpv13e/threads/strclithread.o \
./unpv13e/threads/strclithread2.o \
./unpv13e/threads/tcpcli01.o \
./unpv13e/threads/tcpcli02.o \
./unpv13e/threads/tcpserv01.o \
./unpv13e/threads/tcpserv02.o \
./unpv13e/threads/test01.o \
./unpv13e/threads/test02.o \
./unpv13e/threads/test03.o \
./unpv13e/threads/test04.o \
./unpv13e/threads/test05.o \
./unpv13e/threads/web01.o \
./unpv13e/threads/web02.o \
./unpv13e/threads/web03.o 

C_DEPS += \
./unpv13e/threads/example01.d \
./unpv13e/threads/example02.d \
./unpv13e/threads/example03.d \
./unpv13e/threads/readline.d \
./unpv13e/threads/strclithread.d \
./unpv13e/threads/strclithread2.d \
./unpv13e/threads/tcpcli01.d \
./unpv13e/threads/tcpcli02.d \
./unpv13e/threads/tcpserv01.d \
./unpv13e/threads/tcpserv02.d \
./unpv13e/threads/test01.d \
./unpv13e/threads/test02.d \
./unpv13e/threads/test03.d \
./unpv13e/threads/test04.d \
./unpv13e/threads/test05.d \
./unpv13e/threads/web01.d \
./unpv13e/threads/web02.d \
./unpv13e/threads/web03.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/threads/%.o: ../unpv13e/threads/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


