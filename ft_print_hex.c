/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:43 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/12 17:14:31 by nsakanou         ###   ########.fr       */
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

void	ft_puthex(unsigned int n, const char format)
{
	int	fd;

	fd = 0;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(fd, n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(fd, 'a' + (n - 10));
			if (format == 'X')
				ft_putchar(fd, 'A' + (n - 10));
		}
	}
	else
	{
		ft_print_hex(n / 16, format);
		ft_print_hex(n % 16, format);
	}
}

int	ft_print_hex(unsigned int n, const char fmt)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_puthex(n, fmt);
		count++;
	}
	else
	{
		ft_puthex(n, fmt);
		count += count_hex(n);
	}
	return (count);
}
