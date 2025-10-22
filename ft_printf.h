/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:39:30 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/22 11:05:49 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *input, ...);
static void	print(const char type, va_list args, int *printed_chars);
void		puthex_fd(unsigned long num, const char format, int *printed_chars);
void		putstr_fd(char *s, int fd, int *printed_chars);
void		putnbr_fd(int n, int fd, int *printed_chars);

#endif
