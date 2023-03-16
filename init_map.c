/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:46:50 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/16 15:58:07 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_image_player(t_game *game, int i, int j)
{
	print_image(*game, game->player_img, game->x, game->y);
	game->pi = i;
	game->pj = j;
}

static void	print_image_exit(t_game *game)
{
	exit_status(game);
	print_image(*game, game->exit_img, game->x, game->y);
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->y = 0;
	game->moves++;
	while (game->map[++i] != NULL)
	{
		j = -1;
		game->x = 0;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == '0')
				print_image(*game, game->back_img, game->x, game->y);
			if (game->map[i][j] == '1')
				print_image(*game, game->wall_img, game->x, game->y);
			if (game->map[i][j] == 'P')
				print_image_player(game, i, j);
			game->x += 64;
		}
		game->y += 64;
	}
	print_moves(game);
	print_collect_exit_enemy(game);
}

void	print_collect_exit_enemy(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->y = 0;
	while (game->map[++i] != NULL)
	{
		j = -1;
		game->x = 0;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'E')
				print_image_exit(game);
			game->x += 64;
		}
		game->y += 64;
	}
}

void	init_map(t_game *game)
{
	game->moves = -1;
	*game = image_buffer(*game);
	print_map(game);
}
