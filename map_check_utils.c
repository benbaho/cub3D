/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:48:18 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/19 19:10:30 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_line_check(t_game *game)
{
	int		i;
	char	*map_start;
	char	*trim_map;

	map_start = ft_strnstr(game->normal_map, \
		game->last_info, ft_strlen(game->normal_map)) + \
		ft_strlen(game->last_info) + 1;
	map_start = ft_strtrim(map_start, "\n");
	if (ft_strnstr(map_start, "\n\n", ft_strlen(map_start)) == NULL)
	{
		if (map_start)
			free(map_start);
		return (1);
	}
	if (map_start)
		free(map_start);
	return (0);
}

int	color_check(char *color)
{
	char	**split_color;
	int		i;
	int		number;

	i = -1;
	split_color = ft_split(color, ',');
	if (ft_strlen(color) > 11 || ft_strlen(color) < 5
		|| ft_2dstrlen(split_color) != 3)
		return (0);
	while (split_color[++i])
	{	
		if (!ft_strisdigit(split_color[i]))
			return (0);
		number = ft_atoi(split_color[i]);
		if (!(number >= 0 && number <= 255))
		{
			free_arr(split_color);
			return (0);
		}
	}
	free_arr(split_color);
	return (1);
}

int	file_open_check(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_char(char c, t_game *game)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N'
		&& c != 'W' && c != 'S' && c != 'E')
		return (1);
	else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		game->player->player_dir += 1;
	if (game->player->player_dir > 1)
		return (1);
	return (0);
}

int	check_map_elements(t_game *game)
{
	int	i;
	int	c;

	i = -1;
	while (game->map->parsed_map[++i])
	{
		c = 0;
		while (game->map->parsed_map[i][c])
		{
			if (check_char(game->map->parsed_map[i][c], game))
				return (0);
			c++;
		}
	}
	return (1);
}
