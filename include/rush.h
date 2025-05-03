/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:48:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 22:31:08 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "../libft/libft.h"
# include <ncurses.h>
# include <signal.h>
# include <stdbool.h>
# include <time.h>

# define DEFAULT_TARGET 2048
# define ESCAPE 27
# define ENTER 10
# define BOARD_RATIO 90
# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct s_game
{
	int	grid[5][5];
	int	score;
	int	won;
	int	gameover;
	int	msg_shown;
	int	target;
	int colors;
	int grid_size;
}		t_game;

int		get_random_num(void);
int		get_random_pos(t_game *game);
int		init(t_game *game);
int		start(t_game *game);
int		fill_board(t_game *game);
int		draw_board(t_game *game);
int		handle_key_events(int key, t_game *game);
int		spawn_random_tile(t_game *game);
void	up_key_event(t_game *game);
void	down_key_event(t_game *game);
void	left_key_event(t_game *game);
void	right_key_event(t_game *game);
int		game_loop(t_game *game);
void	resize_handler(int sig);
void	color_setup(int is_colored, int num);
void	reset_color(int is_colored);
int		start_menu(t_game *game);
int		count_digits(int n);

#endif // rush