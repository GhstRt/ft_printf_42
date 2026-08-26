/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuozturk@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:49:19 by yuozturk          #+#    #+#             */
/*   Updated: 2026/08/26 17:55:07 by yuozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(const char *str, va_list args)
{
	int	total;

	total = 0;
	if (ft_strnstr(str, "%c", 2))
		total += ft_print_chr((char)va_arg(args, int));
	else if (ft_strnstr(str, "%s", 2))
		total += ft_print_str(va_arg(args, char *));
	else if (ft_strnstr(str, "%d", 2) || ft_strnstr(str, "%i", 2))
		total += ft_print_num(va_arg(args, int));
	else if (ft_strnstr(str, "%u", 2))
		total += ft_print_num(va_arg(args, unsigned int));
	else if (ft_strnstr(str, "%x", 2) || ft_strnstr(str, "%X", 2))
		total += ft_print_hex(va_arg(args, unsigned int), str + 1);
	else if (ft_strnstr(str, "%p", 2))
		total += ft_print_hex((unsigned long)va_arg(args, void *), str + 1);
	else if (ft_strnstr(str, "%%", 2))
		total += ft_print_chr('%');
	return (total);
}

static int	integrity_check(const char *str)
{
	int		i;
	char	*usable;

	i = 0;
	usable = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1] || ft_strfind(usable, str[i + 1]) == 0)
				return (0);
			i += 2;
		}
		else
			i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list	args;

	i = 0;
	total = 0;
	if (!integrity_check(str))
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			total += format_check(&str[i], args);
			i += 2;
		}
		else
		{
			ft_print_chr(str[i]);
			total++;
			i++;
		}
	}
	va_end(args);
	return (total);
}
