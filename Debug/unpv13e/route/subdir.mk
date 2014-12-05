################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/route/checkudpsum.c \
../unpv13e/route/get_ifi_info.c \
../unpv13e/route/getrt.c \
../unpv13e/route/mynetstat.c \
../unpv13e/route/prifindex.c \
../unpv13e/route/prifinfo.c \
../unpv13e/route/prifname.c \
../unpv13e/route/prifnameindex.c 

OBJS += \
./unpv13e/route/checkudpsum.o \
./unpv13e/route/get_ifi_info.o \
./unpv13e/route/getrt.o \
./unpv13e/route/mynetstat.o \
./unpv13e/route/prifindex.o \
./unpv13e/route/prifinfo.o \
./unpv13e/route/prifname.o \
./unpv13e/route/prifnameindex.o 

C_DEPS += \
./unpv13e/route/checkudpsum.d \
./unpv13e/route/get_ifi_info.d \
./unpv13e/route/getrt.d \
./unpv13e/route/mynetstat.d \
./unpv13e/route/prifindex.d \
./unpv13e/route/prifinfo.d \
./unpv13e/route/prifname.d \
./unpv13e/route/prifnameindex.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/route/%.o: ../unpv13e/route/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


