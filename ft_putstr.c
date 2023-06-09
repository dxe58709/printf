/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:21 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/09 19:57:14 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

ssize_t	ft_putstr(int fd, const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{	
		count += ft_putchar(fd, *str);
		str++;
	}
	return (count);
}

