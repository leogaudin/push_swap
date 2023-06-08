/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:32:24 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/08 17:04:30 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../../include/push_swap.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	top;
	int	size;
	int	pile[1024];
}		t_stack;

t_stack	*initialise_stack(void);
t_stack	*populate_stack(char **arguments, int argc);
void	free_stack(t_stack *stack);
void	free_arguments(char **arguments);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	sort_stack(t_stack *stack_a, t_stack *stack_b, char **arguments);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
int		valid_atoi(const char *str);
void	print_error(t_stack *stack, char **arguments, int argc);
int		ft_isspace(char c);
int		already_exists(int n, t_stack *stack);
int		already_sorted(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
int		get_array_length(char **arguments);
void	print_stack(t_stack *stack);
int		scan_from_bottom(t_stack *stack, int min, int max);
int		scan_from_top(t_stack *stack, int min, int max);
int		get_min_cost(int a, int b);
void	sort_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start,
			int chunk_end);
void	dump_back(t_stack *stack_a, t_stack *stack_b);
void	smart_push_b(t_stack *stack_a, t_stack *stack_b, int value);
int		is_biggest_or_smallest(t_stack *stack, int value);
void	move_in_range_to_top(t_stack *stack, int min, int max, char stack_name);
int		get_directly_below_index(t_stack *stack, int value);
int		get_directly_above_index(t_stack *stack, int value);
void	exit_without_error(t_stack *stack_a, t_stack *stack_b,
			char **arguments);

#endif
