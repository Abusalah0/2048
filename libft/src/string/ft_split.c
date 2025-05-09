/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:36:41 by abdsalah          #+#    #+#             */
/*   Updated: 2024/10/21 02:09:42 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static char	**ft_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

static size_t	get_sep(const char *s, char c)
{
	size_t	count;
	int		in_substr;

	count = 0;
	in_substr = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_substr = 0;
		}
		else if (!in_substr)
		{
			in_substr = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	add_substring(char **result, const char *start, const char *s,
		size_t *index)
{
	if (s > start)
	{
		result[*index] = ft_substr(start, 0, s - start);
		if (!result[*index])
			return (1);
		(*index)++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t		num_substrs;
	char		**result;
	size_t		index;
	const char	*start = s;

	if (!s)
		return (NULL);
	num_substrs = get_sep(s, c);
	result = malloc((num_substrs + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (add_substring(result, start, s, &index))
				return (ft_free(result, index));
			start = s + 1;
		}
		s++;
	}
	if (add_substring(result, start, s, &index))
		return (ft_free(result, index));
	return (result[index] = NULL, result);
}
