/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperdemirci <alperdemirci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:39:55 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/17 21:38:55 by alperdemirc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_deactive(int keycode, t_game *game)
{
	if (keycode == ON_TURNL)
		game->key->key_left = 0;
	else if (keycode == ON_TURNR)
		game->key->key_right = 0;
	else if (keycode == ON_KEYA)
		game->key->key_a = 0;
	else if (keycode == ON_KEYD)
		game->key->key_d = 0;
	else if (keycode == ON_KEYW)
		game->key->key_w = 0;
	else if (keycode == ON_KEYS)
		game->key->key_s = 0;
	return (1);
}

int	key_events(int keycode, t_game *game)
{
	if (keycode == ON_DESTROY)
		ft_error("[ESC] Game has been closed.\n", game);
	else if (keycode == ON_TURNL)
		game->key->key_left = 1;
	else if (keycode == ON_TURNR)
		game->key->key_right = 1;
	else if (keycode == ON_KEYA)
		game->key->key_a = 1;
	else if (keycode == ON_KEYD)
		game->key->key_d = 1;
	else if (keycode == ON_KEYW)
		game->key->key_w = 1;
	else if (keycode == ON_KEYS)
		game->key->key_s = 1;
	return (1);
}

static int	retmove(t_game *game)
{
	if (game->key->key_a || game->key->key_w || game->key->key_s
		|| game->key->key_d || game->key->key_left || game->key->key_right)
		return (1);
	else
		return (0);
}

int	move(t_game *game)
{
	if (game->key->key_a)
		setpos(game, game->player->plane.x, game->player->plane.y, '-');
	if (game->key->key_d)
		setpos(game, game->player->plane.x, game->player->plane.y, '+');
	if (game->key->key_w)
		setpos(game, game->player->dir.x, game->player->dir.y, '+');
	if (game->key->key_s)
		setpos(game, game->player->dir.x, game->player->dir.y, '-');
	if (game->key->key_left || game->key->key_right)
		turn(game);
	return (retmove(game));
}
