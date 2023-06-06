/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:48:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 13:04:51 by lgaudin          ###   ########.fr       */
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
	if (a == -1 && b != -1)
		return (-1);
	return (2);
}

static void	move_in_range_to_top(t_stack *stack, int min, int max)
{
	int	closest;
	int	count;
	int i;

	closest = get_min_cost(
		stack->size - scan_from_top(stack, min, max),
		scan_from_bottom(stack, min, max)
	);
	i = 0;
	if (closest == 1)
	{
		count = scan_from_top(stack, min, max);
		while (i++ < count)
			ra(stack);
	}
	else if (closest == 2)
	{
		count = scan_from_bottom(stack, min, max);
		while (i++ < count)
			rra(stack);
	}
}

static void	check_b_and_move(t_stack *stack_a, t_stack *stack_b, int value)
{
	move_in_range_to_top(stack_b, -2147483647,
			stack_b->pile[value]);
	pb(stack_a, stack_b);
}

static void	sort_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start,
		int chunk_end)
{
	// ft_printf("Sorting chunk with values %d - %d\n", chunk_start, chunk_end);
	while (scan_from_top(stack_a, chunk_start, chunk_end) != -1
		&& scan_from_bottom(stack_a, chunk_start, chunk_end) != -1)
	{
		move_in_range_to_top(stack_a, chunk_start, chunk_end);
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
	// while (stack_b->top >= 0)
	// {
	// 	move_in_range_to_top(stack_b, stack_b->pile[find_max_index(stack_b)],
	// 			stack_b->pile[find_max_index(stack_b)]);
	// 	pa(stack_a, stack_b);
	// }
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

// void	sort_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	current;
// 	int	previous;

// 	if (stack_a->top <= 0)
// 		return ;
// 	while (stack_a->top > 0)
// 	{
// 		current = stack_a->pile[stack_a->top];
// 		previous = stack_a->pile[stack_a->top - 1];
// 		if (current > previous)
// 		{
// 			sa(stack_a);
// 			if (stack_b->top >= 0
// 				&& stack_b->pile[stack_b->top] > stack_a->pile[stack_a->top])
// 				pa(stack_a, stack_b);
// 		}
// 		else
// 			pb(stack_a, stack_b);
// 	}
// 	while (stack_b->top >= 0)
// 		pa(stack_a, stack_b);
// }
