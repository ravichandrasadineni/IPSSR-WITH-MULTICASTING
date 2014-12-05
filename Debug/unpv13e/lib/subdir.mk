################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../unpv13e/lib/connect_nonb.o \
../unpv13e/lib/connect_timeo.o \
../unpv13e/lib/daemon_inetd.o \
../unpv13e/lib/daemon_init.o \
../unpv13e/lib/dg_cli.o \
../unpv13e/lib/dg_echo.o \
../unpv13e/lib/error.o \
../unpv13e/lib/family_to_level.o \
../unpv13e/lib/get_ifi_info.o \
../unpv13e/lib/gf_time.o \
../unpv13e/lib/host_serv.o \
../unpv13e/lib/mcast_get_if.o \
../unpv13e/lib/mcast_get_loop.o \
../unpv13e/lib/mcast_get_ttl.o \
../unpv13e/lib/mcast_join.o \
../unpv13e/lib/mcast_leave.o \
../unpv13e/lib/mcast_set_if.o \
../unpv13e/lib/mcast_set_loop.o \
../unpv13e/lib/mcast_set_ttl.o \
../unpv13e/lib/my_addrs.o \
../unpv13e/lib/read_fd.o \
../unpv13e/lib/readable_timeo.o \
../unpv13e/lib/readline.o \
../unpv13e/lib/readn.o \
../unpv13e/lib/rtt.o \
../unpv13e/lib/signal.o \
../unpv13e/lib/signal_intr.o \
../unpv13e/lib/sock_bind_wild.o \
../unpv13e/lib/sock_cmp_addr.o \
../unpv13e/lib/sock_cmp_port.o \
../unpv13e/lib/sock_get_port.o \
../unpv13e/lib/sock_ntop.o \
../unpv13e/lib/sock_ntop_host.o \
../unpv13e/lib/sock_set_addr.o \
../unpv13e/lib/sock_set_port.o \
../unpv13e/lib/sock_set_wild.o \
../unpv13e/lib/sockfd_to_family.o \
../unpv13e/lib/str_cli.o \
../unpv13e/lib/str_echo.o \
../unpv13e/lib/tcp_connect.o \
../unpv13e/lib/tcp_listen.o \
../unpv13e/lib/tv_sub.o \
../unpv13e/lib/udp_client.o \
../unpv13e/lib/udp_connect.o \
../unpv13e/lib/udp_server.o \
../unpv13e/lib/wraplib.o \
../unpv13e/lib/wrappthread.o \
../unpv13e/lib/wrapsock.o \
../unpv13e/lib/wrapstdio.o \
../unpv13e/lib/wrapunix.o \
../unpv13e/lib/writable_timeo.o \
../unpv13e/lib/write_fd.o \
../unpv13e/lib/writen.o 

