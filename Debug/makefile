################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include unpv13e/unixdomain/subdir.mk
-include unpv13e/udpcliserv/subdir.mk
-include unpv13e/udpcksum/subdir.mk
-include unpv13e/traceroute/subdir.mk
-include unpv13e/threads/subdir.mk
-include unpv13e/test/subdir.mk
-include unpv13e/tcpcliserv/subdir.mk
-include unpv13e/streams/stream_dg/subdir.mk
-include unpv13e/streams/subdir.mk
-include unpv13e/ssntp/subdir.mk
-include unpv13e/sockopt/subdir.mk
-include unpv13e/sock/subdir.mk
-include unpv13e/sigio/subdir.mk
-include unpv13e/server/subdir.mk
-include unpv13e/select/subdir.mk
-include unpv13e/sctp/subdir.mk
-include unpv13e/rtt/subdir.mk
-include unpv13e/route/subdir.mk
-include unpv13e/ping/subdir.mk
-include unpv13e/oob/subdir.mk
-include unpv13e/nonblock/subdir.mk
-include unpv13e/names/subdir.mk
-include unpv13e/mysdr/subdir.mk
-include unpv13e/mcast/subdir.mk
-include unpv13e/libroute/subdir.mk
-include unpv13e/libgai/old/subdir.mk
-include unpv13e/libgai/subdir.mk
-include unpv13e/libfree/subdir.mk
-include unpv13e/lib/subdir.mk
-include unpv13e/key/subdir.mk
-include unpv13e/ipopts/subdir.mk
-include unpv13e/ioctl/subdir.mk
-include unpv13e/intro/subdir.mk
-include unpv13e/inetd/subdir.mk
-include unpv13e/icmpd/subdir.mk
-include unpv13e/debug/subdir.mk
-include unpv13e/bcast/subdir.mk
-include unpv13e/advio/old/subdir.mk
-include unpv13e/advio/subdir.mk
-include lib/Asgn3_code/subdir.mk
-include lib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: PSSR-WITH-MULTICASTING

# Tool invocations
PSSR-WITH-MULTICASTING: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	gcc  -o "PSSR-WITH-MULTICASTING" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) PSSR-WITH-MULTICASTING
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
