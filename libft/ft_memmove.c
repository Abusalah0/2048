/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:02:01 by abdsalah          #+#    #+#             */
/*   Updated: 2024/08/31 13:20:38 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	char unsigned		*d;

	s = src;
	d = dest;
	i = 0;
	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest <= src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (dest > src)
		while (n--)
			d[n] = s[n];
	return (dest);
}
