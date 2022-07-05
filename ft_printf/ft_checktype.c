/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:54:08 by aavezou           #+#    #+#             */
/*   Updated: 2021/12/07 11:58:03 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(char b, va_list args)
{
	int	count;

	count = 0;
	if (b == 'c')
		count = ft_putcharcount(va_arg(args, int));
	else if (b == 'd' || b == 'i')
		count = ft_printandcount(va_arg(args, int));
	else if (b == 's')
		count = ft_putstrcount(va_arg(args, char *));
	else if (b == 'p')
	{
		count = ft_putcharcount('0');
		count = ft_putcharcount('x');
		count = ft_printandcountptr(va_arg(args, unsigned long long int));
	}
	else if (b == 'u')
		count = ft_printandcountu(va_arg(args, unsigned int));
	else if (b == 'x')
		count = ft_printandcounthexa(va_arg(args, unsigned int));
	else if (b == 'X')
		count = ft_printandcountbigx(va_arg(args, unsigned int));
	else if (b == '%')
		count = ft_putcharcount('%');
	return (count);
}
