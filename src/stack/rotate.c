/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:54:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/04 14:58:42 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return;

	tmp = stack->pile[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->pile[i] = stack->pile[i - 1];
		i--;
	}
	stack->pile[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return;

	tmp = stack->pile[0];
	i = 0;
	while (i < stack->top)
	{
		stack->pile[i] = stack->pile[i + 1];
		i++;
	}
	stack->pile[stack->top] = tmp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
