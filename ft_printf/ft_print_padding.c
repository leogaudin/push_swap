/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:14:42 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/22 13:15:00 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_padding(int width, int len, char c)
{
	int	count;

	count = 0;
	while (width - len > 0)
	{
		ft_putchar_fd(c, 1);
		count++;
		width--;
	}
	return (count);
}
