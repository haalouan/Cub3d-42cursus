/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:23:50 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/26 22:26:42 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initialise_params_for_hor_calc(t_ray_calc *hor, double angle)
{
	hor->tan_angle = tan(angle * (M_PI / 180));
	hor->verif_y = angle > 180 && angle < 360;
	hor->verif_x = angle > 90 && angle < 270;
	if (hor->verif_y)
		hor->ay = BLOCK_L * 1;
	else
		hor->ay = BLOCK_L * -1;
	hor->ax = BLOCK_L / hor->tan_angle;
	if (hor->verif_x && hor->ax > 0)
		hor->ax *= -1;
	else
		hor->ax *= 1;
	if (!hor->verif_x && hor->ax < 0)
		hor->ax *= -1;
	else
		hor->ax *= 1;
}

void	init_first_hor_inter(t_ray_calc *hor, t_map_e *m,
	double *x_inter, double *y_inter)
{
	if (hor->verif_y)
		(*y_inter) = floor(m->player->y_p / BLOCK_L) * BLOCK_L + BLOCK_L;
	else
		(*y_inter) = floor(m->player->y_p / BLOCK_L) * BLOCK_L - 1;
	(*x_inter) = m->player->x_p
		+ (m->player->y_p - (*y_inter)) / hor->tan_angle;
}

long	special_case_hor(t_map_e *m, t_ray **h, double angle, t_ray_calc *horiz)
{
	double x_inter;
	double y_inter;
	int			map_x;
	int			map_y;
	
	// horiz = ft_malloc(sizeof(t_ray_calc), 0);
	printf("returning special case\n");
	horiz->ax = BLOCK_W / 10;
	if (horiz->verif_y)
		(y_inter) = floor(m->player->y_p / BLOCK_L) * BLOCK_L + BLOCK_L;
	else
		(y_inter) = floor(m->player->y_p / BLOCK_L) * BLOCK_L - 1;
	(x_inter) = m->player->x_p + horiz->ax;
	while (x_inter >= 0 && y_inter >= 0
		&& x_inter <= (BLOCK_W * 21) && y_inter <= (BLOCK_L * 10))
	{
		map_x = (int)floor((fabs(x_inter)) / BLOCK_W);
		map_y = (int)floor(fabs(y_inter) / BLOCK_L);
		if (map_x < 21 && map_y < 10
			&& mouvement_is_blocked(map_y, map_x, angle))
			break ;
		x_inter = x_inter + horiz->ax;
		y_inter = y_inter + horiz->ay;
	}
	if (h)
		(*h)->bitmap_offset = x_inter;
	return (calculate_magnitude(m->player, x_inter, y_inter));
}

long	find_horizontal_distance(t_map_e *m, t_ray **h, double angle)
{
	double		x_inter;
	double		y_inter;
	t_ray_calc	*horiz;
	int			map_x;
	int			map_y;

	horiz = ft_malloc(sizeof(t_ray_calc), 0);
	update_angle(&angle);
	initialise_params_for_hor_calc(horiz, angle);
	init_first_hor_inter(horiz, m, &x_inter, &y_inter);
	while (x_inter >= 0 && y_inter >= 0
		&& x_inter <= (BLOCK_W * 21) && y_inter <= (BLOCK_L * 10))
	{
		map_x = (int)floor((fabs(x_inter)) / BLOCK_W);
		map_y = (int)floor(fabs(y_inter) / BLOCK_L);
		if (map_x < 21 && map_y < 10
			&& mouvement_is_blocked(map_y, map_x, angle))
			break ;
		x_inter = x_inter + horiz->ax;
		y_inter = y_inter + horiz->ay;
	}
	if (h)
		(*h)->bitmap_offset = x_inter;
	return (calculate_magnitude(m->player, x_inter, y_inter));
}
