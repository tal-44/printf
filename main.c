#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int num;
	unsigned int unum;
	char c;
	char *str;
	void *ptr;
	int countft;
	int countstdio;

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