/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:45:55 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/10 15:04:48 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief    Check if the char is a space.
 *
 * @param    c         The char to check.
 * @return             1 if the char is a space, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

/**
 * @brief    Check if the string is a valid integer that can be passed
 * to atoi.
 *
 * @param    str       The string to check.
 * @return             1 if the string is a valid integer, 0 otherwise.
 */
int	valid_atoi(const char *str)
{
	int	i;
	int	digits;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	digits = 0;
	while ((str[i] >= '0' && str[i] <= '9') || ft_isspace(str[i]))
	{
		i++;
		digits++;
	}
	if (str[i] || digits == 0 || digits > 10)
		return (0);
	return (1);
}

/**
 * @brief    Check if a number already exists in the stack.
 *
 * @param    n         The number to look for.
 * @param    stack     The stack to look in.
 * @return             1 if the number already exists, 0 otherwise.
 */
int	already_exists(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
		if (stack->pile[i--] == n)
			return (1);
	i--;
	return (0);
}

/**
 * @brief    Check if the stack is already sorted.
 *
 * @param    stack     The stack to check.
 * @return             1 if the stack is already sorted, 0 otherwise.
 */
int	already_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	if (i <= 1)
		return (1);
	while (i >= 0)
	{
		if (i == 0)
			break ;
		if (stack->pile[i] > stack->pile[i - 1])
			return (0);
		i--;
	}
	return (1);
}

/**
 * @brief    Free everything and exit the program without error.
 *
 * @param    stack_a
 * @param    stack_b
 * @param    arguments
 */
void	exit_without_error(t_stack *stack_a, t_stack *stack_b, char **arguments,
		int argc)
{
	if (argc == 2)
		free_arguments(arguments);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(0);
}
