/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:54:11 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/08 15:02:16 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Swap the first 2 elements at the top of stack.
 *
 * @param    stack     Stack to swap.
 */
void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->pile[stack->top];
	stack->pile[stack->top] = stack->pile[stack->top - 1];
	stack->pile[stack->top - 1] = tmp;
}

/**
 * @brief    Swap the first 2 elements at the top of stack_a and stack_b.
 *
 * @param    stack_a
 * @param    stack_b
 */
void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print == 1)
		ft_printf("ss\n");
}

/**
 * @brief    Swap the first 2 elements at the top of stack_a.
 *
 * @param    stack_a
 */
void	sa(t_stack *stack_a, int print)
{
	swap(stack_a);
	if (print == 1)
		ft_printf("sa\n");
}

/**
 * @brief    Swap the first 2 elements at the top of stack_b.
 *
 * @param    stack_b
 */
void	sb(t_stack *stack_b, int print)
{
	swap(stack_b);
	if (print == 1)
		ft_printf("sb\n");
}
