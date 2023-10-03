/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:19:45 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/19 17:19:18 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ray	*getwalllength(t_game *game, t_ray *ray)
{
	game->draw->perpwalldist = getperpwalldist(ray);
	game->draw->line_h = (int)(WINY / game->draw->perpwalldist);
	game->draw->drawwall.x = -game->draw->line_h / 2 + WINY / 2;
	if (game->draw->drawwall.x < 0)
		game->draw->drawwall.x = 0;
	game->draw->drawwall.y = game->draw->line_h / 2 + WINY / 2;
	if (game->draw->drawwall.y > WINY)
		game->draw->drawwall.y = WINY;
	ray = setwall(game, ray);
	return (ray);
}

t_ray	*summonray(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (!game->map->parsed_map[ray->map.y])
			break ;
		else if (ray->map.y >= 0 && game->map->parsed_map
			[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
	return (ray);
}

static t_ray	*setsidedist(t_ray *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->deltadist.y;
	}
	return (ray);
}

t_ray	*raycastloopstart(t_ray *ray, int x)
{
	double	camerax;

	camerax = 2 * x / (double)WINX - 1;
	ray->raydir.x = ray->dir.x + ray->plane.x * camerax;
	ray->raydir.y = ray->dir.y + ray->plane.y * camerax;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	ray->deltadist.x = fabs(1 / ray->raydir.x);
	ray->deltadist.y = fabs(1 / ray->raydir.y);
	ray = setsidedist(ray);
	ray->hit = 0;
	return (ray);
}
