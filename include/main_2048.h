/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:48:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/09 15:50:51 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "../libft/include/libft.h"
# include <ncurses.h>
# include <signal.h>
# include <stdbool.h>
# include <time.h>

# define DEFAULT_TARGET 2048
# define ESCAPE 27
# define ENTER 10
# define BOARD_RATIO 90
# define MAX_GRID_SIZE 5
# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

/*
* this is a mandatory enum required by the project
*/
enum	e_const
{
	WIN_VALUE = 2048
};

/*
 * a structure to hold the game state and the grid
 */
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

/**
	@brief 	generate a random number (2 or 4) based on a definded probability
	@param
		none
	@returns
		- int 2 or 4
*/
int		get_random_num(void);

/**
 *   @brief 	get a random position in the grid
 *   @param 
 * 		game: pointer to the game structure
 * 	@returns
 * 		- int: the random position in the grid
 *  @returns
 * 		- -1 if no empty cells are found
 */
int		get_random_pos(t_game *game);

/**
 * @brief 	initialize the game structure and ncurses
 * @param 
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
 */
int		init(t_game *game);

/**
 * @brief 	starts the game by calling the menu function and initializing the board and game loop
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
 */
int		start(t_game *game);

/**
 * @brief  prints the numbers on the board
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
 */
int		fill_board(t_game *game);

/**
 * @brief 	draws the board without numbers using ncurses, fills a defined ratio of the screen
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 
 * 		- 1 if failed
 */
int		draw_board(t_game *game);

/**
 * @brief 	handle key (arrows) events and trigger redraw only if the board changed or the window was resized
 * 
 * @param
 * 		key: the key pressed
 * 	@param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
*/
int		handle_key_events(int key, t_game *game);

/**
 * @brief 	spawn a random tile (2 or 4) in a random empty cell in the grid
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
*/
int		spawn_random_tile(t_game *game);

/**
 * @brief 	handle the key event for moving the tiles up in the grid
 * 
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		void
 */
void	up_key_event(t_game *game);


/**
 * @brief 	handle the key event for moving the tiles down in the grid
 * 
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		void
 */
void	down_key_event(t_game *game);

/**
 * @brief 	handle the key event for moving the tiles left in the grid
 * 
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		void
 */
void	left_key_event(t_game *game);

/**
 * @brief 	handle the key event for moving the tiles right in the grid
 * 
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		void
 */
void	right_key_event(t_game *game);


/**
 * @brief 	game loop function that handles the game logic and events
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
 */
int		game_loop(t_game *game);

/**
 * @brief 	choose the color of the tile based on its value, if the coloring is enabled
 * @param
 * 		is_colored: 1 if the coloring is enabled, 0 otherwise
 * @param
 * 		num: the number to be colored
 * @returns
 * 		void
 */
void	color_setup(int is_colored, int num);

/**
 * @brief 	reset the color of the tile to default, if the coloring is enabled
 * @param
 * 		is_colored: 1 if the coloring is enabled, 0 otherwise
 * @returns
 * 		void
 */
void	reset_color(int is_colored);

/**
 * @brief 	create the starting menus using ncurses
 * @param
 * 		game: pointer to the game structure
 * @returns
 * 		- 0 if successful
 * @returns
 * 		- 1 if failed
 */
int		start_menu(t_game *game);

#endif // RUSH_H