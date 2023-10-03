/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:36:49 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 22:30:21 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	win_init(t_game	*game)
{
	int	a;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Error: MLX init fail", game);
	game->win = mlx_new_window(game->mlx, WINX, WINY, "CUB3D");
	if (!game->win)
		ft_error("Error: MLX window fail", game);
	game->screen_image = malloc(sizeof(t_image));
	if (!game->screen_image)
		ft_error("Error: MLX image fail", game);
	game->screen_image->img = mlx_new_image(game->mlx, WINX, WINY);
	game->screen_image->adr = mlx_get_data_addr(game->screen_image->img,
			&game->screen_image->bpp, &game->screen_image->line_length,
			&game->screen_image->endian);
}

void	key_init(t_game *game)
{
	game->key = malloc(sizeof(t_keys));
	if (!game->key)
		ft_error("Error: t_keys malloc error.\n", game);
	game->key->key_w = 0;
	game->key->key_a = 0;
	game->key->key_s = 0;
	game->key->key_d = 0;
	game->key->key_left = 0;
	game->key->key_right = 0;
}

void	ray_init(t_game	*game)
{
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		ft_error("Error: t_ray malloc error.\n", game);
}

void	player_init(t_game	*game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_error("Error: t_player malloc error.\n", game);
	game->player->dir.x = 0;
	game->player->dir.y = 0;
	game->player->plane.x = 0;
	game->player->plane.y = 0;
	game->player->player_dir = 0;
}

void	game_init(t_game *game)
{
	game->argv = NULL;
	game->player = NULL;
	game->screen_image = NULL;
	game->textures = NULL;
	game->ray = NULL;
	game->map = NULL;
	game->key = NULL;
	game->draw = NULL;
}
