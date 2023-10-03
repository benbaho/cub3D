/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperdemirci <alperdemirci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:21:50 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/16 19:17:26 by alperdemirc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*read_map(int fd)
{
	int			rd_bytes;
	char		map[2];
	char		*value;

	value = NULL;
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, map, 1);
		map[rd_bytes] = '\0';
		value = ft_str_join(value, map);
	}
	return (value);
}
