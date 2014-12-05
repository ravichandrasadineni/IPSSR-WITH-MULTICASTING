################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/server/child02.c \
../unpv13e/server/child02l.c \
../unpv13e/server/child02m.c \
../unpv13e/server/child03.c \
../unpv13e/server/child03m.c \
../unpv13e/server/child04.c \
../unpv13e/server/child05.c \
../unpv13e/server/client.c \
../unpv13e/server/clientrst.c \
../unpv13e/server/lock_fcntl.c \
../unpv13e/server/lock_pthread.c \
../unpv13e/server/meter.c \
../unpv13e/server/pr_cpu_time.c \
../unpv13e/server/pthread07.c \
../unpv13e/server/pthread08.c \
../unpv13e/server/pthread09.c \
../unpv13e/server/readline.c \
../unpv13e/server/readline_r.c \
../unpv13e/server/serv00.c \
../unpv13e/server/serv01.c \
../unpv13e/server/serv02.c \
../unpv13e/server/serv02m.c \
../unpv13e/server/serv03.c \
../unpv13e/server/serv03m.c \
../unpv13e/server/serv04.c \
../unpv13e/server/serv05.c \
../unpv13e/server/serv06.c \
../unpv13e/server/serv07.c \
../unpv13e/server/serv08.c \
../unpv13e/server/serv09.c \
../unpv13e/server/sig_chld_waitpid.c \
../unpv13e/server/web_child.c \
../unpv13e/server/web_child_r.c 

OBJS += \
./unpv13e/server/child02.o \
./unpv13e/server/child02l.o \
./unpv13e/server/child02m.o \
./unpv13e/server/child03.o \
./unpv13e/server/child03m.o \
./unpv13e/server/child04.o \
./unpv13e/server/child05.o \
./unpv13e/server/client.o \
./unpv13e/server/clientrst.o \
./unpv13e/server/lock_fcntl.o \
./unpv13e/server/lock_pthread.o \
./unpv13e/server/meter.o \
./unpv13e/server/pr_cpu_time.o \
./unpv13e/server/pthread07.o \
./unpv13e/server/pthread08.o \
./unpv13e/server/pthread09.o \
./unpv13e/server/readline.o \
./unpv13e/server/readline_r.o \
./unpv13e/server/serv00.o \
./unpv13e/server/serv01.o \
./unpv13e/server/serv02.o \
./unpv13e/server/serv02m.o \
./unpv13e/server/serv03.o \
./unpv13e/server/serv03m.o \
./unpv13e/server/serv04.o \
./unpv13e/server/serv05.o \
./unpv13e/server/serv06.o \
./unpv13e/server/serv07.o \
./unpv13e/server/serv08.o \
./unpv13e/server/serv09.o \
./unpv13e/server/sig_chld_waitpid.o \
./unpv13e/server/web_child.o \
./unpv13e/server/web_child_r.o 

C_DEPS += \
./unpv13e/server/child02.d \
./unpv13e/server/child02l.d \
./unpv13e/server/child02m.d \
./unpv13e/server/child03.d \
./unpv13e/server/child03m.d \
./unpv13e/server/child04.d \
./unpv13e/server/child05.d \
./unpv13e/server/client.d \
./unpv13e/server/clientrst.d \
./unpv13e/server/lock_fcntl.d \
./unpv13e/server/lock_pthread.d \
./unpv13e/server/meter.d \
./unpv13e/server/pr_cpu_time.d \
./unpv13e/server/pthread07.d \
./unpv13e/server/pthread08.d \
./unpv13e/server/pthread09.d \
./unpv13e/server/readline.d \
./unpv13e/server/readline_r.d \
./unpv13e/server/serv00.d \
./unpv13e/server/serv01.d \
./unpv13e/server/serv02.d \
./unpv13e/server/serv02m.d \
./unpv13e/server/serv03.d \
./unpv13e/server/serv03m.d \
./unpv13e/server/serv04.d \
./unpv13e/server/serv05.d \
./unpv13e/server/serv06.d \
./unpv13e/server/serv07.d \
./unpv13e/server/serv08.d \
./unpv13e/server/serv09.d \
./unpv13e/server/sig_chld_waitpid.d \
./unpv13e/server/web_child.d \
./unpv13e/server/web_child_r.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/server/%.o: ../unpv13e/server/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


