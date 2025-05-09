/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:44:03 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/09 15:45:44 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_count_digits(int n)
{
    int count;

    count = 0;
    if (n < 0)
        n = -n;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return (count);
}