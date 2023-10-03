/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawstart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:33:12 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 22:42:38 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	get_texture_color(t_image *texture, int x, int y)
{
	return (*(size_t *)((texture->adr + (y * texture->line_length)
			+ (x * texture->bpp / 8))));
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > WINY)
		return ;
	if (x < 0 || x > WINX)
		return ;
	if (!image->adr)
		return ;
	dst = (char *)image->adr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	fillimage(int x, t_game *game, t_ray *ray)
{
	size_t	y;
	t_image	tmp;

	y = -1;
	tmp = game->textures->tex[game->draw->wall_x];
	while (++y < WINY)
	{
		if (y < (size_t)game->draw->drawwall.x)
			my_mlx_pixel_put(game->screen_image, x, y, game->textures->c_color);
		else if (y < (size_t)game->draw->drawwall.y)
		{
			game->draw->tex.y = (int)game->draw->texpos & (64 - 1);
			game->draw->texpos += game->draw->step;
			game->draw->color = \
				get_texture_color(&tmp,
					game->draw->tex.x, game->draw->tex.y);
			my_mlx_pixel_put(game->screen_image, x, y, game->draw->color);
		}
		else
		{
			my_mlx_pixel_put(game->screen_image, x, y, game->textures->f_color);
		}
	}
}

void	drawvertical(int x, t_game *game, t_ray *ray)
{
	game->draw->wallx -= floor(game->draw->wallx);
	game->draw->tex.x = (int)(game->draw->wallx * (double)(64));
	if (ray->side == 0 && ray->raydir.x > 0)
		game->draw->tex.x = 64 - game->draw->tex.x - 1;
	if (ray->side == 1 && ray->raydir.y < 0)
		game->draw->tex.x = 64 - game->draw->tex.x - 1;
	game->draw->step = 1.0 * 64 / game->draw->line_h;
	game->draw->texpos = \
		(game->draw->drawwall.x - WINY / 2 + game->draw->line_h / 2)
		* game->draw->step;
	fillimage(x, game, ray);
}
