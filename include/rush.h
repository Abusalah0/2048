/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:48:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 19:06:33 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "../libft/libft.h"
# include <ncurses.h>
# include <signal.h>
# include <stdbool.h>
# include <time.h>

# define GRID_SIZE 4
# define DEFAULT_TARGET 2048
# define ESCAPE 27
# define ENTER 10
# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
extern int g_sig;

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct s_game
{
	int	grid[GRID_SIZE][GRID_SIZE];
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
void	init(t_game *game);
int		start(t_game *game);
int		draw_initial_board(void);
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
void	start_menu(t_game *game);

#endif // rush