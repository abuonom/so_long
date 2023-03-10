/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:03:52 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/09 17:12:50 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_other(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j]
			!= 'E' && game->map[i][j] != 'C' && game->map[i][j] != 'P' && game->map[i][j] != 'Z')
				exit_check(game);
		}
	}
}

void	check_least(t_game *game)
{
	int	i;
	int	j;

	game->numb_collect = 0;
	game->numb_exit = 0;
	game->numb_play = 0;
	i = -1;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->numb_exit++;
			if (game->map[i][j] == 'C')
				game->numb_collect++;
			if (game->map[i][j] == 'P')
				game->numb_play++;
		}
	}
	if(game->numb_exit < 1 && game->numb_collect < 1 && game->numb_play < 1)
		exit_check(game);
}

void	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (game->map[i][++j] != '\0')
	{
		if (game->map[i][j] != '1')
			exit_check(game);
	}
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			exit_check(game);
		i++;
	}
	j = 0;
	while (game->map[i - 1][j] != '\0')
	{
		if (game->map[i - 1][j] != '1')
			exit_check(game);
		j++;
	}
}

void	check_rectangular(t_game *game)
{
	int	i;
	int	lenght;
	int height;

	height = 0;
	i = 1;
	lenght = ft_strlen(game->map[height]);
	while(game->map[height])
		height++;
	while(game->map[i])
	{
		if((int)ft_strlen(game->map[i]) != lenght)
			exit_check(game);
		lenght = ft_strlen(game->map[i]);
		i++;
	}
	if(height == lenght)
		exit_check(game);
}

void	check_map(t_game *game)
{
	check_least(game);
	check_rectangular(game);
	check_other(game);
	check_wall(game);
}
