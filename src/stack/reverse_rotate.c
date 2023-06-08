/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:50:20 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/08 15:03:11 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Shift down all elements of the stack by 1. The last element
 * becomes the first one.
 *
 * @param    stack     Stack to reverse rotate.
 */
void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	tmp = stack->pile[0];
	i = 0;
	while (i < stack->top)
	{
		stack->pile[i] = stack->pile[i + 1];
		i++;
	}
	stack->pile[stack->top] = tmp;
}

/**
 * @brief   Shift down all elements of stack_a by 1. The last element becomes
 * the first one.
 *
 * @param    stack_a
 */
void	rra(t_stack *stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print == 1)
		ft_printf("rra\n");
}

/**
 * @brief   Shift down all elements of stack_b by 1. The last element becomes
 * the first one.
 *
 * @param    stack_b
 */
void	rrb(t_stack *stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print == 1)
		ft_printf("rrb\n");
}

/**
 * @brief    Shift down all elements of stack_a and stack_b by 1. The last
 * elements become the first ones.
 *
 * @param    stack_a
 * @param    stack_b
 */
void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print == 1)
		ft_printf("rrr\n");
}
