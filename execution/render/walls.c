/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:57:12 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/08 15:07:59 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_wall_values(t_map_e *m, t_wall *w)
{
	w->t = ft_malloc(sizeof(t_bitmap), 0);
	w->distance_to_projection = (m->width * BLOCK_W / 2)
		/ tan(FOV / 2 * (M_PI / 180));
}

void	update_wall_values(t_wall *w, t_ray *rays, t_map_e *m)
{
	update_texture(w, m);
	w->distance = rays->distance;
	w->distance = cos((m->player->angle - rays->angle)
			* (M_PI / 180)) * w->distance;
	w->wall_height = (w->distance_to_projection * BLOCK_L) / w->distance;
	w->wall_top = ((BLOCK_L * m->height) / 2)
		- ((w->wall_height / 2));
	if (w->wall_top < 0 || (w->wall_top > m->height * BLOCK_L))
		w->wall_top = 0;
	w->wall_bot = ((BLOCK_L * m->height) / 2) + ((w->wall_height / 2));
	//!TODO: fix wall_bot value!
	if (absolute_value(w->wall_bot) > m->height * BLOCK_L)
		w->wall_bot = m->height * BLOCK_L;
	w->t->offset_x = (int)((rays->bitmap_offset)
			* (w->t->texture->width / BLOCK_W)) % (w->t->texture->width);
	if (w->t->offset_x < 0)
		w->t->offset_x = 0;
	w->t->scaling_factor = ((double)w->t->texture->height / w->wall_height);
	w->angle = rays->angle;
}

void	draw_wall(t_wall *w, t_map_e *m, int x, int vertical)
{
	int	y;
	int	b;
	(void)vertical;
	y = w->wall_top;
	b = w->wall_bot;
	w->t->offset_y = ((w->wall_top - (m->height * BLOCK_L / 2)
				+ (w->wall_height / 2)) * w->t->scaling_factor);
	if (w->t->offset_y < 0)
		w->t->offset_y = 0;
	while (y < b)
	{
		w->t->color = w->t->arr[((int)w->t->offset_y
				* w->t->texture->width) + (int)w->t->offset_x];
		w->t->color = convert_pixel_to_color(w->t->color);
		// if (vertical)
		// 	w->t->color = (w->t->color >> 1) & 8355711;
		mlx_put_pixel(m->interface->new_img,
			x, y, w->t->color);
		w->t->offset_y += w->t->scaling_factor;
		y++;
	}
}

void	render_all_walls(t_map_e *m, t_ray *rays, t_wall *w)
{
	int		x;

	x = 0;
	while (rays)
	{
		update_wall_values(w, rays, m);
		draw_sky(m, x, w);
		draw_wall(w, m, x, rays->hit_vertical);
		draw_floor(w, m, x);
		rays = rays->next;
		x += 1;
	}
}

void	draw_3d_walls(t_map_e *m)
{
	static t_wall	*w;
	t_ray			*rays;

	rays = ft_malloc(sizeof(t_ray), 0);
	if (!rays)
		exit (1);
	rays = NULL;
	measure_all_rays(m, &rays);
	w = ft_malloc(sizeof(t_wall), 0);
	if (!w)
		exit(1);
	init_wall_values(m, w);
	render_all_walls(m, rays, w);
	ft_malloc(0, 1);
}
