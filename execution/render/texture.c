/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:13:55 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/11 20:20:54 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_map_e *m, t_map *data)
{
	m->all_textures = malloc(sizeof(mlx_texture_t) * 4);
	if (!m->all_textures)
		exit (1);
	m->all_textures[0] = mlx_load_png(data->ea);
	m->all_textures[1] = mlx_load_png(data->we);
	m->all_textures[2] = mlx_load_png(data->no);
	m->all_textures[3] = mlx_load_png(data->so);
	if (!(m->all_textures[0]) || !(m->all_textures[1])
		|| !(m->all_textures[2]) || !(m->all_textures[3]))
		exit (1);
}

void	update_texture(t_wall *w, t_map_e *m)
{
	if (m->player->angle >= 90 && m->player->angle < 180)
		w->t->texture = m->all_textures[2];
	else if (m->player->angle >= 180 && m->player->angle < 270)
		w->t->texture = m->all_textures[1];
	else if (m->player->angle >= 270 && m->player->angle < 360)
		w->t->texture = m->all_textures[3];
	else if (m->player->angle >= 0 && m->player->angle < 90)
		w->t->texture = m->all_textures[0];
	w->t->arr = (uint32_t *)w->t->texture->pixels;
}
