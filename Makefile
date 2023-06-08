NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_print_nbr.c \
	ft_print_unbr.c \
	ft_print_hex.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_ptr.c \
	ft_printf.c \
 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)

re: fclean all

