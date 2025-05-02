/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:20:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 16:08:35 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int color_pair(int num)
{
	int pair = 0;
	
	for (; num > 0; num /= 2)
	{
		pair++;	
	}
	for (int i = 1; i <= 7; i++)
	{
		if (pair == i)
				return (COLOR_PAIR(i));
	}
	if (pair > 7)
	{
		return (COLOR_PAIR(pair % 7));
	}
	return (-1);
}

void	color_setup(int is_colored, int num)
{
	
	if (is_colored == 0)
	{
		return ;
	}
	int pair = color_pair(num);
	attron(pair);
}

void	reset_color(int is_colored)
{
	if (is_colored == 0)
	{
		return ;
	}
	attroff(COLOR_PAIRS);
}
