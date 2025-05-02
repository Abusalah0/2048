/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:02:25 by abdsalah          #+#    #+#             */
/*   Updated: 2024/08/31 13:25:13 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				numlen;
	char			*str;
	int				is_negative;
	unsigned int	num;

	is_negative = 0;
	num = n;
	if (n < 0)
	{
		is_negative = 1;
		num = -n;
	}
	numlen = len(n);
	str = malloc(numlen + 1);
	if (!str)
		return (NULL);
	str[numlen] = '\0';
	if (is_negative)
		str[0] = '-';
	while (numlen > is_negative)
	{
		str[--numlen] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
