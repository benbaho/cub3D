/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:56:16 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/19 19:10:50 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_reader(t_game *game, char *av)
{
	int		fd;
	int		map_start;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("Error: File Not Found!\n", game);
	game->normal_map = read_map(fd);
	close(fd);
	game->argv = ft_split(game->normal_map, '\n');
}	

int	write_path(char **dest, char *line, char *key)
{
	char	**split_line;
	int		res;

	split_line = ft_split(line, ' ');
	res = ft_strncmp(split_line[0], key, ft_strlen(split_line[0]));
	if (res == 0)
	{
		*dest = ft_strdup(split_line[1]);
		free_arr(split_line);
		return (1);
	}
	free_arr(split_line);
	return (0);
}

int	check_texture_path(t_game *game)
{
	if (!game->map->north_path || !game->map->south_path
		|| !game->map->east_path || !game->map->west_path
		|| !game->map->c_color || !game->map->f_color)
		return (0);
	return (1);
}

int	texture_path_init(t_game *game)
{
	char	**av;
	int		i;
	int		count;

	av = game->argv;
	i = -1;
	count = 0;
	while (av[++i])
	{
		if (write_path(&game->map->west_path, av[i], "WE")
			|| write_path(&game->map->south_path, av[i], "SO")
			|| write_path(&game->map->north_path, av[i], "NO")
			|| write_path(&game->map->east_path, av[i], "EA")
			|| write_path(&game->map->f_color, av[i], "F")
			|| write_path(&game->map->c_color, av[i], "C"))
			count++;
		else if (count == 6)
		{
			game->last_info = av[i - 1];
			break ;
		}
	}
	return (i);
}

void	map_init(t_game *game, char *map_location)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_error("Error: malloc error", game);
	config_null(game);
	if (!ft_strnstr(&map_location[ft_strlen(map_location) - 4],
			".cub", ft_strlen(map_location)))
		ft_error("Error: bad file type", game);
	map_reader(game, map_location);
	game->map->parsed_map = &game->argv[texture_path_init(game)];
	if (!(*game->map->parsed_map))
		ft_error("Error: sth wrong with map file.", game);
	map_check(game);
}
