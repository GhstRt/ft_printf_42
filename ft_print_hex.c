/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuozturk@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:45:19 by yuozturk          #+#    #+#             */
/*   Updated: 2026/08/26 16:51:05 by yuozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long hex, const char *flag)
{
	if (flag[0] == 'p')
	{
		if (hex == 0)
		{
			ft_putstr("(nil)");
			return (5);
		}
		ft_putstr("0x");
		return (ft_puthex(hex, flag[0]) + 2);
	}
	return (ft_puthex(hex, flag[0]));
}
