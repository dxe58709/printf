#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int	ft_printf(const char *fmt, ...);
int     ft_printunbr(unsigned int n);
int     ft_printnbr(int n);
void    ft_print_hex(unsigned int n, const char format);
void    ft_ptr(const void *ptr);
void    ft_putchar(char c);
void    ft_putstr(const char *s);

#endif
