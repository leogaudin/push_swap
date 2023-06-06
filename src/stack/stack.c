/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:56:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 14:59:53 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "stack.h"
#include <stdio.h>

t_stack	*initialise_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = -1;
	stack->size = 0;
	return (stack);
}

t_stack	*populate_stack(char **arguments, int argc)
{
	int		i;
	long	n;
	t_stack	*stack;

	stack = initialise_stack();
	i = get_size(arguments) - 1;
	stack->size = i + 1;
	while (i >= 0)
	{
		if (valid_atoi(arguments[i]))
		{
			n = ft_atoi(arguments[i]);
			if (already_exists(n, stack) == 1 || n > 2147483647
				|| n < -2147483648)
				print_error(stack);
		}
		else
			print_error(stack);
		stack->top++;
		stack->pile[stack->top] = n;
		i--;
	}
	if (argc == 2)
		free_arguments(arguments);
	return (stack);
}
