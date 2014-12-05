################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/test/accept_eintr.c \
../unpv13e/test/funcs.c \
../unpv13e/test/readline1.c \
../unpv13e/test/readline2.c \
../unpv13e/test/readline3.c \
../unpv13e/test/test1.c \
../unpv13e/test/test2.c \
../unpv13e/test/tisfdtype.c \
../unpv13e/test/treadline1.c \
../unpv13e/test/treadline2.c \
../unpv13e/test/treadline3.c \
../unpv13e/test/tshutdown.c \
../unpv13e/test/tsnprintf.c 

OBJS += \
./unpv13e/test/accept_eintr.o \
./unpv13e/test/funcs.o \
./unpv13e/test/readline1.o \
./unpv13e/test/readline2.o \
./unpv13e/test/readline3.o \
./unpv13e/test/test1.o \
./unpv13e/test/test2.o \
./unpv13e/test/tisfdtype.o \
./unpv13e/test/treadline1.o \
./unpv13e/test/treadline2.o \
./unpv13e/test/treadline3.o \
./unpv13e/test/tshutdown.o \
./unpv13e/test/tsnprintf.o 

C_DEPS += \
./unpv13e/test/accept_eintr.d \
./unpv13e/test/funcs.d \
./unpv13e/test/readline1.d \
./unpv13e/test/readline2.d \
./unpv13e/test/readline3.d \
./unpv13e/test/test1.d \
./unpv13e/test/test2.d \
./unpv13e/test/tisfdtype.d \
./unpv13e/test/treadline1.d \
./unpv13e/test/treadline2.d \
./unpv13e/test/treadline3.d \
./unpv13e/test/tshutdown.d \
./unpv13e/test/tsnprintf.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/test/%.o: ../unpv13e/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


