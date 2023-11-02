/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:22:42 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/02 11:42:58 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *cont)
{
	static unsigned char	c = 0;
	static int				bit = 0;

	(void) cont;
	(void) info;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			c |= (1 << bit);
		else
			c |= 0;
		bit++;
		if (bit == 8)
		{
			write (1, &c, 1);
			bit = 0;
			c = 0;
		}
	}
	else
		ft_printf("Unexpected signal received: %d\n", sig);
}

void	set_sigaction(void)
{
	struct sigaction	serv_act;

	serv_act.sa_sigaction = &handler;
	serv_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &serv_act, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &serv_act, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_printf("Server PID: %d", getpid());
	set_sigaction();
	while (1)
		pause ();
	return (0);
}
