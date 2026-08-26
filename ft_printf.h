/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuozturk@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:49:32 by yuozturk          #+#    #+#             */
/*   Updated: 2026/08/25 18:03:26 by yuozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_toupper(int c);
int		ft_putstr(char *str);
void	ft_putchr(char c);
int		ft_puthex(unsigned long n, char flag);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strfind(const char *s1, char c);
int		ft_print_chr(char c);
int		ft_print_hex(unsigned long hex, const char *flag);
int		ft_print_num(long n);
int		ft_print_str(char *str);
int		ft_printf(const char *str, ...);

#endif