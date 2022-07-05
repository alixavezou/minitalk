/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printandcount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:39 by aavezou           #+#    #+#             */
/*   Updated: 2021/12/07 12:11:53 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printandcount(int nb)
{
	ft_putnbr(nb);
	return (ft_countnb(nb) - 2);
}

int	ft_printandcountu(unsigned int nb)
{
	ft_putnbru(nb);
	return (ft_countnbu(nb) - 2);
}

int	ft_printandcountbigx(unsigned int nb)
{
	ft_putnbrx(nb, "0123456789ABCDEF");
	return (ft_countnbhexa(nb) - 2);
}

int	ft_printandcounthexa(unsigned int nb)
{
	ft_putnbrx(nb, "0123456789abcdef");
	return (ft_countnbhexa(nb) - 2);
}

int	ft_printandcountptr(unsigned long long int nb)
{
	ft_putnbrhexap(nb, "0123456789abcdef");
	return (ft_countnbhexa(nb));
}
