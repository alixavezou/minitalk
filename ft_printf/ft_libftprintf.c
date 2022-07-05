/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:56:53 by aavezou           #+#    #+#             */
/*   Updated: 2021/12/06 19:43:45 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *dest, ...)
{
	va_list		args;
	const char	*s;
	int			i;
	int			count;

	s = dest;
	i = 0;
	count = 0;
	va_start(args, dest);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_checktype(s[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (i + count);
}
