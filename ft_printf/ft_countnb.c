/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:06:30 by aavezou           #+#    #+#             */
/*   Updated: 2021/12/07 12:10:44 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnb(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n = n * -1;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count = count + 1;
	}
	return (count);
}

int	ft_countnbu(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n = n * -1;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count = count + 1;
	}
	return (count);
}

int	ft_countnbhexa(unsigned long long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 16;
		count = count + 1;
	}
	return (count);
}
