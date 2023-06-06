/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:53:40 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:41:19 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Get the array length.
 *
 * @param    arguments The array to get the length of.
 * @return             The length of the array.
 */
int	get_array_length(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
		i++;
	return (i);
}

/**
 * @brief    Find the minimum value.
 *
 * @param    a
 * @param    b
 * @return             1 if `a` is less than or equal to `b`, -1 if `a` and
 * `b` are equal to -1, and 2 otherwise.
 */
int	get_min_cost(int a, int b)
{
	if (a <= b)
		return (1);
	else if (a == -1 && b == -1)
		return (-1);
	return (2);
}
