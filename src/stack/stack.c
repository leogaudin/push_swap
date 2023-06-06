/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:56:13 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:22:50 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "stack.h"
#include <stdio.h>

/**
 * @brief    Allocates the memory to a stack and returns a pointer to it.
 *
 * @return   t_stack*  pointer to the allocated stack
 */
t_stack	*initialise_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = -1;
	stack->size = 0;
	return (stack);
}

/**
 * @brief    Populates an already-allocated stack with the given arguments.
 *
 * @param    arguments array of strings representing the arguments
 * @param    argc      number of arguments, if =2 then free arguments
 * @return   t_stack*  pointer to the populated stack
 */
t_stack	*populate_stack(char **arguments, int argc)
{
	int		i;
	long	n;
	t_stack	*stack;

	stack = initialise_stack();
	i = get_array_length(arguments) - 1;
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
