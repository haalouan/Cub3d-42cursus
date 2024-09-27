/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:29:42 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/27 22:17:52 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player_instance(t_map_e *map3d)
{
	map3d->player = malloc(sizeof(t_player));
	if (!map3d->player)
		exit (1);
	map3d->player->x_p = 17 * BLOCK_W + 40;
	map3d->player->y_p = 4 * BLOCK_L + 40;
	map3d->player->angle = 180;
	map3d->player->rotation_speed = 2;
}

void	draw_circle(t_map_e *map, int x_center, int y_center, int radius)
{
	int	dx;
	int	dy;
	int	i;
	int	j;

	i = 0;
	while (i <= radius * 2)
	{
		dx = i - radius;
		j = 0;
		while (j <= radius * 2)
		{
			dy = j - radius;
			if (dx * dx + dy * dy <= radius * radius)
				my_put_mlx(map, (x_center + dx), (y_center + dy));
			j++;
		}
		i++;
	}
}

void	draw_player(t_map_e *map)
{
	int	x_center;
	int	y_center;
	int	radius;

	x_center = (map->player->x_p) + BLOCK_W;
	y_center = (map->player->y_p) + BLOCK_L;
	radius = 10;
	draw_circle(map, x_center, y_center, radius);
	apply_dda_algorithm(map);
	ft_malloc(0, 1);
}
