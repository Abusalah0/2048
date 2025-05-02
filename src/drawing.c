/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:16:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 15:42:31 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	draw_initial_board(void)
{
	int	term_height;
	int	term_width;
	int	cell_height;
	int	cell_width;
	int	y;
	int	x;

	getmaxyx(stdscr, term_height, term_width);
	cell_height = term_height / GRID_SIZE;
	cell_width = term_width / GRID_SIZE;
	
	for (int row = 0; row <= GRID_SIZE; row++)
	{
		y = row * cell_height;
		for (int x = 0; x < term_width; x++)
			mvaddch(y, x, '-');
	}
	for (int col = 0; col <= GRID_SIZE; col++)
	{
		x = col * cell_width;
		for (int y = 0; y < term_height; y++)
			mvaddch(y, x, '|');
	}
	return (0);
}

int	fill_board(t_game *game)
{
	int	term_height;
	int	term_width;
	int	cell_height;
	int	cell_width;

	getmaxyx(stdscr, term_height, term_width);
	cell_height = term_height / GRID_SIZE;
	cell_width = term_width / GRID_SIZE;
	for (int row = 0; row < GRID_SIZE; row++)
	{
		for (int col = 0; col < GRID_SIZE; col++)
		{
			if (game->grid[row][col] != 0)
			{
				color_setup(game->colors ,game->grid[row][col]);
				mvprintw(row * cell_height + cell_height / 2, col * cell_width
					+ cell_width / 2, "%d", game->grid[row][col]);
				reset_color(game->colors);
			}
		}
	}
	return (0);
}

int	draw_board(t_game *game)
{
	clear();
	draw_initial_board();
	fill_board(game);
	refresh();
	return (0);
}
