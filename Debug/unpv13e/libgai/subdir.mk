################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/libgai/freeaddrinfo.c \
../unpv13e/libgai/ga_aistruct.c \
../unpv13e/libgai/ga_clone.c \
../unpv13e/libgai/ga_echeck.c \
../unpv13e/libgai/ga_nsearch.c \
../unpv13e/libgai/ga_port.c \
../unpv13e/libgai/ga_serv.c \
../unpv13e/libgai/ga_unix.c \
../unpv13e/libgai/gai_strerror.c \
../unpv13e/libgai/getaddrinfo.c \
../unpv13e/libgai/getnameinfo.c \
../unpv13e/libgai/gn_ipv46.c \
../unpv13e/libgai/test1.c \
../unpv13e/libgai/testga.c 

OBJS += \
./unpv13e/libgai/freeaddrinfo.o \
./unpv13e/libgai/ga_aistruct.o \
./unpv13e/libgai/ga_clone.o \
./unpv13e/libgai/ga_echeck.o \
./unpv13e/libgai/ga_nsearch.o \
./unpv13e/libgai/ga_port.o \
./unpv13e/libgai/ga_serv.o \
./unpv13e/libgai/ga_unix.o \
./unpv13e/libgai/gai_strerror.o \
./unpv13e/libgai/getaddrinfo.o \
./unpv13e/libgai/getnameinfo.o \
./unpv13e/libgai/gn_ipv46.o \
./unpv13e/libgai/test1.o \
./unpv13e/libgai/testga.o 

C_DEPS += \
./unpv13e/libgai/freeaddrinfo.d \
./unpv13e/libgai/ga_aistruct.d \
./unpv13e/libgai/ga_clone.d \
./unpv13e/libgai/ga_echeck.d \
./unpv13e/libgai/ga_nsearch.d \
./unpv13e/libgai/ga_port.d \
./unpv13e/libgai/ga_serv.d \
./unpv13e/libgai/ga_unix.d \
./unpv13e/libgai/gai_strerror.d \
./unpv13e/libgai/getaddrinfo.d \
./unpv13e/libgai/getnameinfo.d \
./unpv13e/libgai/gn_ipv46.d \
./unpv13e/libgai/test1.d \
./unpv13e/libgai/testga.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/libgai/%.o: ../unpv13e/libgai/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


