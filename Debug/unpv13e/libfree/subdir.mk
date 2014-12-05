################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../unpv13e/libfree/in_cksum.o \
../unpv13e/libfree/inet_ntop.o \
../unpv13e/libfree/inet_pton.o 

C_SRCS += \
../unpv13e/libfree/getaddrinfo.c \
../unpv13e/libfree/getnameinfo.c \
../unpv13e/libfree/in_cksum.c \
../unpv13e/libfree/inet_aton.c \
../unpv13e/libfree/inet_ntop.c \
../unpv13e/libfree/inet_ntop_ipv4.c \
../unpv13e/libfree/inet_pton.c \
../unpv13e/libfree/inet_pton_ipv4.c \
../unpv13e/libfree/test_ascii2addr.c \
../unpv13e/libfree/test_getservbyname_r.c \
../unpv13e/libfree/test_inet_pton.c 

OBJS += \
./unpv13e/libfree/getaddrinfo.o \
./unpv13e/libfree/getnameinfo.o \
./unpv13e/libfree/in_cksum.o \
./unpv13e/libfree/inet_aton.o \
./unpv13e/libfree/inet_ntop.o \
./unpv13e/libfree/inet_ntop_ipv4.o \
./unpv13e/libfree/inet_pton.o \
./unpv13e/libfree/inet_pton_ipv4.o \
./unpv13e/libfree/test_ascii2addr.o \
./unpv13e/libfree/test_getservbyname_r.o \
./unpv13e/libfree/test_inet_pton.o 

C_DEPS += \
./unpv13e/libfree/getaddrinfo.d \
./unpv13e/libfree/getnameinfo.d \
./unpv13e/libfree/in_cksum.d \
./unpv13e/libfree/inet_aton.d \
./unpv13e/libfree/inet_ntop.d \
./unpv13e/libfree/inet_ntop_ipv4.d \
./unpv13e/libfree/inet_pton.d \
./unpv13e/libfree/inet_pton_ipv4.d \
./unpv13e/libfree/test_ascii2addr.d \
./unpv13e/libfree/test_getservbyname_r.d \
./unpv13e/libfree/test_inet_pton.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/libfree/%.o: ../unpv13e/libfree/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


