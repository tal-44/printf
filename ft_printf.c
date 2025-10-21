

# include "printf.h"

void    print(const char type, va_list *args, int *printed_chars)
{
    if (type == 'c')
    {
        ft_putchar_fd(va_arg(args, int), 1);
        (*printed_chars)++;
    }
    else if (type == 's')
        putstr_fd(va_arg(args, char *), 1, printed_chars);
    else if (type == 'p')
        puthex_fd(va_arg(args, unsigned long), 0, printed_chars);
    else if (type == 'd')
        putnbr_fd(va_arg(args, int), 1, printed_chars);
    else if (type == 'i')
        putnbr_fd(va_arg(args, int), 1, printed_chars);
    else if (type == 'u')
        putnbr_fd(va_arg(args, unsigned int), 1, printed_chars);
    else if (type == 'x')
        puthex_fd(va_arg(args, unsigned long), 0, printed_chars);
    else if (type == 'X')
        puthex_fd(va_arg(args, unsigned long), 1, printed_chars);
    else if (type == '%')
    {
        ft_putchar_fd('%', 1);
        (*printed_chars)++;
    }
}


int ft_printf(const char *input, ...)
{
    va_list  args;
    int      i;
    int      printed_chars;

    va_start(args, input);
    printed_chars = 0;
    i = 0;
    while (input[i])
    {
        if (input[i] == '%' && input[i + 1])
        {
            i++;
            print(input[i], &args, &printed_chars);
            i++;
        }
        else
        {
            ft_putchar_fd(input[i], 1);
            printed_chars++;
            i++;
        }
    }
    va_end(args);
    return (printed_chars);
}



#include <stdio.h>

int main(void)
{
    int num = -42;
    unsigned int unum = 42;
    char c = 'Z';
    char *str = "Hola Mundo";
    void *ptr = &num;
    int countft;
    int countstdio;

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
    
    ft_printf("\n\n\n")

    countft = ft_printf("ft_printf: Char: %c | String: %s | Ptr: %p | Dec: %d | Int: %i | Unsigned: %u | Hex: %x | HEX: %X | Porcentaje: %%\n", c, str, ptr, num, num, unum, unum, unum);
    countstdio = printf("printf:    Char: %c | String: %s | Ptr: %p | Dec: %d | Int: %i | Unsigned: %u | Hex: %x | HEX: %X | Porcentaje: %%\n", c, str, ptr, num, num, unum, unum, unum);

    printf("\ncountft: %d | countstdio: %d\n", countft, countstdio);

    return 0;
}