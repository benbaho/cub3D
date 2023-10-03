/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:32:37 by bdurmus           #+#    #+#             */
/*   Updated: 2023/06/19 19:11:22 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "inc/minilibx/mlx.h"
# include "inc/libft/libft.h"

# define WINX 1920
# define WINY 1080
# define ON_TURNR 124
# define ON_TURNL  123
# define ON_KEYA 0
# define ON_KEYW  13
# define ON_KEYS  1
# define ON_KEYD  2
# define ON_DESTROY 53
# define TURNSPEED 0.10f
# define FOV 0.66

typedef struct s_image
{
	void		*img;
	char		*adr;
	int			bpp;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_dvector
{
	double		x;
	double		y;
}	t_dvector;

typedef struct s_ivector
{
	int			x;
	int			y;
}	t_ivector;

typedef struct s_player
{
	t_dvector	pos;
	t_dvector	dir;
	t_dvector	plane;
	int			player_dir;
}	t_player;

typedef struct s_texture
{
	t_image		tex[4];
	int			f_color;
	int			c_color;
}	t_texture;

typedef struct s_ray
{
	t_dvector	dir;
	t_dvector	pos;
	t_dvector	plane;
	t_dvector	deltadist;
	t_dvector	sidedist;
	t_dvector	raydir;
	t_ivector	step;
	t_ivector	map;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_draw
{
	int			wall_x;
	int			color;
	int			line_h;
	double		step;
	double		texpos;
	double		wallx;
	double		perpwalldist;
	t_ivector	tex;
	t_ivector	drawwall;
}	t_draw;

typedef struct s_keys
{
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
}	t_keys;

typedef struct s_map
{
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	char		*c_color;
	char		*f_color;
	char		**parsed_map;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**argv;
	char		*normal_map;
	char		*last_info;
	t_player	*player;
	t_image		*screen_image;
	t_texture	*textures;
	t_ray		*ray;
	t_map		*map;
	t_keys		*key;
	t_draw		*draw;
}	t_game;

int		file_open_check(char *path);
int		check_valid_map(t_game *game);
char	*read_map(int fd);
void	win_init(t_game *game);
void	key_init(t_game *game);
void	texture_init(t_game *game);
int		map_line_check(t_game *game);
void	map_init(t_game *game, char *map_location);

int		ft_2dstrlen(char **av);
int		color_check(char *color);
void	map_check(t_game	*game);
int		texture_path_init(t_game *game);
int		check_map_elements(t_game *game);
int		check_texture_path(t_game *game);
int		key_events(int keycode, t_game *game);
int		key_deactive(int keycode, t_game *game);
char	*ft_str_join(char *left_str, char *buff);

int		move(t_game *game);
void	player_init(t_game *game);
void	ray_init(t_game *game);
void	turn(t_game *game);
void	game_init(t_game *game);
void	setpos(t_game *game, double newposx, double newposy, char mod);
//ray
t_ray	*raycastloopstart(t_ray *ray, int x);
t_ray	*summonray(t_game *game, t_ray *ray);
t_ray	*getwalllength(t_game *game, t_ray *ray);
t_ray	*setwall(t_game *game, t_ray *ray);
int		find_player(t_game *game);
void	render(t_game *game);
void	raycasting(t_game *game);
double	getperpwalldist(t_ray *ray);
void	drawvertical(int x, t_game *game, t_ray *ray);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
//frees
int		ft_isspace(char c);
void	free_arr(char	**arr);
void	free_map(t_game *game);
void	free_all(t_game *game);
void	ft_error(char *msg, t_game *game);
void	config_null(t_game *game);

#endif
