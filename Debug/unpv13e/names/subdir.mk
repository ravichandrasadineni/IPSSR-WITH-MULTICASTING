################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/names/daytimetcpcli.c \
../unpv13e/names/daytimetcpcli1.c \
../unpv13e/names/daytimetcpcli2.c \
../unpv13e/names/daytimetcpcli3.c \
../unpv13e/names/daytimetcpsrv1.c \
../unpv13e/names/daytimetcpsrv2.c \
../unpv13e/names/daytimetcpsrv3.c \
../unpv13e/names/daytimetcpsrv4.c \
../unpv13e/names/daytimeudpcli1.c \
../unpv13e/names/daytimeudpcli2.c \
../unpv13e/names/daytimeudpsrv2.c \
../unpv13e/names/daytimeudpsrv3.c \
../unpv13e/names/hostent.c \
../unpv13e/names/hostent2.c \
../unpv13e/names/hostent3.c \
../unpv13e/names/myaddrs1.c \
../unpv13e/names/netent.c \
../unpv13e/names/prmyaddrs.c \
../unpv13e/names/prmyaddrs1.c \
../unpv13e/names/test1.c \
../unpv13e/names/test2.c \
../unpv13e/names/udp_server_reuseaddr.c 

OBJS += \
./unpv13e/names/daytimetcpcli.o \
./unpv13e/names/daytimetcpcli1.o \
./unpv13e/names/daytimetcpcli2.o \
./unpv13e/names/daytimetcpcli3.o \
./unpv13e/names/daytimetcpsrv1.o \
./unpv13e/names/daytimetcpsrv2.o \
./unpv13e/names/daytimetcpsrv3.o \
./unpv13e/names/daytimetcpsrv4.o \
./unpv13e/names/daytimeudpcli1.o \
./unpv13e/names/daytimeudpcli2.o \
./unpv13e/names/daytimeudpsrv2.o \
./unpv13e/names/daytimeudpsrv3.o \
./unpv13e/names/hostent.o \
./unpv13e/names/hostent2.o \
./unpv13e/names/hostent3.o \
./unpv13e/names/myaddrs1.o \
./unpv13e/names/netent.o \
./unpv13e/names/prmyaddrs.o \
./unpv13e/names/prmyaddrs1.o \
./unpv13e/names/test1.o \
./unpv13e/names/test2.o \
./unpv13e/names/udp_server_reuseaddr.o 

C_DEPS += \
./unpv13e/names/daytimetcpcli.d \
./unpv13e/names/daytimetcpcli1.d \
./unpv13e/names/daytimetcpcli2.d \
./unpv13e/names/daytimetcpcli3.d \
./unpv13e/names/daytimetcpsrv1.d \
./unpv13e/names/daytimetcpsrv2.d \
./unpv13e/names/daytimetcpsrv3.d \
./unpv13e/names/daytimetcpsrv4.d \
./unpv13e/names/daytimeudpcli1.d \
./unpv13e/names/daytimeudpcli2.d \
./unpv13e/names/daytimeudpsrv2.d \
./unpv13e/names/daytimeudpsrv3.d \
./unpv13e/names/hostent.d \
./unpv13e/names/hostent2.d \
./unpv13e/names/hostent3.d \
./unpv13e/names/myaddrs1.d \
./unpv13e/names/netent.d \
./unpv13e/names/prmyaddrs.d \
./unpv13e/names/prmyaddrs1.d \
./unpv13e/names/test1.d \
./unpv13e/names/test2.d \
./unpv13e/names/udp_server_reuseaddr.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/names/%.o: ../unpv13e/names/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


