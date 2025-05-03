/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:44:22 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 22:28:47 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	board_changed(int *old, int *new, int size)
{
    int total = size * size;
    for (int k = 0; k < total; k++)
        if (old[k] != new[k])
            return (1);
    return (0);
}
int handle_key_events(int key, t_game *game)
{
    int old_board[game->grid_size][game->grid_size];
    bool moved;

    
    ft_memcpy(old_board,
           game->grid,
           game->grid_size * game->grid_size * sizeof(int));

    if (key == KEY_RESIZE)
    {
        resizeterm(0, 0);
        draw_board(game);
        return (0);
    }
    else if (key == KEY_UP)
        up_key_event(game);
    else if (key == KEY_DOWN)
        down_key_event(game);
    else if (key == KEY_LEFT)
        left_key_event(game);
    else if (key == KEY_RIGHT)
        right_key_event(game);
    else
        return (0);

    moved = board_changed(&old_board[0][0],
                          &game->grid[0][0],
                          game->grid_size);
    if (moved)
        spawn_random_tile(game);
    clear();
    draw_board(game);
    if (moved)
    {
        napms(10);
        flushinp();
    }
    return (0);
}