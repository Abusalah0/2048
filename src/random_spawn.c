/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:52:04 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 14:35:24 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	get_random_num(void)
{
	int	random;

	random = rand() % 10;
	if (random < 7)
		return (2);
	else
		return (4);
}

int	get_random_pos(t_game *game)
{
	int	empty_cells[16][2];
	int	count;
	int	index;

	count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (game->grid[i][j] == 0)
			{
				empty_cells[count][0] = i;
				empty_cells[count][1] = j;
				count++;
			}
		}
	}
	if (count == 0)
		return (-1);
	index = rand() % count;
	return (empty_cells[index][0] * 4 + empty_cells[index][1]);
}

int	spawn_random_tile(t_game *game)
{
	int	idx;

	idx = get_random_pos(game);
	if (idx < 0)
		return (1);
	game->grid[idx / 4][idx % 4] = get_random_num();
	return (0);
}
