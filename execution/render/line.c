/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:21:24 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/20 13:04:17 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_vector_values(t_line *line, t_map_e *m,
		long h_distance, double angle)
{
	line->x = cast_to_minimap(m->player->x_p, m->minimap->begin_y, m->minimap->end_y, 0);
	line->y = cast_to_minimap(m->player->y_p, m->minimap->begin_x, m->minimap->end_x, 1);
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
		// mlx_put_pixel(m->interface->new_img,
		// 	line->x / 4, line->y / 4, get_rgba(0, 0, 255, 255));
		mlx_put_pixel(m->interface->new_img,
			line->x, line->y, get_rgba(0, 0, 255, 255));
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
