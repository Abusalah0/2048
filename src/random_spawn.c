/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:52:04 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/09 16:06:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file random_spawn.c
 * */

#include "main_2048.h"

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
	int	empty_cells[MAX_GRID_SIZE * MAX_GRID_SIZE][2];
	int	count;
	int	index;

	count = 0;
	for (int i = 0; i < game->grid_size; i++)
	{
		for (int j = 0; j < game->grid_size; j++)
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
	return (empty_cells[index][0] *  game->grid_size + empty_cells[index][1]);
}

int	spawn_random_tile(t_game *game)
{
	int	idx;

	idx = get_random_pos(game);
	if (idx < 0)
		return (1);
	game->grid[idx / game->grid_size][idx % game->grid_size] = get_random_num();
	return (0);
}
