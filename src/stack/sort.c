/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:48:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 20:47:57 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void sort_three(t_stack *stack_a)
{

	if (stack_a->pile[0] < stack_a->pile[1] && stack_a->pile[1] < stack_a->pile[2])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->pile[0] < stack_a->pile[2] && stack_a->pile[2] > stack_a->pile[1])
		ra(stack_a);
	else if (stack_a->pile[0] > stack_a->pile[1] && stack_a->pile[1] < stack_a->pile[2])
		sa(stack_a);
	else if (stack_a->pile[0] > stack_a->pile[2] && stack_a->pile[2] < stack_a->pile[1])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (stack_a->pile[0] < stack_a->pile[2] && stack_a->pile[2] < stack_a->pile[1])
		rra(stack_a);
}

static void small_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
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
	while (chunk_start > stack_a->pile[find_max_index(stack_a)])
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
 * If length > 5, use small_sort.
 * If length > 100, use big_sort with 5 chunks.
 * If length > 500, use big_sort with 11 chunks.
 *
 * @param    stack_a   Stack to sort.
 * @param    stack_b   Stack to use as a buffer.
 */
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (already_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
	{
		small_sort(stack_a, stack_b);
		return ;
	}
	else if (stack_a->size <= 100)
	{
		big_sort(stack_a, stack_b, 5);
		return ;
	}
	else if (stack_a->size <= 500)
	{
		big_sort(stack_a, stack_b, 11);
		return ;
	}
}
