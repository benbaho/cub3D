/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:41:56 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 20:58:53 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_game(t_game *game)
{
	ft_error("[RED_BUTTON] Game has been closed.", game);
	return (1);
}

void	ft_error(char *msg, t_game *game)
{
	printf("%s", msg);
	free_all(game);
	exit(1);
}

void	init_all(t_game *game, char *map_location)
{
	game_init(game);
	player_init(game);
	map_init(game, map_location);
	win_init(game);
	key_init(game);
	texture_init(game);
	ray_init(game);
}

int	loop(t_game *game)
{
	if (move(game))
		render(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error: Map not found\n");
		return (1);
	}
	init_all(&game, argv[1]);
	mlx_hook(game.win, 2, 1L << 0, key_events, &game);
	mlx_hook(game.win, 3, 1L << 1, key_deactive, &game);
	mlx_hook(game.win, 17, 1L << 0, close_game, &game);
	mlx_loop_hook(game.mlx, loop, &game);
	raycasting(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.screen_image->img, 0, 0);
	mlx_loop(game.mlx);
	free_all(&game);
}
