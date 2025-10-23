/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:29:18 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/23 12:02:29 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(const char type, va_list args, int *printed_chars)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*printed_chars)++;
	}
	else if (type == 's')
		putstr_fd(va_arg(args, char *), 1, printed_chars);
	else if (type == 'd' || type == 'i')
		putnbr_fd(va_arg(args, int), 1, printed_chars);
	else if (type == 'u')
		putunsnbr_fd(va_arg(args, unsigned int), 1, printed_chars);
	else
		print_hex(type, args, printed_chars);
}

void	print_hex(const char type, va_list args, int *printed_chars)
{
	unsigned long	ptr_value;

	if (type == 'p')
	{
		ptr_value = va_arg(args, unsigned long);
		if (!ptr_value)
			putstr_fd("(nil)", 1, printed_chars);
		else
		{
			putstr_fd("0x", 1, printed_chars);
			puthex_fd(ptr_value, 0, printed_chars);
		}
	}
	else if (type == 'x')
		puthex_fd(va_arg(args, unsigned int), 0, printed_chars);
	else if (type == 'X')
		puthex_fd(va_arg(args, unsigned int), 1, printed_chars);
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		(*printed_chars)++;
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	va_start(args, input);
	printed_chars = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
		{
			ft_putchar_fd(input[i], 1);
			i++;
			printed_chars++;
			continue ;
		}
		if (input[++i])
		{
			print(input[i], args, &printed_chars);
			i++;
		}
	}
	va_end(args);
	return (printed_chars);
}
/*
#include <stdio.h>

int	main(void)
{
	int				num;
	unsigned int	unum;
	char			c;
	char			*str;
	void			*ptr;
	int				countft;
	int				countstdio;

	num = -42;
	unum = 42;
	c = 'Z';
	str = "Hola Mundo";
	ptr = &num;
	printf("%%c\n\n");
	countft = ft_printf("ft_printf: %c\n", c);
	countstdio = printf("printf:    %c\n", c);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%s\n");
	countft = ft_printf("ft_printf: %s\n", str);
	countstdio = printf("printf:    %s\n", str);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%p\n");
	countft = ft_printf("ft_printf: %p\n", ptr);
	countstdio = printf("printf:    %p\n", ptr);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%d\n");
	countft = ft_printf("ft_printf: %d\n", num);
	countstdio = printf("printf:    %d\n", num);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%i\n");
	countft = ft_printf("ft_printf: %i\n", num);
	countstdio = printf("printf:    %i\n", num);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%u\n");
	countft = ft_printf("ft_printf: %u\n", unum);
	countstdio = printf("printf:    %u\n", unum);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%x\n");
	countft = ft_printf("ft_printf: %x\n", unum);
	countstdio = printf("printf:    %x\n", unum);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%X\n");
	countft = ft_printf("ft_printf: %X\n", unum);
	countstdio = printf("printf:    %X\n", unum);
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	printf("%%\n");
	countft = ft_printf("ft_printf: [%%]\n");
	countstdio = printf("printf:    [%%]\n");
	printf("countft: %d | countstdio: %d\n\n", countft, countstdio);
	ft_printf("\n\n\n");
	printf("\ncountft: %d | countstdio: %d\n", countft, countstdio);
	return (0);
}
*/