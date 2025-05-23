/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:16:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/09 16:16:22 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_2048.h"

/**
 * * @brief Draws the grid cells on the board.
 * * @param size The size of the grid.
 * * @return 0 on success.
 */
static int draw_board_cells(int size)
{
    int term_height, term_width;
    int raw_height, raw_width;
    int cell_height, cell_width;
    int used_height, used_width;
    int y_offset, x_offset;
    int y, x;

    getmaxyx(stdscr, term_height, term_width);
    raw_height = term_height * BOARD_RATIO / 100;
    raw_width = term_width * BOARD_RATIO / 100;
    cell_height = raw_height / size;
    cell_width = raw_width / size;
    used_height = cell_height * size;
    used_width = cell_width * size;

    y_offset = (term_height - used_height) / 2;
    x_offset = (term_width - used_width) / 2;
    for (int row = 0; row <= size; row++)
    {
        y = y_offset + row * cell_height;
        for (x = x_offset; x < x_offset + used_width; x++)
            mvaddch(y, x, ACS_HLINE);
    }
    for (int col = 0; col <= size; col++)
    {
        x = x_offset + col * cell_width;
        for (y = y_offset; y < y_offset + used_height; y++)
            mvaddch(y, x, ACS_VLINE);
    }
    return (0);
}

/**
 * * @brief Prints the numbers on the board.
 * * @param used_height The height of the used area.
 * * @param used_width The width of the used area.
 * * @param cell_height The height of each cell.
 * * @param cell_width The width of each cell.
 * * @param game The game structure containing the grid and colors.
 * * @return void
 */
static void print_nums_on_board(int used_height, int used_width, int cell_height, int cell_width, t_game *game)
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
            int x = x_offset + col * cell_width + ((cell_width - ft_count_digits(num)) / 2);
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
    return (0);
}

int	draw_board(t_game *game)
{
	clear();
	draw_board_cells(game->grid_size);
	fill_board(game);
	refresh();
	return (0);
}
