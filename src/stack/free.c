/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:36 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/07 16:20:36 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Free the arguments.
 *
 * @param    arguments The arguments to free.
 */
void	free_arguments(char **arguments)
{
	int	i;

	if (!arguments)
		return ;
	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

/**
 * @brief    Free the stack.
 *
 * @param    stack     The stack to free.
 */
void	free_stack(t_stack *stack)
{
	if (stack)
		free(stack);
}
