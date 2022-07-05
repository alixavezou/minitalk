/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:22:34 by aavezou           #+#    #+#             */
/*   Updated: 2021/12/07 12:12:24 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
		return ;
	}
	else if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putnbru(unsigned int n)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbru(n * (-1));
	}
	else
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
}

void	ft_putnbrx(unsigned int n, char *base)
{
	if (n > 15)
	{
		ft_putnbrx(n / 16, base);
	}
	ft_putchar(base[(n % 16)]);
}

void	ft_putnbrhexap(unsigned long long int n, char *base)
{
	if (n > 15)
	{
		ft_putnbrhexap(n / 16, base);
	}
	ft_putchar(base[(n % 16)]);
}
