/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperdemirci <alperdemirci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:12:31 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/17 21:24:44 by alperdemirc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	getdis(double newpos)
{
	return (newpos * 2 * 0.20);
}

void	turn(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->key->key_left)
	{
		game->player->dir.x = game->player->dir.x * cos(-TURNSPEED)
			- game->player->dir.y * sin(-TURNSPEED);
		game->player->dir.y = olddirx * sin(-TURNSPEED)
			+ game->player->dir.y * cos(-TURNSPEED);
		game->player->plane.x = game->player->plane.x * cos(-TURNSPEED)
			- game->player->plane.y * sin(-TURNSPEED);
		game->player->plane.y = oldplanex * sin(-TURNSPEED)
			+ game->player->plane.y * cos(-TURNSPEED);
		return ;
	}
	game->player->dir.x = game->player->dir.x * cos(TURNSPEED)
		- game->player->dir.y * sin(TURNSPEED);
	game->player->dir.y = olddirx * sin(TURNSPEED)
		+ game->player->dir.y * cos(TURNSPEED);
	game->player->plane.x = game->player->plane.x * cos(TURNSPEED)
		- game->player->plane.y * sin(TURNSPEED);
	game->player->plane.y = oldplanex * sin(TURNSPEED)
		+ game->player->plane.y * cos(TURNSPEED);
}

void	setpos(t_game *game, double newposx, double newposy, char mod)
{
	double	*posx;
	double	*posy;

	posx = &(game->player->pos.x);
	posy = &(game->player->pos.y);
	if (mod == '-')
	{
		if (!(game->map->parsed_map[(int)(*posy - getdis(newposy))]))
			return ;
		if (ft_strchr("1", game->map->parsed_map[(int)(*posy - getdis(newposy))]
			[(int)(*posx - getdis(newposx))]))
			return ;
		game->player->pos.x -= newposx * (5 * 0.015f);
		game->player->pos.y -= newposy * (5 * 0.015f);
	}
	else if (mod == '+')
	{
		if (!(game->map->parsed_map[(int)(*posy + getdis(newposy))]))
			return ;
		if (ft_strchr("1", game->map->parsed_map[(int)(*posy + getdis(newposy))]
			[(int)(*posx + getdis(newposx))]))
			return ;
		game->player->pos.x += newposx * (5 * 0.015f);
		game->player->pos.y += newposy * (5 * 0.015f);
	}
}
