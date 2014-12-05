################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../unpv13e/intro/byteorder.o \
../unpv13e/intro/daytimetcpcli.o \
../unpv13e/intro/daytimetcpcli1.o \
../unpv13e/intro/daytimetcpcli2.o \
../unpv13e/intro/daytimetcpcli3.o \
../unpv13e/intro/daytimetcpcliv6.o \
../unpv13e/intro/daytimetcpsrv.o \
../unpv13e/intro/daytimetcpsrv1.o \
../unpv13e/intro/daytimetcpsrv2.o \
../unpv13e/intro/daytimetcpsrv3.o \
../unpv13e/intro/daytimetcpsrvv6.o \
../unpv13e/intro/echoserver.o 

C_SRCS += \
../unpv13e/intro/byteorder.c \
../unpv13e/intro/daytimetcpcli.c \
../unpv13e/intro/daytimetcpcli1.c \
../unpv13e/intro/daytimetcpcli2.c \
../unpv13e/intro/daytimetcpcli3.c \
../unpv13e/intro/daytimetcpcliv6.c \
../unpv13e/intro/daytimetcpsrv.c \
../unpv13e/intro/daytimetcpsrv1.c \
../unpv13e/intro/daytimetcpsrv2.c \
../unpv13e/intro/daytimetcpsrv3.c \
../unpv13e/intro/daytimetcpsrvv6.c \
../unpv13e/intro/echoserver.c 

OBJS += \
./unpv13e/intro/byteorder.o \
./unpv13e/intro/daytimetcpcli.o \
./unpv13e/intro/daytimetcpcli1.o \
./unpv13e/intro/daytimetcpcli2.o \
./unpv13e/intro/daytimetcpcli3.o \
./unpv13e/intro/daytimetcpcliv6.o \
./unpv13e/intro/daytimetcpsrv.o \
./unpv13e/intro/daytimetcpsrv1.o \
./unpv13e/intro/daytimetcpsrv2.o \
./unpv13e/intro/daytimetcpsrv3.o \
./unpv13e/intro/daytimetcpsrvv6.o \
./unpv13e/intro/echoserver.o 

C_DEPS += \
./unpv13e/intro/byteorder.d \
./unpv13e/intro/daytimetcpcli.d \
./unpv13e/intro/daytimetcpcli1.d \
./unpv13e/intro/daytimetcpcli2.d \
./unpv13e/intro/daytimetcpcli3.d \
./unpv13e/intro/daytimetcpcliv6.d \
./unpv13e/intro/daytimetcpsrv.d \
./unpv13e/intro/daytimetcpsrv1.d \
./unpv13e/intro/daytimetcpsrv2.d \
./unpv13e/intro/daytimetcpsrv3.d \
./unpv13e/intro/daytimetcpsrvv6.d \
./unpv13e/intro/echoserver.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/intro/%.o: ../unpv13e/intro/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


