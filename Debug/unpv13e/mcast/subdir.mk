################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/mcast/dgclibcast1.c \
../unpv13e/mcast/dgclimcast5.c \
../unpv13e/mcast/dgclimcast6.c \
../unpv13e/mcast/main.c \
../unpv13e/mcast/recv.c \
../unpv13e/mcast/send.c \
../unpv13e/mcast/udpcli01.c \
../unpv13e/mcast/udpcli05.c \
../unpv13e/mcast/udpcli06.c \
../unpv13e/mcast/udpserv01.c 

OBJS += \
./unpv13e/mcast/dgclibcast1.o \
./unpv13e/mcast/dgclimcast5.o \
./unpv13e/mcast/dgclimcast6.o \
./unpv13e/mcast/main.o \
./unpv13e/mcast/recv.o \
./unpv13e/mcast/send.o \
./unpv13e/mcast/udpcli01.o \
./unpv13e/mcast/udpcli05.o \
./unpv13e/mcast/udpcli06.o \
./unpv13e/mcast/udpserv01.o 

C_DEPS += \
./unpv13e/mcast/dgclibcast1.d \
./unpv13e/mcast/dgclimcast5.d \
./unpv13e/mcast/dgclimcast6.d \
./unpv13e/mcast/main.d \
./unpv13e/mcast/recv.d \
./unpv13e/mcast/send.d \
./unpv13e/mcast/udpcli01.d \
./unpv13e/mcast/udpcli05.d \
./unpv13e/mcast/udpcli06.d \
./unpv13e/mcast/udpserv01.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/mcast/%.o: ../unpv13e/mcast/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


