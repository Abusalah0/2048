/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:44:22 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 16:46:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	board_changed(int old[GRID_SIZE][GRID_SIZE], int new[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
		for (int j = 0; j < GRID_SIZE; j++)
			if (old[i][j] != new[i][j])
				return (1);
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	int	old_board[GRID_SIZE][GRID_SIZE];

	ft_memcpy(old_board, game->grid, sizeof(game->grid));
	if (key == KEY_UP)
		up_key_event(game);
	else if (key == KEY_DOWN)
		down_key_event(game);
	else if (key == KEY_LEFT)
		left_key_event(game);
	else if (key == KEY_RIGHT)
		right_key_event(game);
	if (key == KEY_RESIZE)
	{
		clear();
		draw_board(game);
	}
	if (board_changed(old_board, game->grid))
	{
		spawn_random_tile(game);
		draw_board(game);
		napms(10);
		flushinp();
	}
	return (0);
}
