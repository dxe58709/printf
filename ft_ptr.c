/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:15 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/12 14:57:44 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(uintptr_t n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	ptr_hex(uintptr_t n)
{
	int	fd;

	fd = 0;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(fd, n + '0');
		else
			ft_putchar(fd, 'a' + (n - 10));
	}
	else
	{
		ft_print_hex(fd, n / 16);
		ft_print_hex(fd, n % 16);
	}
}

int	ft_ptr(const void *ptr)
{
	uintptr_t	n;
	int			count;
	int			fd;

	fd = 0;
	n = (uintptr_t)ptr;
	count = count_ptr(n);
	ft_putstr(fd, "0x");
	if (count == 0)
		ft_putchar(fd, '0');
	else
		ptr_hex(n);
	return (count);
}

