/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:30 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/12 20:26:51 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}
