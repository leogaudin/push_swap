/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:48:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 15:02:48 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CHUNK_COUNT 5

#include "stack.h"

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

static int	get_min_cost(int a, int b)
{
	if (a <= b)
		return (1);
	else if (a == -1 && b != -1)
		return (-1);
	return (2);
}

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

static void	check_b_and_move(t_stack *stack_a, t_stack *stack_b, int value)
{
	if (value + 1 == value + 2 - 1)
		pb(stack_a, stack_b);
}

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
