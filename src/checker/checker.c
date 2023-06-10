/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:58:28 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/10 15:08:32 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief    Parse the instruction and call the corresponding function.
 *
 * @param    instruction The string to parse.
 * @param    stack_a
 * @param    stack_b
 */
void	parse_instruction(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(instruction, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else
		free(instruction);
}

/**
 * @brief    Get the instructions from stdin and parse them.
 *
 * @param    stack_a
 * @param    stack_b
 */
void	get_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		parse_instruction(instruction, stack_a, stack_b);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
}

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
	if (get_array_length(arguments) == 1 || already_sorted(a) == 1)
		exit_without_error(a, NULL, arguments, argc);
	if (!a)
		print_error(a, arguments, argc);
	b = initialise_stack();
	get_instructions(a, b);
	if (already_sorted(a) == 1 && b->top < 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_without_error(a, b, arguments, argc);
	return (0);
}