C_SRCS += \
../unpv13e/lib/connect_nonb.c \
../unpv13e/lib/connect_timeo.c \
../unpv13e/lib/daemon_inetd.c \
../unpv13e/lib/daemon_init.c \
../unpv13e/lib/dg_cli.c \
../unpv13e/lib/dg_echo.c \
../unpv13e/lib/error.c \
../unpv13e/lib/family_to_level.c \
../unpv13e/lib/get_ifi_info.c \
../unpv13e/lib/gf_time.c \
../unpv13e/lib/host_serv.c \
../unpv13e/lib/hstrerror.c \
../unpv13e/lib/if_indextoname.c \
../unpv13e/lib/if_nameindex.c \
../unpv13e/lib/if_nametoindex.c \
../unpv13e/lib/in6addr_any.c \
../unpv13e/lib/mcast_get_if.c \
../unpv13e/lib/mcast_get_loop.c \
../unpv13e/lib/mcast_get_ttl.c \
../unpv13e/lib/mcast_join.c \
../unpv13e/lib/mcast_leave.c \
../unpv13e/lib/mcast_set_if.c \
../unpv13e/lib/mcast_set_loop.c \
../unpv13e/lib/mcast_set_ttl.c \
../unpv13e/lib/my_addrs.c \
../unpv13e/lib/pselect.c \
../unpv13e/lib/read_fd.c \
../unpv13e/lib/readable_timeo.c \
../unpv13e/lib/readline.c \
../unpv13e/lib/readn.c \
../unpv13e/lib/rtt.c \
../unpv13e/lib/signal.c \
../unpv13e/lib/signal_intr.c \
../unpv13e/lib/snprintf.c \
../unpv13e/lib/sock_bind_wild.c \
../unpv13e/lib/sock_cmp_addr.c \
../unpv13e/lib/sock_cmp_port.c \
../unpv13e/lib/sock_get_port.c \
../unpv13e/lib/sock_ntop.c \
../unpv13e/lib/sock_ntop_host.c \
../unpv13e/lib/sock_set_addr.c \
../unpv13e/lib/sock_set_port.c \
../unpv13e/lib/sock_set_wild.c \
../unpv13e/lib/sockatmark.c \
../unpv13e/lib/sockfd_to_family.c \
../unpv13e/lib/str_cli.c \
../unpv13e/lib/str_echo.c \
../unpv13e/lib/tcp_connect.c \
../unpv13e/lib/tcp_listen.c \
../unpv13e/lib/tv_sub.c \
../unpv13e/lib/udp_client.c \
../unpv13e/lib/udp_connect.c \
../unpv13e/lib/udp_server.c \
../unpv13e/lib/wraplib.c \
../unpv13e/lib/wrappthread.c \
../unpv13e/lib/wrapsock.c \
../unpv13e/lib/wrapstdio.c \
../unpv13e/lib/wrapunix.c \
../unpv13e/lib/writable_timeo.c \
../unpv13e/lib/write_fd.c \
../unpv13e/lib/writen.c 

OBJS += \
./unpv13e/lib/connect_nonb.o \
./unpv13e/lib/connect_timeo.o \
./unpv13e/lib/daemon_inetd.o \
./unpv13e/lib/daemon_init.o \
./unpv13e/lib/dg_cli.o \
./unpv13e/lib/dg_echo.o \
./unpv13e/lib/error.o \
./unpv13e/lib/family_to_level.o \
./unpv13e/lib/get_ifi_info.o \
./unpv13e/lib/gf_time.o \
./unpv13e/lib/host_serv.o \
./unpv13e/lib/hstrerror.o \
./unpv13e/lib/if_indextoname.o \
./unpv13e/lib/if_nameindex.o \
./unpv13e/lib/if_nametoindex.o \
./unpv13e/lib/in6addr_any.o \
./unpv13e/lib/mcast_get_if.o \
./unpv13e/lib/mcast_get_loop.o \
./unpv13e/lib/mcast_get_ttl.o \
./unpv13e/lib/mcast_join.o \
./unpv13e/lib/mcast_leave.o \
./unpv13e/lib/mcast_set_if.o \
./unpv13e/lib/mcast_set_loop.o \
./unpv13e/lib/mcast_set_ttl.o \
./unpv13e/lib/my_addrs.o \
./unpv13e/lib/pselect.o \
./unpv13e/lib/read_fd.o \
./unpv13e/lib/readable_timeo.o \
./unpv13e/lib/readline.o \
./unpv13e/lib/readn.o \
./unpv13e/lib/rtt.o \
./unpv13e/lib/signal.o \
./unpv13e/lib/signal_intr.o \
./unpv13e/lib/snprintf.o \
./unpv13e/lib/sock_bind_wild.o \
./unpv13e/lib/sock_cmp_addr.o \
./unpv13e/lib/sock_cmp_port.o \
./unpv13e/lib/sock_get_port.o \
./unpv13e/lib/sock_ntop.o \
./unpv13e/lib/sock_ntop_host.o \
./unpv13e/lib/sock_set_addr.o \
./unpv13e/lib/sock_set_port.o \
./unpv13e/lib/sock_set_wild.o \
./unpv13e/lib/sockatmark.o \
./unpv13e/lib/sockfd_to_family.o \
./unpv13e/lib/str_cli.o \
./unpv13e/lib/str_echo.o \
./unpv13e/lib/tcp_connect.o \
./unpv13e/lib/tcp_listen.o \
./unpv13e/lib/tv_sub.o \
./unpv13e/lib/udp_client.o \
./unpv13e/lib/udp_connect.o \
./unpv13e/lib/udp_server.o \
./unpv13e/lib/wraplib.o \
./unpv13e/lib/wrappthread.o \
./unpv13e/lib/wrapsock.o \
./unpv13e/lib/wrapstdio.o \
./unpv13e/lib/wrapunix.o \
./unpv13e/lib/writable_timeo.o \
./unpv13e/lib/write_fd.o \
./unpv13e/lib/writen.o 

