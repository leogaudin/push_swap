/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:52:01 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:37:27 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Find the index of the closest superior value in the stack.
 *
 * @param    stack     The stack to scan.
 * @param    value     The value to compare.
 * @return             The index of the closest superior value.
 */
static int	get_directly_above_index(t_stack *stack, int value)
{
	int	i;
	int	closest;

	if (stack == NULL || stack->top < 0)
		return (-1);
	i = 0;
	closest = -1;
	while (i <= stack->top)
	{
		if (stack->pile[i] > value && (closest == -1
				|| stack->pile[i] < stack->pile[closest]))
			closest = i;
		i++;
	}
	return (closest);
}

/**
 * @brief    Find the index of the closest inferior value in the stack.
 *
 * @param    stack     The stack to scan.
 * @param    value     The value to compare.
 * @return             The index of the closest inferior value.
 */
static int	get_directly_below_index(t_stack *stack, int value)
{
	int	i;
	int	closest;

	if (stack == NULL || stack->top < 0)
		return (-1);
	i = 0;
	closest = -1;
	while (i <= stack->top)
	{
		if (stack->pile[i] < value && (closest == -1
				|| stack->pile[i] > stack->pile[closest]))
			closest = i;
		i++;
	}
	return (closest);
}
