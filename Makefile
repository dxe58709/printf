# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 13:10:36 by nsakanou          #+#    #+#              #
#    Updated: 2024/01/24 21:02:28 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/ft_print_nbr.c \
	srcs/ft_printf.c \
	srcs/ft_ptr.c \
	srcs/ft_print_unbr.c \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_print_hex.c 
 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