C_DEPS += \
./unpv13e/lib/connect_nonb.d \
./unpv13e/lib/connect_timeo.d \
./unpv13e/lib/daemon_inetd.d \
./unpv13e/lib/daemon_init.d \
./unpv13e/lib/dg_cli.d \
./unpv13e/lib/dg_echo.d \
./unpv13e/lib/error.d \
./unpv13e/lib/family_to_level.d \
./unpv13e/lib/get_ifi_info.d \
./unpv13e/lib/gf_time.d \
./unpv13e/lib/host_serv.d \
./unpv13e/lib/hstrerror.d \
./unpv13e/lib/if_indextoname.d \
./unpv13e/lib/if_nameindex.d \
./unpv13e/lib/if_nametoindex.d \
./unpv13e/lib/in6addr_any.d \
./unpv13e/lib/mcast_get_if.d \
./unpv13e/lib/mcast_get_loop.d \
./unpv13e/lib/mcast_get_ttl.d \
./unpv13e/lib/mcast_join.d \
./unpv13e/lib/mcast_leave.d \
./unpv13e/lib/mcast_set_if.d \
./unpv13e/lib/mcast_set_loop.d \
./unpv13e/lib/mcast_set_ttl.d \
./unpv13e/lib/my_addrs.d \
./unpv13e/lib/pselect.d \
./unpv13e/lib/read_fd.d \
./unpv13e/lib/readable_timeo.d \
./unpv13e/lib/readline.d \
./unpv13e/lib/readn.d \
./unpv13e/lib/rtt.d \
./unpv13e/lib/signal.d \
./unpv13e/lib/signal_intr.d \
./unpv13e/lib/snprintf.d \
./unpv13e/lib/sock_bind_wild.d \
./unpv13e/lib/sock_cmp_addr.d \
./unpv13e/lib/sock_cmp_port.d \
./unpv13e/lib/sock_get_port.d \
./unpv13e/lib/sock_ntop.d \
./unpv13e/lib/sock_ntop_host.d \
./unpv13e/lib/sock_set_addr.d \
./unpv13e/lib/sock_set_port.d \
./unpv13e/lib/sock_set_wild.d \
./unpv13e/lib/sockatmark.d \
./unpv13e/lib/sockfd_to_family.d \
./unpv13e/lib/str_cli.d \
./unpv13e/lib/str_echo.d \
./unpv13e/lib/tcp_connect.d \
./unpv13e/lib/tcp_listen.d \
./unpv13e/lib/tv_sub.d \
./unpv13e/lib/udp_client.d \
./unpv13e/lib/udp_connect.d \
./unpv13e/lib/udp_server.d \
./unpv13e/lib/wraplib.d \
./unpv13e/lib/wrappthread.d \
./unpv13e/lib/wrapsock.d \
./unpv13e/lib/wrapstdio.d \
./unpv13e/lib/wrapunix.d \
./unpv13e/lib/writable_timeo.d \
./unpv13e/lib/write_fd.d \
./unpv13e/lib/writen.d 


# Each subdirectory must supply rules for building sources it contributes
unpv13e/lib/%.o: ../unpv13e/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


