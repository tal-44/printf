/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:29:32 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/22 11:09:59 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 0 for lowercase, 1 for uppercase
void	puthex_fd(unsigned long num, const char format, int *printed_chars)
{
	char	*cadena_hex;

	if (num == (NULL))
	{
		putstr_fd("(null)", 1, printed_chars);
		return ;
	}
	cadena_hex = "0123456789abcdef";
	if (num >= 16)
		puthex_fd(num / 16, format, printed_chars);
	if (format == 0)
		ft_putchar_fd(cadena_hex[num % 16], 1);
	else
		ft_putchar_fd(ft_toupper(cadena_hex[num % 16]), 1);
	(*printed_chars)++;
}

void	putstr_fd(char *s, int fd, int *printed_chars)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
	{
		ft_putchar_fd(s[i], fd);
		(*printed_chars)++;
	}
}

void	putnbr_fd(int n, int fd, int *printed_chars)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		putnbr_fd((int)(num / 10), fd, printed_chars);
	ft_putchar_fd((char)('0' + (num % 10)), fd);
	(*printed_chars)++;
}
