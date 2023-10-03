/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:18:07 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 21:12:20 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ray	*rayinits(t_game *game)
{
	game->ray->dir.x = game->player->dir.x;
	game->ray->dir.y = game->player->dir.y;
	game->ray->plane.x = game->player->plane.x;
	game->ray->plane.y = game->player->plane.y;
	game->ray->pos.x = game->player->pos.x;
	game->ray->pos.y = game->player->pos.y;
	return (game->ray);
}

void	raycasting(t_game *game)
{
	t_ray	*ray;
	int		i;

	ray = rayinits(game);
	i = -1;
	while (++i < WINX)
	{
		ray = raycastloopstart(ray, i);
		ray = summonray(game, ray);
		ray = getwalllength(game, ray);
		drawvertical(i, game, ray);
	}
}

void	render(t_game *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->screen_image->img, 0, 0);
}
