/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:58:26 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/08 17:04:21 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Print an error message, free the stack and exit the program.
 *
 * @param    stack     The stack to free.
 */
void	print_error(t_stack *stack, char **arguments, int argc)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	if (argc == 2)
		free_arguments(arguments);
	exit(EXIT_FAILURE);
}

/**
 * @brief    Print the stack.
 *
 * @param    stack     The stack to print.
 */
void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("i = %d and stack->pile[i] = %d\n", i, stack->pile[i]);
		i--;
	}
	ft_printf("\n");
}
