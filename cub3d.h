/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:52:54 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/13 19:47:29 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "sources/get_next_line/get_next_line.h"
# include "sources/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "parssing/parssing.h"

# define BLOCK_W 64
# define BLOCK_L 64
# define FOV 60

typedef struct mlx_v
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*new_img;
	char		*title;
}	t_mlx;

typedef struct ray_calc_v
{
	double	x_inter;
	double	y_inter;
	double	ax;
	double	ay;
	double	angle;
	double	tan_angle;
	double	verif_y;
	double	verif_x;
}	t_ray_calc;

typedef struct line_vector
{
	long	line_length;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_line;

typedef struct player_v
{
	double	x_p;
	double	y_p;
	double	angle;
	int		rotation_speed;
}	t_player;

typedef struct map_v
{
	char			*type;
	struct mlx_v	*interface;
	int				**map_values;
	char			**m_values;
	mlx_texture_t	**all_textures;
	struct player_v	*player;
	int				width;
	int				height;
	uint32_t		floor;
	uint32_t		ceiling;
}	t_map_e;

typedef struct ray_v
{
	long				distance;
	int					hit_vertical;
	double				angle;
	double				x;
	double				bitmap_offset;
	double				tan;
	struct ray_v		*next;
	struct ray_v		*previous;
}	t_ray;

typedef struct bitmap_v
{
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			offset_x;
	double			offset_y;
	double			scaling_factor;
	uint32_t		color;
}	t_bitmap;

typedef struct wall_v
{
	long			distance;
	long			distance_to_projection;
	double			height;
	long			wall_height;
	long			wall_top;
	long			wall_bot;
	struct bitmap_v	*t;
	double			angle;
	struct wall_v	*next;
}	t_wall;

typedef struct data_v
{
	void			*data;
	struct data_v	*next;
}	t_data;

void	init_all_values(t_map_e *m, t_map *data);
void	init_textures(t_map_e *m, t_map *data);
void	update_texture(t_wall *w, t_ray *rays, t_map_e *m);
void	move_right(t_player *p, char **mapValues);
void	move_left(t_player *p, char **mapValues);
void	move_down(t_player *p, char **mapValues);
void	move_up(t_player *p, char **mapValues);
void	key_func(void *param);
void	terminate_game(t_map_e *m);
int		get_rgba(int r, int g, int b, int a);
void	draw_block(mlx_image_t *img, int x, int y, char value);
void	apply_dda_algorithm(t_map_e *m);
void	draw_player(t_map_e *map);
void	apply_dda_algorithm(t_map_e *m);
void	draw_3d_walls(t_map_e *m);
void	ft_lstadd_back(t_ray **lst, t_ray *new);
t_ray	*ft_lstnew(double x);
void	draw_mini_map(t_map_e *m, char **data, int flag);
int		wall_contact(t_player *p, char **mapValues);
void	init_player_instance(t_map_e *map3d, t_map *data);
void	my_put_mlx(t_map_e *map, int x, int y);
int		convert_pixel_to_color(uint32_t color);
void	draw_sky(t_map_e *m, int x, t_wall *w);
void	draw_floor(t_wall *w, t_map_e *m, int x);
void	draw_sky(t_map_e *m, int x, t_wall *w);
void	draw_floor(t_wall *w, t_map_e *m, int x);
void	apply_dda_algorithm(t_map_e *m);
int		ray_is_facing_left(double angle);
int		ray_is_facing_down(double angle);
long	calculate_magnitude(t_player *player, double x, double y);
void	draw_line(t_map_e *m, double angle, long h_distance);
long	find_horizontal_distance(t_map_e *m, t_ray **h, double angle);
long	find_vertical_distance(t_map_e *m, t_ray **v, double angle);
void	update_angle(double *angle);
long	find_min(long a, long b);
void	ft_lstadd_a_back(t_data **lst, t_data *new);
t_data	*ft_lstnew_ad(void *address);
void	draw_map(t_map_e *m, char **data, int flag);
int		mouvement_is_blocked(char **mapValues,
			int map_y, int map_x, double angle);
void	init_player_position(t_player *p, int i, int j, char direction);
void	draw_all_walls(t_map_e *m, t_wall *w);
void	render_wall(t_map_e *m, t_ray *ray, t_wall *w, int x);
void	free_all_exit(t_map_e *map, t_map *data);
void	close_function(void *param);
void	allocate_cal_struc(t_ray_calc	**cal);
#endif