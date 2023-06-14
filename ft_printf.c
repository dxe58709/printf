/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:03 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/14 15:10:27 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_judge_format(int fd, const char *fmt, va_list ap, ssize_t count)
{
	ssize_t	i;

	i = 0;
	if (fmt[i] == '%')
		count += ft_putchar(fd, fmt[i]);
	else if (fmt[i] == 'c')
		count += ft_putchar(fd, va_arg(ap, int));
	else if (fmt[i] == 's')
		count += ft_putstr(fd, va_arg(ap, const char *));
	else if (fmt[i] == 'u')
		count += ft_print_unbr(fd, va_arg(ap, unsigned int));
	else if (fmt[i] == 'x' || fmt[i] == 'X')
		count += ft_print_hex(fd, va_arg(ap, unsigned int));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	// else if (fmt[i] == 'p')
	// 	count += ft_ptr(va_arg(ap, void *));
	return (count);
}

int	fmt_count(int fd, const char *fmt, va_list ap)
{
	ssize_t	i;
	ssize_t	count;

	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			count = ft_judge_format(fd, &fmt[i], ap, count);
			i++;
			continue ;
		}
		else
			count += ft_putchar(fd, fmt[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	count;

	va_start(ap, fmt);
	count = fmt_count(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (count);
}

 #include <stdio.h>

 int	main()
 {
 	int	count1;
 	int	count2;
 	int	x = -100;
 	// int	num = 42;
 	// int	*ptr = &num;

 	// count1 = printf("%p\n", (void *)ptr);
 	// count2 = ft_printf("%p\n", (void *)ptr);

 	count1 = printf("%x\n", x);
 	count2 = ft_printf("%x\n", x);
 	printf("%d\n", count1);
 	printf("%d\n", count2);
 }
