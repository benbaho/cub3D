/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:43:27 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/19 19:11:08 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_arr(char	**arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (arr[i])
			free(arr[i]);
	if (arr)
		free(arr);
}

void	free_map(t_game *game)
{
	if (game->map->north_path)
		free(game->map->north_path);
	if (game->map->south_path)
		free(game->map->south_path);
	if (game->map->east_path)
		free(game->map->east_path);
	if (game->map->west_path)
		free(game->map->west_path);
	if (game->map->f_color)
		free(game->map->f_color);
	if (game->map->c_color)
		free(game->map->c_color);
	if (game->map)
		free(game->map);
	if (game->normal_map)
		free(game->normal_map);
}

void	free_all(t_game *game)
{
	if (game->screen_image)
		mlx_destroy_image(game->mlx, game->screen_image->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->player)
		free(game->player);
	free_map(game);
	if (game->argv)
		free_arr(game->argv);
	if (game->screen_image)
		free(game->screen_image);
	if (game->key)
		free(game->key);
	if (game->textures)
		free(game->textures);
	if (game->draw)
		free(game->draw);
	if (game->ray)
		free(game->ray);
}
