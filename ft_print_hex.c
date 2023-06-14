/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: N <nsakanou@student.42tokyo.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:43 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/14 15:56:57 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	ft_puthex(unsigned int n, const char format)
{
	int	fd;
	int	count;

	fd = 0;
	count = 0;
	if (n < 16)
	{
		if (n < 10)
			count += ft_putchar(fd, n + '0');
		else if (format == 'x')
			count += ft_putchar(fd, 'a' + (n - 10));
		else if (format == 'X')
			count += ft_putchar(fd, 'A' + (n - 10));
	}
	else
	{
		count += ft_puthex(n / 16, format);
		if (format == 'x')
			count += ft_putchar(fd, 'a' + (n % 16));
		else if (format == 'X')
			count += ft_putchar(fd, 'A' + (n % 16));
	}
	count += count_hex(n);
	return (count);
}
/*
int	ft_print_hex(unsigned int n, const char fmt)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_puthex(n, fmt);
		count = 1;
	}
	else
	{
		ft_puthex(n, fmt);
		count += count_hex(n);
	}
	return (count);
}*/

