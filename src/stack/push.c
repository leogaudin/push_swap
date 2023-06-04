/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:54:15 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/04 14:56:26 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *src, t_stack *dest)
{
	if (src->top < 0)
		return;

	dest->top++;
	dest->pile[dest->top] = src->pile[src->top];
	src->top--;
}
