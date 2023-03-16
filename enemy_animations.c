/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:51:04 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/16 16:06:46 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_frame_enemy(t_game *game)
{
	if (game->enemy_frame <= FIRST)
		game->enemy_img = build_img(game->mlx, "./images/ENEMY_1.xpm");
	if (game->enemy_frame <= SECOND && game->enemy_frame >= FIRST)
		game->enemy_img = build_img(game->mlx, "./images/ENEMY_2.xpm");
	if (game->enemy_frame <= THIRD && game->enemy_frame >= SECOND)
		game->enemy_img = build_img(game->mlx, "./images/ENEMY_3.xpm");
	if (game->enemy_frame == THIRD + 30)
		game->enemy_frame = 1;
}

void	choose_frame_collect(t_game *game)
{
	if (game->collect_frame <= FIRST)
		game->collect_img = build_img(game->mlx, "./images/COLLECT 1.xpm");
	if (game->collect_frame <= SECOND && game->collect_frame >= FIRST)
		game->collect_img = build_img(game->mlx, "./images/COLLECT 2.xpm");
	if (game->collect_frame <= THIRD && game->collect_frame >= SECOND)
		game->collect_img = build_img(game->mlx, "./images/COLLECT 3.xpm");
	if (game->collect_frame == THIRD + 10)
		game->collect_frame = 1;
}

void	print_frame(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->enemy_frame++;
	game->collect_frame++;
	game->y = 0;
	while (game->map[++i] != NULL)
	{
		j = -1;
		game->x = 0;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'C')
				print_image(*game, game->collect_img, game->x, game->y);
			if (game->map[i][j] == 'Z')
				print_image(*game, game->enemy_img, game->x, game->y);
			game->x += 64;
		}
		game->y += 64;
	}
	choose_frame_enemy(game);
	choose_frame_collect(game);
}
