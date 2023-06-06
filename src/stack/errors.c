/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:45:55 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 14:58:43 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	valid_atoi(const char *str)
{
	int	i;
	int	digits;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	digits = 0;
	while ((str[i] >= '0' && str[i] <= '9') || ft_isspace(str[i]))
	{
		i++;
		digits++;
	}
	if (str[i] || digits == 0 || digits > 10)
		return (0);
	return (1);
}

int	already_exists(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
		if (stack->pile[i--] == n)
			return (1);
	i--;
	return (0);
}

int	already_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	if (i <= 1)
		return (1);
	while (i >= 0)
	{
		if (i == 0)
			break ;
		if (stack->pile[i] > stack->pile[i - 1])
			return (0);
		i--;
	}
	return (1);
}
