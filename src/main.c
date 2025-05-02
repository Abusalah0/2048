/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 16:41:36 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	g_sig = 0;

int	main(void)
{
	t_game game;
	
	init(&game);
	start(&game);
	clear();
	endwin();
	return (0);
}