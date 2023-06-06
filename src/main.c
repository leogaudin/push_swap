/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:58:46 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/06 19:15:39 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**arguments;

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
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}