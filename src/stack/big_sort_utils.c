/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:57:43 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:50:13 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Moves the elements within the specified range to the top of
 * the stack. The elements are moved in the most efficient way possible.
 *
 * @param    stack      The stack to modify.
 * @param    min        The minimum value of the range.
 * @param    max        The maximum value of the range.
 * @param    stack_name The name of the stack ('a' or 'b').
 */
void	move_in_range_to_top(t_stack *stack, int min, int max, char stack_name)
{
	if (get_min_cost(stack->top - scan_from_top(stack, min, max),
			scan_from_bottom(stack, min, max) + 1) == 1)
	{
		while (scan_from_bottom(stack, min, max) + 1 > 0 && stack->top
			- scan_from_top(stack, min, max) > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (scan_from_bottom(stack, min, max) + 1 > 0 && stack->top
			- scan_from_top(stack, min, max) > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

/**
 * @brief    Checks if the value is bigger than the biggest element of the
 * stack or smaller than the smallest element of the stack.
 *
 * @param    stack     The stack to check.
 * @param    value     The value to check.
 * @return             1 if the value is bigger than the biggest element of the
 * stack, -1 if the value is smaller than the smallest element of the stack,
 * and 0 otherwise.
 */
int	is_biggest_or_smallest(t_stack *stack, int value)
{
	int	i;
	int	biggest;
	int	smallest;

	i = stack->top;
	biggest = 0;
	smallest = 0;
	while (i >= 0)
	{
		if (stack->pile[i] > stack->pile[biggest])
			biggest = i;
		if (stack->pile[i] < stack->pile[smallest])
			smallest = i;
		i--;
	}
	if (value > stack->pile[biggest])
		return (1);
	else if (value < stack->pile[smallest])
		return (-1);
	return (0);
}

/**
 * @brief Checks the value of the element below the top element of stack_b
 *        and moves it to stack_a if it satisfies a specific condition.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param value The value of the top element of stack_a.
 */

/**
 * @brief    Pushes the value at the top of stack_a to stack_b in the most
 * efficient way possible.
 *
 * @param    stack_a
 * @param    stack_b
 * @param    value     The value of the top element of stack_a.
 */
void	smart_push_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	target;
	int	comparison;
	int	min_b;
	int	max_b;

	min_b = find_min_index(stack_b);
	max_b = find_max_index(stack_b);
	if (is_biggest_or_smallest(stack_b, value) == 1)
	{
		comparison = get_min_cost(stack_b->pile[min_b], stack_b->pile[max_b]);
		if (comparison == 1)
			target = stack_b->pile[min_b];
		else
			target = stack_b->pile[max_b];
	}
	else if (is_biggest_or_smallest(stack_b, value) == -1)
		target = stack_b->pile[min_b];
	else
		target = 0;
	move_in_range_to_top(stack_b, target, target, 'b');
	pb(stack_a, stack_b);
}

/**
 * @brief Dumps all elements from stack_b back to stack_a.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */

/**
 * @brief    Dumps all elements from stack_b back to stack_a.
 * The maximum element of stack_b is moved to the top of stack_b, then
 * is dumped to stack_a.
 *
 * @param    stack_a
 * @param    stack_b
 */
void	dump_back(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	while (stack_b->top >= 0)
	{
		max = find_max_index(stack_b);
		move_in_range_to_top(stack_b, stack_b->pile[max], stack_b->pile[max],
			'b');
		pa(stack_a, stack_b);
	}
}

/**
 * @brief Sorts a chunk of elements within the specified range in stack_a.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param chunk_start The starting value of the chunk range.
 * @param chunk_end The ending value of the chunk range.
 */

/**
 * @brief    Sorts a chunk of elements within the specified range in stack_a.
 *
 * @param    stack_a
 * @param    stack_b
 * @param    chunk_start The minimum value of the chunk.
 * @param    chunk_end   The maximum value of the chunk.
 */
void	sort_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start,
		int chunk_end)
{
	while (scan_from_top(stack_a, chunk_start, chunk_end) != -1
		&& scan_from_bottom(stack_a, chunk_start, chunk_end) != -1)
	{
		move_in_range_to_top(stack_a, chunk_start, chunk_end, 'a');
		smart_push_b(stack_a, stack_b, stack_a->pile[stack_a->top]);
	}
}
