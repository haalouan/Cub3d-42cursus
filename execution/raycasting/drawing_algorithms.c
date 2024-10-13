/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:18:30 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/13 18:42:32 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	update_angle(double *angle)
{
	if ((*angle) < 0)
		(*angle) += 360;
	if ((*angle) > 360)
		(*angle) -= 360;
}

static t_ray	*shortest_distance(t_ray *v_ray, t_ray *h_ray)
{
	if (h_ray->distance > v_ray->distance)
	{
		v_ray->hit_vertical = 1;
		return (v_ray);
	}
	h_ray->hit_vertical = 0;
	return (h_ray);
}

static t_ray	*find_distance(t_map_e *m, double a_begin)
{
	static t_ray	*h_ray;
	static t_ray	*v_ray;

	if (!h_ray && !v_ray)
	{
		h_ray = ft_lstnew(a_begin);
		if (!h_ray)
			exit(1);
		v_ray = ft_lstnew(a_begin);
		if (!v_ray)
			exit(1);
	}
	else
	{
		h_ray->angle = a_begin;
		v_ray->angle = a_begin;
	}
	h_ray->angle = a_begin;
	v_ray->angle = a_begin;
	h_ray->distance = find_horizontal_distance(m, &h_ray, a_begin);
	v_ray->distance = find_vertical_distance(m, &v_ray, a_begin);
	return (shortest_distance(v_ray, h_ray));
}

void	draw_all_walls(t_map_e *m, t_wall *w)
{
	t_ray			*r;
	double			a_begin;
	double			a_end;
	int				x;
	double			steps;

	x = 0;
	a_begin = m->player->angle + 30;
	a_end = m->player->angle - 30;
	steps = (double)FOV / (m->width * BLOCK_W);
	while (a_begin > a_end)
	{
		r = find_distance(m, a_begin);
		render_wall(m, r, w, x);
		a_begin -= steps;
		x++;
	}
}
