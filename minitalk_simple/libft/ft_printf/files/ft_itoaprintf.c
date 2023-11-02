/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:39:11 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/02 06:26:31 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoaf(int n)
{
	char			*s;
	long int		size;
	unsigned int	aux;

	size = countnbr(n);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (0);
	s[size--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		aux = n * -1;
		s[0] = '-';
	}
	else
		aux = n;
	s = set_nbr_str(aux, s, size);
	return (s);
}
