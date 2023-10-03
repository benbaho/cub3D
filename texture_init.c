/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:22:59 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 20:52:01 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_color(char *str)
{
	char	**color_codes;
	int		result;
	int		i;

	color_codes = ft_split(str, ',');
	result = ft_atoi(color_codes[0]) * 256 * 256 + ft_atoi(color_codes[1])
		* 256 + ft_atoi(color_codes[2]);
	i = -1;
	free_arr(color_codes);
	return (result);
}

void	get_adress(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->textures->tex[i].adr
			= mlx_get_data_addr(game->textures->tex[i].img,
				&game->textures->tex[i].bpp,
				&game->textures->tex[i].line_length,
				&game->textures->tex[i].endian);
	}
}

void	*convert_xpm(t_game *game, char *path)
{	
	int	size;

	return (mlx_xpm_file_to_image(game->mlx, path, &size, &size));
}

void	texture_init(t_game *game)
{
	game->textures = malloc((sizeof(t_texture)));
	if (!game->textures)
		ft_error("Error: t_texture or t_draw  malloc.\n", game);
	game->draw = malloc(sizeof(t_draw));
	if (!game->draw)
		ft_error("Error: t_texture or t_draw  malloc.\n", game);
	game->textures->f_color = get_color(game->map->f_color);
	game->textures->c_color = get_color(game->map->c_color);
	game->textures->tex[0].img = convert_xpm(game, game->map->north_path);
	game->textures->tex[1].img = convert_xpm(game, game->map->south_path);
	game->textures->tex[2].img = convert_xpm(game, game->map->west_path);
	game->textures->tex[3].img = convert_xpm(game, game->map->east_path);
	get_adress(game);
}
