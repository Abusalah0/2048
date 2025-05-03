/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:52:43 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 22:26:48 by abdsalah         ###   ########.fr       */
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
	if (init_pair(1, COLOR_WHITE, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
	if (init_pair(2, COLOR_YELLOW, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
	if (init_pair(4, COLOR_GREEN, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
	if (init_pair(3, COLOR_RED, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
	if (init_pair(5, COLOR_BLUE, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
	if (init_pair(6, COLOR_MAGENTA, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
	if (init_pair(7, COLOR_CYAN, COLOR_BLACK) == ERR)
	{
		game->colors = 0;
		return ;
	}
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
	srand(time(NULL));
}

static int init_window(t_game *game)
{
	if (initscr() == NULL)
	{
		return (1);
	}
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	init_colors(game);
	curs_set(0);
	return (0);
}

int	init(t_game *game)
{
	init_game(game);
	if (init_window(game))
	{
		return (1);
	}
	return (0);
}
