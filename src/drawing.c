/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:16:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 01:02:46 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	draw_initial_board(int size)
{
	int	term_height;
	int	term_width;
	int	cell_height;
	int	cell_width;
	int	y;
	int	x;

	getmaxyx(stdscr, term_height, term_width);
	cell_height = term_height / size;
	cell_width = term_width / size;
	
	for (int row = 0; row <= size; row++)
	{
		y = row * cell_height;
		for (int x = 0; x < term_width; x++)
			mvaddch(y, x, '-');
	}
	for (int col = 0; col <= size; col++)
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
	cell_height = term_height / game->grid_size;
	cell_width = term_width / game->grid_size;
	for (int row = 0; row < game->grid_size; row++)
	{
		for (int col = 0; col < game->grid_size; col++)
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
	draw_initial_board(game->grid_size);
	fill_board(game);
	refresh();
	return (0);
}
