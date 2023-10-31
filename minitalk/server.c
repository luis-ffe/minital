/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:22:42 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/31 18:17:27 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void	handler(int sig)
{
	char	c;
	int		i;
	
	i = 8;
	c = 0;
	while(--i >= 0)
	{
		if (sig == SIGUSR1)
			c |= (1 << i);
 		else
			c |= (0 << i);
	}
	write(1, &c, 1);
}

int	main(void)
{
	struct sigaction	serv_act;
	serv_act.sa_handler = &handler;
	ft_printf("Server PID: %d\n", getpid());
	while(1)
    {
		sigaction(SIGUSR1, &serv_act, 0);
		sigaction(SIGUSR2, &serv_act, 0);
        pause();
    }
    return (0);
}
