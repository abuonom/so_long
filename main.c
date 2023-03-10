/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:46:50 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/10 16:57:36 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mapbuild(char *path, t_game *game)
{
	int		fd;
	char	*map_str;

	map_str = malloc(sizeof(char) * 10000000);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_game(game);
	read(fd, map_str, 10000000);
	game->map = ft_split(map_str, '\n');
	free(map_str);
	if (!game->map)
		exit(0);
	check_map(game);
	close(fd);
}

int check_ber(char *path)
{
	int i;
	i = ft_strlen(path);
	if(path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b' || path[i - 4] != '.')
		return (1);
	return (0);
}

static void	window_size(t_game *game)
{
	int	i;

	game->winw = ft_strlen(game->map[0]) * 64 ;
	i = 0;
	while (game->map[i])
		i++;
	game->winh = i * 64;
}

int	main(int argc, char **argv)
{
	if(argc < 2 || check_ber(argv[1]) == 1)
		return (1);
	t_game game;
	game.mlx = mlx_init();
	mapbuild(argv[1],&game);
	window_size(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.winw, game.winh, "So Long");
	init_map(&game);
	gameplay(&game);
	return (0);
}
