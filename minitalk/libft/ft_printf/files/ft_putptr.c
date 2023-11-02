/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:20:12 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/01 15:54:59 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(unsigned long long num, int fd)
{
	int					x;

	x = 0;
	if (num == 0)
		return (write (fd, "0", 1));
	if (num < 16)
	{
		return (write (fd, &"0123456789abcdef"[num], 1));
	}
	else
	{
		x += ft_putptr(num / 16, fd);
		x += ft_putptr(num % 16, fd);
	}
	return (x);
}

int	ft_putptr0x(unsigned long long num, int fd)
{
	write (fd, "0", 1);
	write (fd, "x", 1);
	return ((ft_putptr(num, fd) + 2));
}
