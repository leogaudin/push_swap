/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:19 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/22 16:08:09 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	star;
	int	plus;
	int	hash;
	int	space;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_hexa(unsigned long long n, char c, t_flags *flags);
int		ft_print_pointer(unsigned long long p, t_flags *flags);
int		ft_print_int(int n, t_flags *flags);
int		ft_print_unsigned(unsigned int n);
int		ft_print_percent(void);
int		ft_parser(const char *format, int *i, va_list *args);
int		ft_intlen(long n);
int		ft_parse_width(const char *format, int *i, t_flags *flags,
			va_list *args);
int		ft_print_padding(int width, int len, char c);

#endif
