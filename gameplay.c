/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:12:27 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 15:51:50 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animation_loop(t_game *game)
{
	print_frame(game);
	return (0);
}

int key_pressed(int keycode, t_game *game)
{
	if(keycode == ESC || keycode == Q)
		exit_game(game);
	if(game->end_game == 0)
	{
		if(keycode == W || keycode == UP)
			move_w(game);
		if(keycode == S || keycode == DOWN)
			move_s(game);
		if(keycode == A || keycode == LEFT)
			move_a(game);
		if(keycode == D || keycode == RIGHT)
			move_d(game);
	}
	return (0);
}

void gameplay(t_game *game)
{
	game->end_game = 0;
    mlx_hook(game->mlx_win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, cross_exit, game);
	mlx_loop_hook(game->mlx, animation_loop, game);
	mlx_loop(game->mlx);
}


