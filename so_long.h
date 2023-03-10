/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:47:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 17:43:37 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

typedef struct s_data {
	char	**map;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*wall_img;
	void	*back_img;
	void	*enemy_img;
	void	*mlx;
	void	*mlx_win;
	int		winh;
	int		winw;
	int		x;
	int		y;
	int		pi;
	int		pj;
	int		numb_play;
	int		numb_collect;
	int		numb_exit;
	int		enemy_frame;
	int		moves;
	int		end_game;
}				t_game;

# define ESC 53
# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define FIRST 15
# define SECOND 30
# define THIRD 50

void	mapbuild(char *path, t_game *game);
void	check_map(t_game *game);
void	init_map(t_game *game);
void	*build_img(void *mlx, char *path);
t_game	image_buffer(t_game game);
void	gameplay(t_game *game);
void	exit_game(t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	print_image(t_game game, void *i, int x, int y);
void	print_map(t_game *game);
void	count_collectible(t_game *game);
void	exit_status(t_game *game);
void	print_frame(t_game *game);
void	exit_check(t_game *game);
void	print_moves(t_game *game);
void	exit_died(t_game *game);
int		cross_exit(t_game *game);
void	free_map(t_game *game);
void	print_collect_exit_enemy(t_game *game);
void	you_win(t_game *game);
#endif
