/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:30:01 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/15 19:20:10 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	count_strings(char const *str, char c)
{
	int	strings_count;
	int	is_char;

	strings_count = 0;
	is_char = 0;
	if (*str == '\0')
		return (0);
	while (*(++str))
	{
		if (*str != c && is_char == 0)
		{
			is_char = 1;
			strings_count++;
		}
		else if (*str == c)
			is_char = 0;
	}
	return (strings_count);
}

static char	*cut_string(char const *s, int start, int end, char c)
{
	int		i;
	char	*string;

	i = 0;
	string = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		if (s[start] != c)
			string[i++] = s[start];
		start++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		result_index;
	int		i;
	int		current_start;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!result)
		return (0);
	i = -1;
	result_index = 0;
	current_start = -1;
	while (s[++i])
	{
		if (s[i] != c && current_start == -1)
			current_start = i;
		if ((s[i] == c || s[i + 1] == 0) && current_start != -1)
		{
			result[result_index++] = cut_string(s, current_start, i + 1, c);
			current_start = -1;
		}
	}
	result[result_index] = 0;
	return (result);
}

// int main(void)
// {
// 	char *str = "";
// 	char sep = 'a';
// 	printf("There are %d strings in \"%s\"\n", count_strings(str, sep), str);
// 	char **result = ft_split(str, sep);
// 	int i = 0;
// 	while (i <= count_strings(str, sep))
// 	{
// 		printf("String %d: %s\n", i, result[i]);
// 		i++;
// 	}
// 	return (0);
// }
