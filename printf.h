# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int     ft_printf(const char *, ...);
void    puthex_fd(unsigned long num, const char format, int *printed_chars);
void    putstr_fd(char *s, int fd, int *printed_chars);
void    putnbr_fd(int n, int fd, int *printed_chars);

# endif