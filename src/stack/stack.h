/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:32:24 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/05 11:55:37 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../../include/push_swap.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	top;
	int	pile[1024];
}		t_stack;

t_stack	*initialise_stack(void);
t_stack	*populate_stack(char **arguments, int argc);
void	free_stack(t_stack *stack);
void	free_arguments(char **arguments);
int		get_stack_size(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
int		valid_atoi(const char *str);
void	print_error(t_stack *stack);
int		ft_isspace(char c);
int		already_exists(int n, t_stack *stack);
int		already_sorted(t_stack *stack);

#endif
