/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:21:41 by abdsalah          #+#    #+#             */
/*   Updated: 2024/08/31 12:57:16 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	str_len;
	size_t	little_len;
	size_t	j;
	size_t	i;

	str_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (little_len > str_len)
		return (NULL);
	i = 0;
	while (i <= len - little_len && i < len)
	{
		j = 0;
		while (j < little_len && big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
