/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:53:53 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/09 16:02:56 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_2048.h"

static int	init_board_nums(t_game *game)
{
	spawn_random_tile(game);
	spawn_random_tile(game);
	return (0);
}

int	start(t_game *game)
{
	if (start_menu(game))
		return (0);
	init_board_nums(game);
	draw_board(game);
	game_loop(game);
	return (0);
}