/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:43:22 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/02 16:18:42 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(pid_t server_pid, unsigned char c)
{
	unsigned int	bits;

	bits = 0;
	while (++bits <= 8)
	{
		if (c & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(200);
		c >>= 1;
	}
}

void	ft_send_msg(pid_t server_pid, char *msg)
{
	static int		bits;
	unsigned char	c;

	while (*msg)
	{
		bits = 0;
		c = *msg++;
		while (++bits <= 8)
		{
			if (c & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(200);
			c >>= 1;
		}
	}
	if (!*msg)
		ft_send_char(server_pid, *msg);
}

void	detect_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Correct use: ./client [server PID] [message]\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("Invalid PID\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	msg_status(int sig, siginfo_t *info, void *cont)
{
	(void) cont;
	(void) info;
	if (sig == SIGUSR1)
		ft_printf("Server receiving.\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa_status;

	sa_status.sa_sigaction = &msg_status;
	sa_status.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_status, NULL);
	detect_error(argc, argv);
	server_pid = (pid_t)ft_atoi(argv[1]);
	ft_send_char(server_pid, 10);
	ft_send_msg(server_pid, argv[2]);
	while (1)
		pause ();
	return (EXIT_SUCCESS);
}
