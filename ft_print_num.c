/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuozturk@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 13:41:20 by yuozturk          #+#    #+#             */
/*   Updated: 2026/08/26 16:57:11 by yuozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchr('-');
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_print_num(n / 10);
	ft_putchr((n % 10) + '0');
	return (++count);
}
