/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:32:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 13:53:49 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack->pile[i];
	index = i;
	while (i <= stack->top)
	{
		if (stack->pile[i] < min)
		{
			min = stack->pile[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = stack->pile[i];
	index = i;
	while (i <= stack->top)
	{
		if (stack->pile[i] > max)
		{
			max = stack->pile[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_size(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
		i++;
	return (i);
}
