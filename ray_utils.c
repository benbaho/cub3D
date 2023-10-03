/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:21:16 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 17:45:34 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	getperpwalldist(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->sidedist.x - ray->deltadist.x);
	else
		return (ray->sidedist.y - ray->deltadist.y);
}

t_ray	*setwall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		game->draw->wallx = \
			game->player->pos.y + game->draw->perpwalldist * ray->raydir.y;
		if (ray->map.x < game->player->pos.x)
			game->draw->wall_x = 2;
		else
			game->draw->wall_x = 3;
	}
	else
	{
		game->draw->wallx = \
			game->player->pos.x + game->draw->perpwalldist * ray->raydir.x;
		if (ray->map.y < game->player->pos.y)
			game->draw->wall_x = 0;
		else
			game->draw->wall_x = 1;
	}
	return (ray);
}
