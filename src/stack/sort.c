/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:48:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 15:07:09 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CHUNK_COUNT 5

#include "stack.h"

/**
 * @brief Scans the stack from the top to find the index of the first element
 *        within the specified range.
 * @param stack The stack to scan.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return The index of the first element within the range, or -1 if not found.
 */
static int	scan_from_top(t_stack *stack, int min, int max)
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
 * @brief Scans the stack from the bottom to find the index of the first element
 *        within the specified range.
 * @param stack The stack to scan.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return The index of the first element within the range, or -1 if not found.
 */
static int	scan_from_bottom(t_stack *stack, int min, int max)
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

/**
 * @brief Calculates the minimum cost between two values.
 * @param a The first value.
 * @param b The second value.
 * @return 1 if `a` is less than or equal to `b`, -1 if `a` is -1 and `b` is not,
 *         and 2 otherwise.
 */
static int	get_min_cost(int a, int b)
{
	if (a <= b)
		return (1);
	else if (a == -1 && b != -1)
		return (-1);
	return (2);
}

/**
 * @brief Moves the elements within the specified range to the top of the stack.
 * @param stack The stack to modify.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @param stack_name The name of the stack ('a' or 'b').
 */
static void	move_in_range_to_top(t_stack *stack, int min, int max, char stack_name)
{
	int	closest;
	int top_scan;
	int bottom_scan;

	top_scan = stack->top - scan_from_top(stack, min, max);
	bottom_scan = scan_from_bottom(stack, min, max) + 1;
	closest = get_min_cost(top_scan, bottom_scan);
	if (closest == 1)
	{
		while (scan_from_bottom(stack, min, max) + 1 > 0 && stack->top - scan_from_top(stack, min, max) > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else if (closest == 2)
	{
		while (scan_from_bottom(stack, min, max) + 1 > 0 && stack->top - scan_from_top(stack, min, max) > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

/**
 * @brief Checks the value of the element below the top element of stack_b
 *        and moves it to stack_a if it satisfies a specific condition.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param value The value of the top element of stack_a.
 */
static void	check_b_and_move(t_stack *stack_a, t_stack *stack_b, int value)
{
	if (value + 1 == value + 2 - 1)
		pb(stack_a, stack_b);
}

/**
 * @brief Dumps all elements from stack_b back to stack_a.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */
static void dump_back(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	while (stack_b->top >= 0)
	{
		max = find_max_index(stack_b);
		move_in_range_to_top(stack_b, stack_b->pile[max],
				stack_b->pile[max], 'b');
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
static void	sort_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start,
		int chunk_end)
{
	while (scan_from_top(stack_a, chunk_start, chunk_end) != -1
		&& scan_from_bottom(stack_a, chunk_start, chunk_end) != -1)
	{
		move_in_range_to_top(stack_a, chunk_start, chunk_end, 'a');
		check_b_and_move(stack_a, stack_b, stack_a->pile[stack_a->top]);
	}
}

/**
 * @brief Performs a big sort on stack_a and stack_b.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */
static void big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (already_sorted(stack_a))
		return ;
	chunk_size = stack_a->pile[find_max_index(stack_a)] / CHUNK_COUNT;
	chunk_start = stack_a->pile[find_min_index(stack_a)];
	while (chunk_start < stack_a->pile[find_max_index(stack_a)])
	{
		chunk_end = chunk_start + chunk_size;
		sort_chunk(stack_a, stack_b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	dump_back(stack_a, stack_b);
}

/**
 * @brief Sorts the stack using the specified algorithm.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (already_sorted(stack_a))
		return ;
	if (stack_a->size <= 5)
	{
		// small_sort(stack_a);
		return ;
	}
	big_sort(stack_a, stack_b);
}
