/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:03 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/09 20:37:00 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf.h"

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	ssize_t	i;
	ssize_t	count;

	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fd, fmt[i]);
			count++;
			continue ;
		}
		i++;
		if (fmt[i] == '%')
		{
			ft_putchar(fd, fmt[i]);
			count++;
		}
		else if (fmt[i] == 'c')
		{
			ft_putchar(fd, va_arg(ap, int));
			count++;
		}
		else if (fmt[i] == 's')
		{
			const char *str = va_arg(ap, const char *);
			ft_putstr(fd, str);
		}
		else if (fmt[i] == 'u')
			count += ft_print_unbr(va_arg(ap, unsigned int));
		else if (fmt[i] == 'x')
		{
			unsigned int num = va_arg(ap, unsigned int);
			ft_print_hex(fd, num);
		}
		else if (fmt[i] == 'X')
		{
			unsigned int num = va_arg(ap, unsigned int);
 			ft_print_hex(fd, num);
		}
		else if (fmt[i] == 'd')
			count += ft_print_nbr(va_arg(ap, int));
		else if (fmt[i] == 'p')
			ft_ptr(va_arg(ap, void *));
		else if (fmt[i] == 'i')
			count += ft_print_nbr(va_arg(ap, int));
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (count);
}
