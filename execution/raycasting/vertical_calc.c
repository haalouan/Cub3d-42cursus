/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:27:55 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/16 16:01:19 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	initialise_params_for_vert_calc(t_ray_calc *vertical, double angle)
{
	vertical->tan_angle = tan(angle * (M_PI / 180));
	vertical->verif_x = angle > 90 && angle < 270;
	vertical->verif_y = angle > 180 && angle < 360;
	if (vertical->verif_x)
		vertical->ax = BLOCK_W * -1;
	else
		vertical->ax = BLOCK_W * 1;
	vertical->ay = BLOCK_W * tan(angle * (M_PI / 180));
	vertical->angle = angle;
	if (!vertical->verif_y
		&& vertical->ay > 0)
		vertical->ay *= -1;
	if (vertical->verif_y
		&& vertical->ay < 0)
		vertical->ay *= -1;
}

static void	init_first_vertical_inter(t_ray_calc *vertical, t_map_e *m,
	double *x_inter, double *y_inter)
{
	if (!vertical->verif_x)
		(*x_inter) = floor(m->player->x_p / BLOCK_L) * BLOCK_L + BLOCK_L;
	else
		(*x_inter) = floor(m->player->x_p / BLOCK_L) * BLOCK_L - 0.0001;
	(*y_inter) = m->player->y_p
		+ ((m->player->x_p - (*x_inter)) * tan(vertical->angle * (M_PI / 180)));
}

long	find_vertical_distance(t_map_e *m, t_ray **v, double angle)
{
	double				x_inter;
	double				y_inter;	
	static t_ray_calc	*vertical;
	int					map_x;
	int					map_y;

	update_angle(&angle);
	if (!vertical)
		allocate_cal_struc(&vertical);
	initialise_params_for_vert_calc(vertical, angle);
	init_first_vertical_inter(vertical, m, &x_inter, &y_inter);
	while (x_inter >= 0 && y_inter >= 0
		&& x_inter <= (BLOCK_W * m->width) && y_inter <= (BLOCK_L * m->height))
	{
		map_x = (int)floor(fabs(x_inter) / BLOCK_W);
		map_y = (int)floor(fabs(y_inter) / BLOCK_L);
		if (map_x < m->width && map_y < m->height
			&& mouvement_is_blocked(m->m_values, map_y, map_x, angle))
			break ;
		x_inter = x_inter + vertical->ax;
		y_inter = y_inter + vertical->ay;
	}
	if (v)
		(*v)->bitmap_offset = y_inter;
	return (calculate_magnitude(m->player, x_inter, y_inter));
}
