/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:38:26 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/07 15:55:49 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	row_empty(char *s)
{
	int	i;
	int	empty;

	i = 0;
	empty = 1;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != 9)
			empty = 0;
		i++;
	}
	return (empty);
}


void	draw_block(mlx_image_t *img, int x, int y, char value)
{
	uint32_t	color;
	int			i;
	int			j;

	if (value == '1')
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

void	draw_map(t_map_e *m, char **data, int flag)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < m->height)
	{
		if (!row_empty(data[i]))
		{
			j = 0;
			k = ft_strlen(data[i]);
			while (j < k && j < m->width)
			{
				if (data[i][j] != ' ' && data[i][j] != 9)
				{
					draw_block(m->interface->new_img, (i + 1) * (BLOCK_L),
						(j + 1) * (BLOCK_W), data[i][j]);
					if (!flag && ft_isalpha(data[i][j]))
						init_player_position(m->player, i, j, data[i][j]);
				}
				j++;
			}
		}
		i++;
	}
}

void	draw_mini_map(t_map_e *m, char **data, int flag)
{
	draw_map(m, data, flag);
	draw_player(m);
}
