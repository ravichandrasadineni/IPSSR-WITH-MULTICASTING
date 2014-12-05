################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unpv13e/sctp/sctp_addr_to_associd.c \
../unpv13e/sctp/sctp_bindargs.c \
../unpv13e/sctp/sctp_check_notify.c \
../unpv13e/sctp/sctp_displayevents.c \
../unpv13e/sctp/sctp_getnostrm.c \
../unpv13e/sctp/sctp_modify_hb.c \
../unpv13e/sctp/sctp_pdapircv.c \
../unpv13e/sctp/sctp_print_addrs.c \
../unpv13e/sctp/sctp_strcli.c \
../unpv13e/sctp/sctp_strcli1.c \
../unpv13e/sctp/sctp_strcli_un.c \
../unpv13e/sctp/sctp_strcliecho.c \
../unpv13e/sctp/sctp_strcliecho2.c \
../unpv13e/sctp/sctp_wrapper.c \
../unpv13e/sctp/sctpclient01.c \
../unpv13e/sctp/sctpclient02.c \
../unpv13e/sctp/sctpclient04.c \
../unpv13e/sctp/sctpserv01.c \
../unpv13e/sctp/sctpserv02.c \
../unpv13e/sctp/sctpserv03.c \
../unpv13e/sctp/sctpserv04.c \
../unpv13e/sctp/sctpserv05.c \
../unpv13e/sctp/sctpserv06.c \
../unpv13e/sctp/sctpserv07.c \
../unpv13e/sctp/sctpserv_fork.c 

OBJS += \
./unpv13e/sctp/sctp_addr_to_associd.o \
./unpv13e/sctp/sctp_bindargs.o \
./unpv13e/sctp/sctp_check_notify.o \
./unpv13e/sctp/sctp_displayevents.o \
./unpv13e/sctp/sctp_getnostrm.o \
./unpv13e/sctp/sctp_modify_hb.o \
./unpv13e/sctp/sctp_pdapircv.o \
./unpv13e/sctp/sctp_print_addrs.o \
./unpv13e/sctp/sctp_strcli.o \
./unpv13e/sctp/sctp_strcli1.o \
./unpv13e/sctp/sctp_strcli_un.o \
./unpv13e/sctp/sctp_strcliecho.o \
./unpv13e/sctp/sctp_strcliecho2.o \
./unpv13e/sctp/sctp_wrapper.o \
./unpv13e/sctp/sctpclient01.o \
./unpv13e/sctp/sctpclient02.o \
./unpv13e/sctp/sctpclient04.o \
./unpv13e/sctp/sctpserv01.o \
./unpv13e/sctp/sctpserv02.o \
./unpv13e/sctp/sctpserv03.o \
./unpv13e/sctp/sctpserv04.o \
./unpv13e/sctp/sctpserv05.o \
./unpv13e/sctp/sctpserv06.o \
./unpv13e/sctp/sctpserv07.o \
./unpv13e/sctp/sctpserv_fork.o 

C_DEPS += \
./unpv13e/sctp/sctp_addr_to_associd.d \
./unpv13e/sctp/sctp_bindargs.d \
./unpv13e/sctp/sctp_check_notify.d \
./unpv13e/sctp/sctp_displayevents.d \
./unpv13e/sctp/sctp_getnostrm.d \
./unpv13e/sctp/sctp_modify_hb.d \
./unpv13e/sctp/sctp_pdapircv.d \
./unpv13e/sctp/sctp_print_addrs.d \
./unpv13e/sctp/sctp_strcli.d \
./unpv13e/sctp/sctp_strcli1.d \
./unpv13e/sctp/sctp_strcli_un.d \
./unpv13e/sctp/sctp_strcliecho.d \
./unpv13e/sctp/sctp_strcliecho2.d \
./unpv13e/sctp/sctp_wrapper.d \
./unpv13e/sctp/sctpclient01.d \
./unpv13e/sctp/sctpclient02.d \
./unpv13e/sctp/sctpclient04.d \
./unpv13e/sctp/sctpserv01.d \
./unpv13e/sctp/sctpserv02.d \
./unpv13e/sctp/sctpserv03.d \
./unpv13e/sctp/sctpserv04.d \
./unpv13e/sctp/sctpserv05.d \
./unpv13e/sctp/sctpserv06.d \
./unpv13e/sctp/sctpserv07.d \
./unpv13e/sctp/sctpserv_fork.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/sctp/%.o: ../unpv13e/sctp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


