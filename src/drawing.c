/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:16:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 16:35:26 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int draw_initial_board(int size)
{
    int term_h, term_w;
    int raw_h, raw_w;
    int cell_h, cell_w;
    int used_h, used_w;
    int y_offset, x_offset;
    int y, x;

    getmaxyx(stdscr, term_h, term_w);
    raw_h = term_h * BOARD_RATIO / 100;
    raw_w = term_w * BOARD_RATIO / 100;
    cell_h = raw_h / size;
    cell_w = raw_w / size;
    used_h = cell_h * size;
    used_w = cell_w * size;

    y_offset = (term_h - used_h) / 2;
    x_offset = (term_w - used_w) / 2;
    for (int row = 0; row <= size; row++)
    {
        y = y_offset + row * cell_h;
        for (x = x_offset; x < x_offset + used_w; x++)
            mvaddch(y, x, '-');
    }
    for (int col = 0; col <= size; col++)
    {
        x = x_offset + col * cell_w;
        for (y = y_offset; y < y_offset + used_h; y++)
            mvaddch(y, x, '|');
    }

    return 0;
}

void print_nums_on_board(int used_height, int used_width, int cell_height, int cell_width, t_game *game)
{
    int y_offset, x_offset;
    int term_height, term_width;

	getmaxyx(stdscr, term_height, term_width);
	y_offset = (term_height - used_height) / 2;
    x_offset = (term_width - used_width) / 2;
    for (int row = 0; row < game->grid_size; row++)
    {
        for (int col = 0; col < game->grid_size; col++)
        {
            int num = game->grid[row][col];
            if (num == 0)
                continue;
            int y = y_offset + row * cell_height + (cell_height / 2);
            int x = x_offset + col * cell_width + ((cell_width - count_digits(num)) / 2);
            color_setup(game->colors, num);
            mvprintw(y, x, "%d", num);
            reset_color(game->colors);
        }
    }
}

int fill_board(t_game *game)
{
    int term_height, term_width;
    int raw_height, raw_width;
    int cell_height, cell_width;
    int used_height, used_width;

    getmaxyx(stdscr, term_height, term_width);
    raw_height  = term_height * BOARD_RATIO / 100;
    raw_width = term_width * BOARD_RATIO / 100;
    cell_height  = raw_height / game->grid_size;
    cell_width = raw_width / game->grid_size;
    used_height  = cell_height * game->grid_size;
    used_width = cell_width * game->grid_size;
	print_nums_on_board(used_height, used_width, cell_height, cell_width, game);
    return 0;
}

int	draw_board(t_game *game)
{
	clear();
	draw_initial_board(game->grid_size);
	fill_board(game);
	refresh();
	return (0);
}
