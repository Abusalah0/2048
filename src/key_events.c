/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:20:06 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 16:13:04 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

//AI disclamer: I used AI here to make the code this compact and more readable.
// the original code was repititive and long.

static void	compress(int line[GRID_SIZE])
{
	int	temp[GRID_SIZE] = {0};
	int	idx;

	idx = 0;
	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (line[i] != 0)
			temp[idx++] = line[i];
	}
	for (int i = 0; i < GRID_SIZE; i++)
		line[i] = temp[i];
}

static void	merge(int line[GRID_SIZE], t_game *game)
{
	for (int i = 0; i < GRID_SIZE - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			game->score += line[i];
			if (line[i] == game->target)
				game->won = 1;
			line[i + 1] = 0;
		}
	}
}

void	up_key_event(t_game *game)
{
	int col[GRID_SIZE];

	for (int c = 0; c < GRID_SIZE; c++)
	{
		for (int r = 0; r < GRID_SIZE; r++)
			col[r] = game->grid[r][c];
		compress(col);
		merge(col, game);
		compress(col);
		for (int r = 0; r < GRID_SIZE; r++)
			game->grid[r][c] = col[r];
	}
}

void	down_key_event(t_game *game)
{
	int col[GRID_SIZE];

	for (int c = 0; c < GRID_SIZE; c++)
	{
		for (int r = 0; r < GRID_SIZE; r++)
			col[GRID_SIZE - 1 - r] = game->grid[r][c];
		compress(col);
		merge(col, game);
		compress(col);
		for (int r = 0; r < GRID_SIZE; r++)
			game->grid[r][c] = col[GRID_SIZE - 1 - r];
	}
}

void	left_key_event(t_game *game)
{
	int row[GRID_SIZE];

	for (int r = 0; r < GRID_SIZE; r++)
	{
		for (int c = 0; c < GRID_SIZE; c++)
			row[c] = game->grid[r][c];
		compress(row);
		merge(row, game);
		compress(row);
		for (int c = 0; c < GRID_SIZE; c++)
			game->grid[r][c] = row[c];
	}
}

void	right_key_event(t_game *game)
{
	int row[GRID_SIZE];

	for (int r = 0; r < GRID_SIZE; r++)
	{
		for (int c = 0; c < GRID_SIZE; c++)
			row[GRID_SIZE - 1 - c] = game->grid[r][c];
		compress(row);
		merge(row, game);
		compress(row);
		for (int c = 0; c < GRID_SIZE; c++)
			game->grid[r][c] = row[GRID_SIZE - 1 - c];
	}
}
