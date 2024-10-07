/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:52 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/07 16:14:01 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


static void	calculate_dimensions(t_map_e *m, t_map *data)
{
	int	i;
	int	height;
	int	width;
	int	tmp;

	i = 0;
	height = 0;
	width = 0;
	while (data->map[i++])
		height++;
	i = 0;
	while (data->map[i])
	{
		tmp = ft_strlen(data->map[i]);
		if (tmp > width)
			width = tmp;
		i++;
	}
	m->width = width;
	m->height = height;
}

static void	init_interface(t_map_e *m)
{
	m->interface = malloc(sizeof(t_map));
	if (!m->interface)
	{
		free(m);
		free(m->player);
		exit (1);
	}
	m->interface->mlx_ptr = mlx_init(m->width * BLOCK_W,
			m->height * BLOCK_L, "overall_map", false);
	if (!m->interface->mlx_ptr)
	{
		free(m->player);
		free(m->interface);
		free(m);
		exit (1);
	}
	m->interface->new_img = mlx_new_image(m->interface->mlx_ptr,
			m->width * BLOCK_W, m->height * BLOCK_L);
	if (!m->interface->new_img)
	{
		free(m->player);
		free(m->interface->mlx_ptr);
		free(m->interface);
		free(m);
		exit (1);
	}

}

void	init_all_values(t_map_e *m, t_map *data)
{
	init_textures(m, data);
	init_player_instance(m);
	calculate_dimensions(m, data);
	m->m_values = data->map;
	init_interface(m);
}
