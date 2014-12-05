################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/libroute/get_rtaddrs.c \
../unpv13e/libroute/if_indextoname.c \
../unpv13e/libroute/if_nameindex.c \
../unpv13e/libroute/if_nametoindex.c \
../unpv13e/libroute/net_rt_dump.c \
../unpv13e/libroute/net_rt_iflist.c \
../unpv13e/libroute/sock_masktop.c 

OBJS += \
./unpv13e/libroute/get_rtaddrs.o \
./unpv13e/libroute/if_indextoname.o \
./unpv13e/libroute/if_nameindex.o \
./unpv13e/libroute/if_nametoindex.o \
./unpv13e/libroute/net_rt_dump.o \
./unpv13e/libroute/net_rt_iflist.o \
./unpv13e/libroute/sock_masktop.o 

C_DEPS += \
./unpv13e/libroute/get_rtaddrs.d \
./unpv13e/libroute/if_indextoname.d \
./unpv13e/libroute/if_nameindex.d \
./unpv13e/libroute/if_nametoindex.d \
./unpv13e/libroute/net_rt_dump.d \
./unpv13e/libroute/net_rt_iflist.d \
./unpv13e/libroute/sock_masktop.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/libroute/%.o: ../unpv13e/libroute/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


