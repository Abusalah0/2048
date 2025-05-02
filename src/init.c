/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:52:43 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 01:15:33 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void init_colors(t_game *game)
{
	if (has_colors() == FALSE)
	{
		game->colors = 0;
		return ;
	}
	if (start_color() == ERR)
	{
		game->colors = 0;
		return ;
	}
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	game->colors = 1;
}

static void target_setup(t_game *game)
{
	if (ft_is_power_of_2(WIN_VALUE))
	{
		game->target = WIN_VALUE;
	}
	else
	{
		game->target = DEFAULT_TARGET;
	}
}

static void init_game(t_game *game)
{
	int temp = game->grid_size;
	ft_bzero(game, sizeof(t_game));
	game->grid_size = temp;
	target_setup(game);
	signal(SIGWINCH, resize_handler);
	srand(time(NULL));
}

static void init_window(t_game *game)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	init_colors(game);
	curs_set(0);
}

void	init(t_game *game)
{
	init_game(game);
	init_window(game);
}
