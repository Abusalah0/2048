/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:20:06 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/09 16:02:56 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_2048.h"

static void	compress(int line[5], int size)
{
	int	temp[size];
	int	idx;

	idx = 0;
	ft_bzero(temp, sizeof(temp));
	for (int i = 0; i < size; i++)
	{
		if (line[i] != 0)
			temp[idx++] = line[i];
	}
	for (int i = 0; i < size; i++)
		line[i] = temp[i];
}

static void	merge(int line[5], t_game *game)
{
	for (int i = 0; i < game->grid_size - 1; i++)
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
	int col[game->grid_size];

	for (int c = 0; c < game->grid_size; c++)
	{
		for (int r = 0; r < game->grid_size; r++)
			col[r] = game->grid[r][c];
		compress(col, game->grid_size);
		merge(col, game);
		compress(col, game->grid_size);
		for (int r = 0; r < game->grid_size; r++)
			game->grid[r][c] = col[r];
	}
}

void	down_key_event(t_game *game)
{
	int col[game->grid_size];

	for (int c = 0; c < game->grid_size; c++)
	{
		for (int r = 0; r < game->grid_size; r++)
			col[game->grid_size - 1 - r] = game->grid[r][c];
		compress(col, game->grid_size);
		merge(col, game);
		compress(col, game->grid_size);
		for (int r = 0; r < game->grid_size; r++)
			game->grid[r][c] = col[game->grid_size - 1 - r];
	}
}

void	left_key_event(t_game *game)
{
	int row[game->grid_size];

	for (int r = 0; r < game->grid_size; r++)
	{
		for (int c = 0; c < game->grid_size; c++)
			row[c] = game->grid[r][c];
		compress(row, game->grid_size);
		merge(row, game);
		compress(row, game->grid_size);
		for (int c = 0; c < game->grid_size; c++)
			game->grid[r][c] = row[c];
	}
}

void	right_key_event(t_game *game)
{
	int row[game->grid_size];

	for (int r = 0; r < game->grid_size; r++)
	{
		for (int c = 0; c < game->grid_size; c++)
			row[game->grid_size - 1 - c] = game->grid[r][c];
		compress(row, game->grid_size);
		merge(row, game);
		compress(row, game->grid_size);
		for (int c = 0; c < game->grid_size; c++)
			game->grid[r][c] = row[game->grid_size - 1 - c];
	}
}
