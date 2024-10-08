/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:52 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/08 19:32:13 by shamdoun         ###   ########.fr       */
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

uint32_t	extract_color(char *c)
{
	char		**split;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	split = ft_split(c, ',');
	if (!split)
	{
		ft_malloc(0, 1);
		exit(1);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	return ((uint32_t)get_rgba(r, g, b, 100));
}

void	init_colors(t_map_e *m, char *f, char *c)
{
	m->floor = extract_color(f);
	m->ceiling = extract_color(c);
}

void	init_all_values(t_map_e *m, t_map *data)
{
	init_textures(m, data);
	init_player_instance(m);
	calculate_dimensions(m, data);
	init_colors(m, data->f, data->c);
	m->m_values = data->map;
	init_interface(m);
}
