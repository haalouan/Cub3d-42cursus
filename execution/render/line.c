/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:21:24 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/26 14:14:55 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_gradient(t_gradient *gradient)
{
	gradient->start_r = 135;
	gradient->start_g = 206;
	gradient->start_b = 235;
	gradient->end_r = 0;
	gradient->end_g = 0;
	gradient->end_b = 139;
}

void	init_vector_values(t_line *line, t_map_e *m,
		long h_distance, double angle)
{
	line->x = m->player->x_p + BLOCK_W;
	line->y = m->player->y_p + BLOCK_L;
	line->line_length = h_distance;
	line->x1 = line->x + cos(-angle * (M_PI / 180)) * line->line_length;
	line->y1 = line->y + sin(-angle * (M_PI / 180)) * line->line_length;
	line->dx = absolute_value(line->x1 - line->x);
	line->dy = absolute_value(line->y1 - line->y);
	if (line->x < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

void	draw_line(t_map_e *m, double angle, long h_distance)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		exit(1);
	init_vector_values(line, m, h_distance, angle);
	while (1)
	{
		mlx_put_pixel(m->interface->new_img,
			line->x / 4, line->y / 4, get_rgba(0, 0, 255, 255));
		if (line->x == line->x1 && line->y == line->y1)
			break ;
		line->e2 = line->err * 2;
		if (line->e2 > -(line->dy))
		{
			line->err -= line->dy;
			line->x += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			line->y += line->sy;
		}
	}
	free(line);
}
