/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:56:20 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/02 06:24:37 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fdf(int n, int fd)
{
	char	*s;
	int		x;

	x = 0;
	s = ft_itoaf(n);
	x = ft_putstr_fdf(s, fd);
	free(s);
	return (x);
}
