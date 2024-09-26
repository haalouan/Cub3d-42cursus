/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:38:26 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/26 16:52:21 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

extern int mapValues[20][21];


void	draw_block(mlx_image_t *img, int x, int y, int value)
{
	uint32_t	color;
	int			i;
	int			j;

	if (value == 1)
		color = get_rgba(0, 0, 0, 200);
	else
		color = get_rgba(255, 255, 255, 255);
	i = 0;
	while (i < BLOCK_W - 1)
	{
		j = 0;
		while (j < BLOCK_L - 1)
		{
			mlx_put_pixel(img, (y + j) / 4, (x + i) / 4, color);
			j++;
		}
		i++;
	}
}

void	draw_map(mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			draw_block(img, (i + 1) * (BLOCK_L),
				(j + 1) * (BLOCK_W), mapValues[i][j]);
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_map_e *m)
{
	draw_map(m->interface->new_img);
	draw_player(m);
}
