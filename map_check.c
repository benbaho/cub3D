/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:46:52 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/19 17:57:43 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_all_sides(char **strs, int j)
{
	if (ft_isspace(strs[-1][j - 1]) || !strs[-1][j - 1])
		return (0);
	if (ft_isspace(strs[-1][j]) || !strs[-1][j])
		return (0);
	if (ft_isspace(strs[-1][j + 1]) || !strs[-1][j + 1])
		return (0);
	if (ft_isspace(strs[0][j - 1]) || !strs[0][j - 1])
		return (0);
	if (ft_isspace(strs[0][j + 1]) || !strs[0][j + 1])
		return (0);
	if (ft_isspace(strs[1][j - 1]) || !strs[1][j - 1])
		return (0);
	if (ft_isspace(strs[1][j]) || !strs[1][j])
		return (0);
	if (ft_isspace(strs[1][j + 1]) || !strs[1][j + 1])
		return (0);
	return (1);
}

int	checkmapclosed(char **strs)
{
	int	j;

	j = 0;
	while (strs[0][j])
	{
		if (strs[0][j] == '0')
		{
			if (!check_all_sides(strs, j))
				return (0);
		}
		j++;
	}
	return (1);
}

int	checkwall(char *str)
{
	while (*str)
	{
		if (*str != '1' && !ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_valid_map(t_game *game)
{
	int		i;
	char	**strs;

	strs = game->map->parsed_map;
	i = -1;
	while (strs[++i])
	{
		if ((i == 0 || i == ft_2dstrlen(strs) - 1) && !checkwall(strs[i]))
			return (0);
		else
		{
			if (!checkmapclosed(&strs[i]))
				return (0);
		}
	}
	return (1);
}

void	map_check(t_game	*game)
{
	if (!check_texture_path(game))
		ft_error("Error: Map texture or color info error\n", game);
	if (!map_line_check(game))
		ft_error("Error: Map line", game);
	if (!check_map_elements(game))
		ft_error("Error: There is sth wrong in map", game);
	if (!find_player(game))
		ft_error("Error: Something wrong with player.\n", game);
	if (!file_open_check(game->map->north_path)
		|| !file_open_check(game->map->south_path)
		|| !file_open_check(game->map->east_path)
		|| !file_open_check(game->map->west_path))
		ft_error("Error: Texture file open error.", game);
	if (!color_check(game->map->f_color) || !color_check(game->map->c_color))
		ft_error("Error: Color info type error.", game);
	if (!check_valid_map(game))
		ft_error("Error: Something wrong with map.\n", game);
}
