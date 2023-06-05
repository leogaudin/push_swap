/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:48:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 10:57:43 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	current;
	int	previous;

	if (stack_a->top <= 0)
		return ;
	while (stack_a->top > 0)
	{
		current = stack_a->pile[stack_a->top];
		previous = stack_a->pile[stack_a->top - 1];
		if (current > previous)
		{
			sa(stack_a);
			if (stack_b->top >= 0
				&& stack_b->pile[stack_b->top] > stack_a->pile[stack_a->top])
				pa(stack_a, stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
	while (stack_b->top >= 0)
		pa(stack_a, stack_b);
}
