/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:30:44 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 15:47:04 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void you_win(t_game *game)
{
	exit_game(game);
}

int is_wall(int i,int j, char **map)
{
	if(map[i][j] == '1')
		return (1);
	return (0);
}

void move_w(t_game *game)
{
	if(game->map[game->pi - 1][game->pj] != '1')
	{
		game->player_img = build_img(game->mlx, "./images/UP.xpm");
		if(game->map[game->pi - 1][game->pj] == 'C')
			game->numb_collect--;
		if(game->map[game->pi - 1][game->pj] == 'E' && game->numb_collect == 0)
			you_win(game);
		if(game->map[game->pi - 1][game->pj] == 'Z')
			exit_died(game);
		if(game->map[game->pi - 1][game->pj] == '0' || game->map[game->pi - 1][game->pj] == 'C')
		{
			game->pi--;
			game->map[game->pi][game->pj] = 'P';
			game->map[game->pi + 1][game->pj] = '0';
			print_map(game);
		}
	}
}

void move_s(t_game *game)
{
	if(game->map[game->pi + 1][game->pj] != '1')
	{
		game->player_img = build_img(game->mlx, "./images/DOWN.xpm");
		if(game->map[game->pi + 1][game->pj] == 'C')
			game->numb_collect--;
		if(game->map[game->pi + 1][game->pj] == 'E' && game->numb_collect == 0)
			you_win(game);
		if(game->map[game->pi + 1][game->pj] == 'Z')
			exit_died(game);
		if(game->map[game->pi + 1][game->pj] == '0' || game->map[game->pi + 1][game->pj] == 'C')
		{
			game->pi++;
			game->map[game->pi][game->pj] = 'P';
			game->map[game->pi - 1][game->pj] = '0';
			print_map(game);
		}
	}
}

void move_a(t_game *game)
{
	if(game->map[game->pi][game->pj - 1] != '1')
	{
		game->player_img = build_img(game->mlx, "./images/LEFT.xpm");
		if(game->map[game->pi][game->pj - 1] == 'C')
			game->numb_collect--;
		if(game->map[game->pi][game->pj - 1] == 'E' && game->numb_collect == 0)
			you_win(game);
		if(game->map[game->pi][game->pj - 1] == 'Z')
			exit_died(game);
		if(game->map[game->pi][game->pj - 1] == '0' || game->map[game->pi][game->pj - 1] == 'C')
		{
			game->pj--;
			game->map[game->pi][game->pj] = 'P';
			game->map[game->pi ][game->pj + 1] = '0';
			print_map(game);
		}
	}
}

void move_d(t_game *game)
{
	if(game->map[game->pi][game->pj + 1] != '1')
	{
		game->player_img = build_img(game->mlx, "./images/RIGHT.xpm");
		if(game->map[game->pi][game->pj + 1] == 'C')
			game->numb_collect--;
		if(game->map[game->pi][game->pj + 1] == 'E' && game->numb_collect == 0)
			you_win(game);
		if(game->map[game->pi][game->pj + 1] == 'Z')
			exit_died(game);
		if(game->map[game->pi][game->pj + 1] == '0' || game->map[game->pi][game->pj + 1] == 'C')
		{
			game->pj++;
			game->map[game->pi][game->pj] = 'P';
			game->map[game->pi][game->pj - 1] = '0';
			print_map(game);
		}
	}
}
