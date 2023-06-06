/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:32:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:28:56 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Find the index of the minimum value in the stack.
 *
 * @param    stack     The stack to scan.
 * @return             The index of the maximum value.
 */
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

/**
 * @brief    Find the index of the maximum value in the stack.
 *
 * @param    stack     The stack to scan.
 * @return             The index of the maximum value.
 */
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

/**
 * @brief    Scans the stack from the top to find the index of the first
 * element within the specified range.
 *
 * @param    stack     The stack to scan.
 * @param    min       The minimum value of the range.
 * @param    max       The maximum value of the range.
 * @return             The index of the first element within the range, or -1
 *                     if not found.
 */
int	scan_from_top(t_stack *stack, int min, int max)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->pile[i] >= min && stack->pile[i] <= max)
			return (i);
		i--;
	}
	return (-1);
}

/**
 * @brief    Scans the stack from the bottom to find the index of the first
 * element within the specified range.
 *
 * @param    stack     The stack to scan.
 * @param    min       The minimum value of the range.
 * @param    max       The maximum value of the range.
 * @return             The index of the first element within the range, or -1
 *                     if not found.
 */
int	scan_from_bottom(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->pile[i] >= min && stack->pile[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}
