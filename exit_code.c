/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:10:27 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 17:32:31 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	free_map(game);
	mlx_destroy_image(game->mlx, game->back_img);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->enemy_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void	exit_check(t_game *game)
{
	free_map(game);
	ft_putstr("Error\nMap not allowed\n");
	exit(0);
}

void	exit_died(t_game *game)
{
	game->end_game = 1;
	game->player_img = build_img(game->mlx, "./images/DEATH.xpm");
	print_map(game);
}

int	cross_exit(t_game *game)
{
	exit_game(game);
	return (0);
}

void	exit_status(t_game *game)
{
	if (game->numb_collect == 0)
		game->exit_img = build_img(game->mlx, "./images/EXIT_YES.xpm");
}
