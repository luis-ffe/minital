/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:04:02 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/02 06:24:56 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	list;

	va_start(list, input);
	i = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input != '%' && *input)
			{
				i += ft_typefinder(*input, list);
			}
			else
				i += ft_putchar_fdf(*input, 1);
		}
		else
			i += ft_putchar_fdf(*input, 1);
		input++;
	}
	va_end(list);
	return (i);
}
