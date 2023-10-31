/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:22:29 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/31 18:04:29 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_msg(pid_t server_pid, char *msg)
{
	int				bits;
	unsigned char	c;

	while(*msg)
	{
		bits = 8;
		c = *msg++;
		while(bits--)
		{	
			kill(server_pid, (c & 0x80) ? SIGUSR1 : SIGUSR2);
			usleep(50);
			c <<= 1;
		}
	}
}

void	detect_error(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc != 3)
	{
		ft_printf("Correct use: ./client [server PID] [message]\n");
		return ;
	}
	while(argv[1][i])
	{	
		if(!ft_isdigit(argv[1][i++]))
		{
			ft_printf("Invalid PID\n");
			return ;
		}
	}
}

int main(int argc, char **argv)
{
	pid_t server_pid;
	
	detect_error(argc, argv);
	server_pid = (pid_t)ft_atoi(argv[1]);
	ft_send_msg(server_pid, argv[2]);
	// while(1)
	// 	pause();
//	return (EXIT_SUCCESS);
	return (0);
}
