/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:32:54 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/07 15:57:47 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_map_value(char **mapValues, t_player *p, int x, int y)
{
	char	v;

	v = mapValues[(int)floor((p->y_p + y)
			/ BLOCK_L)][(int)floor((p->x_p + x) / BLOCK_L)];
	if (v == '1')
		return (1);
	return (0);
}

int	wall_contact(t_player *p, char **mapValues)
{
	if (get_map_value(mapValues, p, 0, -20)
		|| get_map_value(mapValues, p, 20, 0)
		|| get_map_value(mapValues, p, -20, 0)
		|| get_map_value(mapValues, p, 0, 20)
		|| get_map_value(mapValues, p, -20, 20)
		|| get_map_value(mapValues, p, -20, -20)
		|| get_map_value(mapValues, p, 20, -20)
		|| get_map_value(mapValues, p, 20, 20))
		return (1);
	return (0);
}

void	draw_3d_map(void)
{
	t_map_e	*map3d;

	map3d = (t_map_e *)malloc(sizeof(t_map));
	if (!map3d)
		exit (1);
	draw_3d_walls(map3d);
	draw_mini_map(map3d, map3d->m_values, 1);
	if (mlx_image_to_window(map3d->interface->mlx_ptr,
			map3d->interface->new_img, 0, 0))
	{
		free(map3d->player);
		free(map3d->interface->mlx_ptr);
		free(map3d->interface->new_img);
		free(map3d->interface);
		free(map3d);
		exit (1);
	}
	mlx_loop_hook(map3d->interface->mlx_ptr, &key_func, map3d);
	mlx_loop(map3d->interface->mlx_ptr);
	mlx_terminate(map3d->interface->mlx_ptr);
	free(map3d->interface);
	free(map3d->player);
	free(map3d);
	ft_malloc(0, 1);
}
