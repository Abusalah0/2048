/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:38:09 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 01:27:47 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	game_over_handler(void)
{
	int	height;
	int	width;
	
	clear();
	getmaxyx(stdscr, height, width);
	mvprintw(height / 2, (width - 9) / 2, "Game Over");
	mvprintw(height / 2 + 1, (width - 20) / 2, "Press any key to quit");
	refresh();
	getch();
}

static int	check_game_over(t_game *game)
{
	int	i;
	int	j;

	for (i = 0; i < game->grid_size; i++)
	{
		for (j = 0; j < game->grid_size; j++)
		{
			if (game->grid[i][j] == 0)
				return (0);
			if (i < game->grid_size - 1 && game->grid[i][j] == game->grid[i + 1][j])
				return (0);
			if (j < game->grid_size - 1 && game->grid[i][j] == game->grid[i][j + 1])
				return (0);
		}
	}
	game->gameover = 1;
	return (1);
}

static void	check_win_stat(t_game *game)
{
	int	height;
	int	width;

	if (game->won && !game->msg_shown)
	{
		clear();
		getmaxyx(stdscr, height, width);
		mvprintw(height / 2, (width - 9) / 2, "You Won!");
		mvprintw(height / 2 + 1, (width - 26) / 2, "Press any key to continue");
		refresh();
		getch();
		draw_board(game);
		game->msg_shown = 1;
	}
}

int	game_loop(t_game *game)
{
	int	ch;

	while (1)
	{
		// if (g_sig == SIGWINCH)
		// {
		// 	clear();
		// 	draw_board(game);
		// 	g_sig = 0;
		// }
		check_win_stat(game);
		if (check_game_over(game))
			break ;
		ch = getch();
		if (ch == ESCAPE || ch == 'q')
		{
			break ;
		}
		// if (g_sig == SIGWINCH)
		// {
			// clear();
			// draw_board(game);
			// g_sig = 0;
		// }
		handle_key_events(ch, game);
	}
	game_over_handler();
	return (0);
}
