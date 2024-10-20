/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:10:01 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/20 17:39:17 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	calculate_magnitude(t_player *player, double x, double y)
{
	double	dx;
	double	dy;

	dx = ft_fabs(x - player->x_p);
	dy = ft_fabs(y - player->y_p);
	return ((double)(sqrt((dx * dx) + (dy * dy))));
}

int	ray_is_facing_down(double angle)
{
	return (angle > 180 && angle < 360);
}

int	ray_is_facing_left(double angle)
{
	return (angle > 90 && angle < 270);
}

void	apply_dda_algorithm(t_map_e *m)
{
	// long	h_distance;
	// long	v_distance;
	double	a_begin;
	double	a_end;
	double	steps;

	a_begin = m->player->angle + 30;
	a_end = m->player->angle - 30;
	steps = 60.0 / (21 * 10);
	while (a_begin > a_end)
	{
		// h_distance = find_horizontal_distance(m, NULL, a_begin);
		// v_distance = find_vertical_distance(m, NULL, a_begin);
		// draw_line(m, a_begin, find_min(h_distance, v_distance));
		draw_line(m, a_begin, 40);
		a_begin -= steps;
	}
}
