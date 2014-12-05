################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/sockopt/checkopts.c \
../unpv13e/sockopt/prdefaults.c \
../unpv13e/sockopt/rcvbuf.c \
../unpv13e/sockopt/rcvbufset.c \
../unpv13e/sockopt/sockopt.c 

OBJS += \
./unpv13e/sockopt/checkopts.o \
./unpv13e/sockopt/prdefaults.o \
./unpv13e/sockopt/rcvbuf.o \
./unpv13e/sockopt/rcvbufset.o \
./unpv13e/sockopt/sockopt.o 

C_DEPS += \
./unpv13e/sockopt/checkopts.d \
./unpv13e/sockopt/prdefaults.d \
./unpv13e/sockopt/rcvbuf.d \
./unpv13e/sockopt/rcvbufset.d \
./unpv13e/sockopt/sockopt.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/sockopt/%.o: ../unpv13e/sockopt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


