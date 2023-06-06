/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:54:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:30:52 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Shift up all elements of a stack by 1. The first element becomes
 * the last one.
 *
 * @param    stack     Stack to rotate.
 */
void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	tmp = stack->pile[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->pile[i] = stack->pile[i - 1];
		i--;
	}
	stack->pile[0] = tmp;
}

/**
 * @brief    Shift up all elements of stack_a by 1. The first element becomes
 * the last one.
 * @param    stack_a   Stack to rotate.
 */
void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

/**
 * @brief    Shift up all elements of stack_b by 1. The first element becomes
 * the last one.
 * @param    stack_b   Stack to rotate.
 */
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

/**
 * @brief   Shift up all elements of stack_a and stack_b by 1. The first
 * elements become the last ones.
 * @param    stack_a
 * @param    stack_b
 */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
