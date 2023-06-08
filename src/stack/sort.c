/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:48:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/08 15:04:22 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Sorts a stack of 3 elements using a naive algorithm.
 *
 * @param    stack_a
 */
static void	sort_three(t_stack *stack_a)
{
	int	*pile;

	pile = stack_a->pile;
	if (pile[2] > pile[1] && pile[1] > pile[0] && pile[0] < pile[2])
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (pile[2] > pile[1] && pile[1] < pile[0] && pile[0] < pile[2])
		ra(stack_a, 1);
	else if (pile[0] > pile[1] && pile[1] < pile[2] && pile[0] > pile[2])
		sa(stack_a, 1);
	else if (pile[0] > pile[2] && pile[2] < pile[1] && pile[0] < pile[1])
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (pile[0] < pile[2] && pile[2] < pile[1] && pile[2] > pile[0])
		rra(stack_a, 1);
}

/**
 * @brief    Sorts a stack of 6 or less elements.
 *
 * @param    stack_a
 * @param    stack_b
 */
static void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	if (stack_a->size == 2)
		sa(stack_a, 1);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
	{
		while (stack_a->top > 2)
			pb(stack_a, stack_b, 1);
		sort_three(stack_a);
		while (stack_b->top >= 0)
		{
			if (is_biggest_or_smallest(stack_a,
					stack_b->pile[stack_b->top]) != 0)
				target = stack_a->pile[find_min_index(stack_a)];
			else
				target = stack_a->pile[get_directly_above_index(stack_a,
						stack_b->pile[stack_b->top])];
			move_in_range_to_top(stack_a, target, target, 'a');
			pa(stack_a, stack_b, 1);
		}
		while (find_min_index(stack_a) != stack_a->top)
			ra(stack_a, 1);
	}
}

/**
 * @brief    Sorts stack_a by chunks.
 *
 * @param    stack_a     Stack to sort.
 * @param    stack_b     Stack to use as a buffer.
 * @param    chunk_count Number of chunks to use to sort.
 */
static void	big_sort(t_stack *stack_a, t_stack *stack_b, int chunk_count)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	chunk_size = stack_a->pile[find_max_index(stack_a)] / chunk_count;
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
 * @brief    Determines which sorting algorithm to use based on the size of
 * the stack.
 * If length <= 6, use small_sort.
 * Else if length <= 100, use big_sort with 5 chunks.
 * Else if length > 500, use big_sort with 11 chunks.
 *
 * @param    stack_a   Stack to sort.
 * @param    stack_b   Stack to use as a buffer.
 */
void	sort_stack(t_stack *stack_a, t_stack *stack_b, char **arguments)
{
	if (already_sorted(stack_a))
		exit_without_error(stack_a, stack_b, arguments);
	else if (stack_a->size <= 6)
		small_sort(stack_a, stack_b);
	else if (stack_a->size <= 100)
		big_sort(stack_a, stack_b, 5);
	else
		big_sort(stack_a, stack_b, 11);
}
