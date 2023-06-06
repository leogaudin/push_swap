/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:36 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 14:59:56 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_arguments(char **arguments)
{
	int	i;

	i = 1;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	free_stack(t_stack *stack)
{
	free(stack);
}
