/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:43 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/09 13:40:19 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_hex(unsigned int n, const char format)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar('a' + (n - 10));
			if (format == 'X')
				ft_putchar('A' + (n - 10));
		}
	}
	else
	{
		ft_print_hex(n / 16, format);
		ft_print_hex(n % 16, format);
	}
}
