/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:49:10 by abdsalah          #+#    #+#             */
/*   Updated: 2024/08/31 13:20:20 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*cur;

	i = 0;
	cur = s;
	while (i < n)
	{
		if (cur[i] == (unsigned char)c)
			return ((char *)&cur[i]);
		i++;
	}
	return (NULL);
}
