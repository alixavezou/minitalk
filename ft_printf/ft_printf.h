/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:52:57 by aavezou           #+#    #+#             */
/*   Updated: 2021/12/07 12:31:48 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putnbr(int n);
void	ft_putnbrx(unsigned int n, char *base);
void	ft_putnbrhexap(unsigned long long int n, char *base);
void	ft_putnbru(unsigned int n);
void	ft_putchar(char c);

int		ft_checktype(char b, va_list args);
int		ft_printf(const char *dest, ...);
int		ft_printandcounthexa(unsigned int nb);
int		ft_printandcountbigx(unsigned int nb);
int		ft_putcharcount(char b);
int		ft_printandcountptr(unsigned long long int nb);
int		ft_printandcount(int nb);
int		ft_putstrcount(char *s);
int		ft_countnbhexa(unsigned long long int n);
int		ft_countnb(int n);
int		ft_printandcountu(unsigned int nb);
int		ft_countnbu(unsigned int n);

#endif