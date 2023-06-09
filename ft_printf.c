#include "printf.h"

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	ssize_t	i;
	ssize_t	count;//出力したバイト数を追跡するため

	i = 0;
	count = 0:
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			count +=ft_putchar(fmt[i]);
			continue;//ループ内のある条件を満たした場合に、その時点での処理をスキップして次の繰り返しに進む
		}
		i++;
		if (fmt[i] == '%')
			count +=ft_putchar(fmt[i]);
		else if (fmt[i] == 'c')
			count +=ft_putchar(va_arg(ap, int));
		else if (fmt[i] == 's')
			count +=ft_putstr(va_arg(ap, char *));
		else if (fmt[i] == 'u')
			count +=ft_print_unbr(va_arg(ap, unsigned int));
		else if (fmt[i] == 'x') 
			count +=ft_print_hex(va_arg(ap, unsigned int));
		else if (fmt[i] == 'X')
			count +=ft_print_hex(va_arg(ap, unsigned int));
		else if (fmt[i] == 'd')
			count +=ft_print_nbr(va_arg(ap, int));
		else if (fmt[i] == 'p')
			count +=ft_ptr(va_arg(ap, void *));
		else if (fmt[i] == 'i')
			count +=ft_print_nbr(va_arg(ap, int));;
		}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	va_start(ap, fmt);
	int	count;

	count = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (count);
}
