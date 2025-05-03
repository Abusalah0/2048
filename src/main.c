/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/03 22:31:03 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(void)
{
	t_game game;
	
	if (init(&game))
	{
		return (1);
	}
	start(&game);
	clear();
	endwin();
	return (0);
}