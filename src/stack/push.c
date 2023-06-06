/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:54:15 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:34:21 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Push the first element of stack src at the top of stack
 * dest.
 *
 * @param    src       Stack to pop from.
 * @param    dest      Stack to push to.
 */
void	push(t_stack *src, t_stack *dest)
{
	if (src->top < 0)
		return ;
	dest->top++;
	dest->pile[dest->top] = src->pile[src->top];
	src->top--;
}

/**
 * @brief    Push the first element of stack_b at the top of stack_a.
 *
 * @param    stack_a
 * @param    stack_b
 */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

/**
 * @brief    Push the first element of stack_a at the top of stack_b.
 *
 * @param    stack_a
 * @param    stack_b
 */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
