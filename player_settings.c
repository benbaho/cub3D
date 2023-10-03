/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:17:32 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/18 17:47:38 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	setplane(t_game *game, char d)
{
	if (d == 'N')
	{
		game->player->plane.x = FOV;
		game->player->plane.y = 0;
	}
	else if (d == 'S')
	{
		game->player->plane.x = -FOV;
		game->player->plane.y = 0;
	}
	else if (d == 'W')
	{
		game->player->plane.x = 0;
		game->player->plane.y = -FOV;
	}
	else if (d == 'E')
	{
		game->player->plane.x = 0;
		game->player->plane.y = FOV;
	}
}

void	getplayerdir(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
	}
	else if (c == 'S')
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
	}
	else if (c == 'W')
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
	}
	else if (c == 'E')
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
	}
	setplane(game, c);
}

int	find_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->parsed_map[++i])
	{
		j = -1;
		while (game->map->parsed_map[i][++j])
		{
			if (ft_strchr("NSEW", game->map->parsed_map[i][j]))
			{
				game->player->pos.x = (double)j + 0.5;
				game->player->pos.y = (double)i + 0.5;
				getplayerdir(game, game->map->parsed_map[i][j]);
				return (1);
			}
		}
	}
	return (0);
}
