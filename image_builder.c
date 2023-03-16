/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:27:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/16 15:40:12 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_image(t_game game, void *i, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.mlx_win, i, x, y);
}

void	*build_img(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	return (img);
}

t_game	image_buffer(t_game game)
{
	game.x = 0;
	game.y = 0;
	game.wall_img = build_img(game.mlx, "./images/WALL_1.xpm");
	game.back_img = build_img(game.mlx, "./images/BACK.xpm");
	game.collect_img = build_img(game.mlx, "./images/COLLECT 0.xpm");
	game.player_img = build_img(game.mlx, "./images/START.xpm");
	game.exit_img = build_img(game.mlx, "./images/EXIT_NO.xpm");
	game.enemy_img = build_img(game.mlx, "./images/ENEMY_1.xpm");
	return (game);
}
