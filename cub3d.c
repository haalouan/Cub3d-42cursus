/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:53:35 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/07 16:12:12 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_map *data)
{
	t_map_e	*map;

	map = (t_map_e *)malloc(sizeof(t_map));
	if (!map)
		exit (1);
	init_all_values(map, data);
	draw_mini_map(map, data->map, 0);
	if (mlx_image_to_window(map->interface->mlx_ptr,
			map->interface->new_img, 0, 0))
	{
		free(map->player);
		free(map->interface->mlx_ptr);
		free(map->interface->new_img);
		free(map->interface);
		free(map);
		exit (1);
	}
	mlx_loop_hook(map->interface->mlx_ptr, &key_func, map);
	mlx_loop(map->interface->mlx_ptr);
	mlx_terminate(map->interface->mlx_ptr);
}

int	main(int arc, char **arv)
{
	t_map	*text;

	text = parssing(arc, arv);
	start_game(text);
	free_map(text);
	return (0);
}
