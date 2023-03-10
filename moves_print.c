/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:49:58 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 17:39:56 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, 25, 20, 16777215, "Moves: ");
	mlx_string_put(game->mlx, game->mlx_win, 125, 20, 16777215, moves);
	ft_putstr("MOVES: ");
	ft_putstr(moves);
	ft_putstr("\n");
	free(moves);
}

void	you_win(t_game *game)
{
	exit_game(game);
}
