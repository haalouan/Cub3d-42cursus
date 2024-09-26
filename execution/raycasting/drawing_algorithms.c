/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:18:30 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/26 16:58:36 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	update_angle(double *angle)
{
	if ((*angle) < 0)
		(*angle) += 360;
	if ((*angle) >= 360)
		(*angle) -= 360;
}

void	choose_closest_distance(t_ray **rays, t_ray *v_ray, t_ray *h_ray)
{
	if (h_ray->distance > v_ray->distance)
	{
		v_ray->hit_vertical = 1;
		ft_lstadd_back(rays, v_ray);
	}
	else
	{
		h_ray->hit_vertical = 0;
		ft_lstadd_back(rays, h_ray);
	}
}

void	measure_all_rays(t_map_e *m, t_ray **rays)
{
	t_ray	*h_ray;
	t_ray	*v_ray;
	double	a_begin;
	double	a_end;
	double	steps;

	a_begin = m->player->angle + 30;
	a_end = m->player->angle - 30;
	steps = 60.0 / (WIDTH * BLOCK_W);
	while (a_begin > a_end)
	{
		h_ray = ft_lstnew(a_begin);
		if (!h_ray)
			exit(1);
		v_ray = ft_lstnew(a_begin);
		if (!v_ray)
			exit(1);
		h_ray->distance = find_horizontal_distance(m, &h_ray, a_begin);
		v_ray->distance = find_vertical_distance(m, &v_ray, a_begin);
		choose_closest_distance(rays, v_ray, h_ray);
		a_begin -= steps;
	}
}
