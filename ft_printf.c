/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:03 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/10 14:03:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	ssize_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			return (ft_putchar(fd, fmt[i]));
			continue ;
		}
		i++;
		if (fmt[i] == '%')
			return (ft_putchar(fd, fmt[i]));
		else if (fmt[i] == 'c')
			return (ft_putchar(fd, va_arg(ap, int)));
		else if (fmt[i] == 's')
			return (ft_putstr(fd, va_arg(ap, const char *)));
		else if (fmt[i] == 'u')
			return (ft_print_unbr(fd, va_arg(ap, unsigned int)));
		else if (fmt[i] == 'x')
			return (ft_print_hex(fd, va_arg(ap, unsigned int)));
		else if (fmt[i] == 'X')
			return (ft_print_hex(fd, va_arg(ap, unsigned int)));
		else if (fmt[i] == 'd')
			return (ft_print_nbr(va_arg(ap, int)));
		else if (fmt[i] == 'p')
			return (ft_ptr(va_arg(ap, void *)));
		else if (fmt[i] == 'i')
			return (ft_print_nbr(va_arg(ap, int)));
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	count;

	va_start(ap, fmt);
	count = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	count++;
	va_end(ap);
	return (count);
}
