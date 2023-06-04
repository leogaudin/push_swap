/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:56:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/04 15:16:54 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "stack.h"

t_stack	*initialise_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = -1;
	stack->pile = malloc(sizeof(int) * size);
	return (stack);
}

t_stack	*populate_stack(char **arguments)
{
	int	i;
	int	n;
	t_stack *stack;

	i = 0;
	while (arguments[i])
		i++;
	stack = initialise_stack(i);
	i = 0;
	while (arguments[i])
	{
		n = ft_atoi(arguments[i]);
		stack->top++;
		stack->pile[stack->top] = n;
		ft_printf("stack->pile[%d] = %d\n", stack->top, stack->pile[stack->top]);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->pile);
	free(stack);
}
