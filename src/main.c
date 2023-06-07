/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:58:46 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/07 16:11:35 by lgaudin          ###   ########.fr       */
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
	a = populate_stack(arguments);
	if (get_array_length(arguments) == 1 || already_sorted(a) == 1)
		exit_without_error(a, NULL, arguments);
	if (!a)
		print_error(a, arguments);
	b = initialise_stack();
	sort_stack(a, b, arguments);
	exit_without_error(a, b, arguments);
	return (0);
}
