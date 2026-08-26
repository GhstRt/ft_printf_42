/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuozturk@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:15:59 by yuozturk          #+#    #+#             */
/*   Updated: 2026/08/26 16:53:05 by yuozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char flag)
{
	char	*hex_chars;
	int		count;

	hex_chars = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, flag);
	if (flag == 'X')
		ft_putchr(ft_toupper(hex_chars[n % 16]));
	else
		ft_putchr(hex_chars[n % 16]);
	return (count + 1);
}
