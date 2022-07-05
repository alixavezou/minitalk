# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 18:56:56 by aavezou           #+#    #+#              #
#    Updated: 2021/12/06 20:04:51 by aavezou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

C_FILES = 	ft_putchar \
			ft_putcharcount \
			ft_putnbr \
			ft_putstrcount \
			ft_countnb \
			ft_checktype \
			ft_libftprintf \
			ft_printandcount \

CFILES = $(addsuffix .c, $(C_FILES))
O_FILES = $(addsuffix .o, $(C_FILES))

HDRS = libftprintf.h

.c.o:
	$(CC) $(CFLAGS) -c -g $< -o $(<:.c=.o)

$(NAME): $(O_FILES)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re