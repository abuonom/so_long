/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:51:04 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 15:11:48 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void choose_frame(t_game *game)
{
	if(game->enemy_frame <= FIRST)
		game->enemy_img = build_img(game->mlx, "./images/ENEMY_1.xpm");
	if(game->enemy_frame <= SECOND && game->enemy_frame >= FIRST)
		game->enemy_img = build_img(game->mlx, "./images/ENEMY_2.xpm");
	if(game->enemy_frame <= THIRD && game->enemy_frame >= SECOND)
		game->enemy_img = build_img(game->mlx, "./images/ENEMY_3.xpm");
	if(game->enemy_frame == THIRD + 30)
		game->enemy_frame = 1;
}

void print_frame(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->enemy_frame++;
	game->y = 0;
	while (game->map[++i] != NULL)
	{
		j = -1;
		game->x = 0;
		while (game->map[i][++j] != '\0')
		{
			if(game->map[i][j] == 'Z')
				print_image(*game, game->enemy_img, game->x, game->y);
			game->x += 64;
		}
		game->y += 64;
	}
	choose_frame(game);
}
