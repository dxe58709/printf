/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:11 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/09 20:03:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int		ft_printf(int fd, const char *fmt, ...);
int		ft_print_unbr(unsigned int n);
int		ft_print_nbr(int n);
void	ft_print_hex(unsigned int n, const char format);
void	ft_ptr(const void *ptr);
void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, const char *s);

#endif
