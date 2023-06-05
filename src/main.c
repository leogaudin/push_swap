/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:58:46 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 11:55:55 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char **arguments;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
		arguments = argv + 1;
	a = populate_stack(arguments, argc);
	if (!a)
		print_error(a);
	b = initialise_stack();
	// print_stack(a);
	if (already_sorted(a) == 0)
		sort_stack(a, b);
	// print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
