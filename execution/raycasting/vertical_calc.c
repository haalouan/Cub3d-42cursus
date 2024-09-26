/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:27:55 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/26 16:32:33 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initialise_params_for_vert_calc(t_ray_calc *vertical, double angle)
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
	else
		vertical->ay *= 1;
	if (vertical->verif_y
		&& vertical->ay < 0)
		vertical->ay *= -1;
	else
		vertical->ay *= 1;
}

void	init_first_vertical_inter(t_ray_calc *vertical, t_map_e *m,
	double *x_inter, double *y_inter)
{
	if (!vertical->verif_x)
		(*x_inter) = floor(m->player->x_p / BLOCK_L) * BLOCK_L + BLOCK_L;
	else
		(*x_inter) = floor(m->player->x_p / BLOCK_L) * BLOCK_L - 1;
	(*y_inter) = m->player->y_p
		+ ((m->player->x_p - (*x_inter)) * tan(vertical->angle * (M_PI / 180)));
}

long	find_vertical_distance(t_map_e *m, t_ray **v, double angle)
{
	double		x_inter;
	double		y_inter;	
	t_ray_calc	*vertical;
	int			map_x;
	int			map_y;

	update_angle(&angle);
	vertical = ft_malloc(sizeof(t_ray_calc), 0);
	initialise_params_for_vert_calc(vertical, angle);
	init_first_vertical_inter(vertical, m, &x_inter, &y_inter);
	while ((fabs(x_inter) <= BLOCK_W * 21) && (fabs(y_inter) <= (BLOCK_L * 10)))
	{
		map_x = (int)floor(fabs(x_inter) / BLOCK_W);
		map_y = (int)floor(fabs(y_inter) / BLOCK_L);
		if (map_x < 21 && map_y < 10
			&& mouvement_is_blocked(map_y, map_x, angle))
			break ;
		x_inter = x_inter + vertical->ax;
		y_inter = y_inter + vertical->ay;
	}
	if (v)
		(*v)->bitmap_offset = y_inter;
	return (calculate_magnitude(m->player, x_inter, y_inter));
}
