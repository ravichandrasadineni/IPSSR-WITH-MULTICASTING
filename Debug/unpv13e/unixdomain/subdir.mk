################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/unixdomain/daytimetcpcli.c \
../unpv13e/unixdomain/daytimetcpsrv2.c \
../unpv13e/unixdomain/mycat.c \
../unpv13e/unixdomain/myopen.c \
../unpv13e/unixdomain/openfile.c \
../unpv13e/unixdomain/readcred.c \
../unpv13e/unixdomain/sigchldwaitpid.c \
../unpv13e/unixdomain/strecho.c \
../unpv13e/unixdomain/testfcred.c \
../unpv13e/unixdomain/tfcred01.c \
../unpv13e/unixdomain/unixbind.c \
../unpv13e/unixdomain/unixdgcli01.c \
../unpv13e/unixdomain/unixdgserv01.c \
../unpv13e/unixdomain/unixstrcli01.c \
../unpv13e/unixdomain/unixstrserv01.c \
../unpv13e/unixdomain/unixstrserv02.c 

OBJS += \
./unpv13e/unixdomain/daytimetcpcli.o \
./unpv13e/unixdomain/daytimetcpsrv2.o \
./unpv13e/unixdomain/mycat.o \
./unpv13e/unixdomain/myopen.o \
./unpv13e/unixdomain/openfile.o \
./unpv13e/unixdomain/readcred.o \
./unpv13e/unixdomain/sigchldwaitpid.o \
./unpv13e/unixdomain/strecho.o \
./unpv13e/unixdomain/testfcred.o \
./unpv13e/unixdomain/tfcred01.o \
./unpv13e/unixdomain/unixbind.o \
./unpv13e/unixdomain/unixdgcli01.o \
./unpv13e/unixdomain/unixdgserv01.o \
./unpv13e/unixdomain/unixstrcli01.o \
./unpv13e/unixdomain/unixstrserv01.o \
./unpv13e/unixdomain/unixstrserv02.o 

C_DEPS += \
./unpv13e/unixdomain/daytimetcpcli.d \
./unpv13e/unixdomain/daytimetcpsrv2.d \
./unpv13e/unixdomain/mycat.d \
./unpv13e/unixdomain/myopen.d \
./unpv13e/unixdomain/openfile.d \
./unpv13e/unixdomain/readcred.d \
./unpv13e/unixdomain/sigchldwaitpid.d \
./unpv13e/unixdomain/strecho.d \
./unpv13e/unixdomain/testfcred.d \
./unpv13e/unixdomain/tfcred01.d \
./unpv13e/unixdomain/unixbind.d \
./unpv13e/unixdomain/unixdgcli01.d \
./unpv13e/unixdomain/unixdgserv01.d \
./unpv13e/unixdomain/unixstrcli01.d \
./unpv13e/unixdomain/unixstrserv01.d \
./unpv13e/unixdomain/unixstrserv02.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/unixdomain/%.o: ../unpv13e/unixdomain/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


