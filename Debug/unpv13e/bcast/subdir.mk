################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/bcast/dgclibcast1.c \
../unpv13e/bcast/dgclibcast2.c \
../unpv13e/bcast/dgclibcast3.c \
../unpv13e/bcast/dgclibcast4.c \
../unpv13e/bcast/dgclibcast5.c \
../unpv13e/bcast/dgclibcast6.c \
../unpv13e/bcast/udpcli01.c \
../unpv13e/bcast/udpcli02.c \
../unpv13e/bcast/udpcli03.c \
../unpv13e/bcast/udpcli04.c \
../unpv13e/bcast/udpcli05.c \
../unpv13e/bcast/udpcli06.c 

OBJS += \
./unpv13e/bcast/dgclibcast1.o \
./unpv13e/bcast/dgclibcast2.o \
./unpv13e/bcast/dgclibcast3.o \
./unpv13e/bcast/dgclibcast4.o \
./unpv13e/bcast/dgclibcast5.o \
./unpv13e/bcast/dgclibcast6.o \
./unpv13e/bcast/udpcli01.o \
./unpv13e/bcast/udpcli02.o \
./unpv13e/bcast/udpcli03.o \
./unpv13e/bcast/udpcli04.o \
./unpv13e/bcast/udpcli05.o \
./unpv13e/bcast/udpcli06.o 

C_DEPS += \
./unpv13e/bcast/dgclibcast1.d \
./unpv13e/bcast/dgclibcast2.d \
./unpv13e/bcast/dgclibcast3.d \
./unpv13e/bcast/dgclibcast4.d \
./unpv13e/bcast/dgclibcast5.d \
./unpv13e/bcast/dgclibcast6.d \
./unpv13e/bcast/udpcli01.d \
./unpv13e/bcast/udpcli02.d \
./unpv13e/bcast/udpcli03.d \
./unpv13e/bcast/udpcli04.d \
./unpv13e/bcast/udpcli05.d \
./unpv13e/bcast/udpcli06.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/bcast/%.o: ../unpv13e/bcast/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


