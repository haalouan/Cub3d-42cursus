/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:38:26 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/20 22:20:17 by shamdoun         ###   ########.fr       */
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

// uint32_t cast_to_minimap(t_map_e *m, int v, int flag)
// {
// 	(void)m;
// 	if (flag)
// 		return (v  * M_M_W) / 10;
// 	return ((v * M_M_H) / 10);
// }
uint32_t cast_to_minimap(int old_v, int o_l, int o_m, int flag)
{
	// (void)m;
	if (flag)
		return ((BLOCK_L / 4) + ((old_v - o_l)  * ((M_M_W) * (BLOCK_L + 1) - (BLOCK_L / 4)) / (o_m - o_l)));
	return ((BLOCK_W / 4) + ((old_v - o_l) * ((M_M_H) * (BLOCK_W + 1) - (BLOCK_W / 4)) / (o_m - o_l)));
}

double cast_to_window(double old_v, int o_l, int o_m, int flag)
{
	// (void)m;
	if (flag)
		return (((old_v - o_l)  * (W_HEIGHT * BLOCK_L) / (o_m - o_l)));
	return (((old_v - o_l) * (W_WIDTH * BLOCK_W)) / (o_m - o_l));
}

void	draw_block(t_map_e *m, int x, int y, char value, t_minimap *mini)
{
	uint32_t	color;
	int			i;
	int			j;
	int			map_i;
	int			map_j;
	int			scale_x;
	int			scale_y;
	
(void)mini;
	scale_x = M_M_W / m->width;
	scale_y = M_M_H / m->height;

	// printf("drawing block x %d y %d\n", y / 64, x / 64);
	// printf("drawing x %d y %d\n", x, y);
	if (value == '1')
		color = get_rgba(32, 30, 31, 150);
	else if (value == 9 || value == 32 || value == '5')
		color = get_rgba(153, 70, 54, 50);
	else
		color = get_rgba(199, 188, 194, 255);
	i = 0;
	// printf("drawing block %d %d\n", x, y);
	while (i < (BLOCK_W) - 1)
	{
		j = 0;
		while (j < (BLOCK_L) - 1)
		{
			map_i = cast_to_minimap(x , mini->begin_x, mini->end_x, 1) + i;
			map_j = cast_to_minimap(y , mini->begin_y,  mini->end_y, 0) + j;
			// map_i = x + i;
			// map_j = y + j;
			mlx_put_pixel(m->interface->new_img, map_j , map_i, color);
			j++;
		}
		i++;
	}
}

// void draw_map_v1(t_map_e *m, char **data, int flag)
// {
// 	int begin_x;
// 	int begin_y;
// 	int end_x;
// 	int end_y;
// 	int i;
// 	int j;
// 	// int k;
// 	(void)flag;
// 	(void)data;


// 	begin_y = m->player->y_p - (M_M_H / 2 * BLOCK_L);
// 	if (begin_y < 0)
// 		begin_y = 0;
// 	end_y = begin_y + (M_M_H * BLOCK_L);
// 	begin_x = m->player->x_p - (M_M_W / 2 * BLOCK_W);
// 	if (begin_x < 0)
// 		begin_x = 0;
// 	end_x = begin_x + (M_M_W * BLOCK_W);
// 	if (end_y > m->height * BLOCK_L) {
//         end_y %= M_M_H * BLOCK_L;
//     }
//     if (end_x > m->width * BLOCK_W) {
//         end_x %= M_M_W * BLOCK_W;
//     }
// 	i = begin_y;
// 	while ((i + begin_y) < end_y)
// 	{
// 		j = begin_x;
// 		while ((j) < end_x)
// 		{
// 			// k = ft_strlen(data[i / 64]);
// 			// if (j < k * 64)
//             // 	draw_block(m, i, j, data[i / 64][j / 64]);
// 			// else
//             	draw_block(m, i, j, '5');
//             // }
// 			j += BLOCK_W;
// 		}
// 		i += BLOCK_L;
// 	}
// }


void transition_map_mouvement(t_vector *position, int *begin, int *l)
{
	if (!position)
	{
		position = ft_malloc(sizeof(t_vector), 0);
		position->inter_factor = 0.0003220f;
		position->deltaTime = 0.010f;
		position->x = *l;
		position->y = *begin;
	}
	else
	{
		*begin = position->y + (*begin - position->y) * position->inter_factor * position->deltaTime;	
		*begin = position->x + (*l - position->x) * position->inter_factor * position->deltaTime;
	}
}

void	draw_map(t_map_e *m, char **data, int flag, t_minimap *mini)
{
	int	i;
	int	begin;
	int	begin_j;
	int	j;
	int	k;
	int	d;
	int	l;
	static t_vector *position1;
	static t_vector *position2;
	

	begin = ((int)floor(m->player->y_p / BLOCK_L) - (M_M_H / 2));
	if (begin < 0)
		begin = 0;
	d = begin + (M_M_H);
	if (d > m->height)
		d = m->height;
	(void)flag;
	i = 0;
	while ((begin + i) < d)
	{
			begin_j = ((int)floor(m->player->x_p / BLOCK_L) - (M_M_W / 2));
			if (begin_j < 0)
				begin_j = 0;
			k = ft_strlen(data[i + begin]);
			l = begin_j + (M_M_W);
			if (l > m->width)
				l = m->width;
			transition_map_mouvement(position1, &begin, &l);
			transition_map_mouvement(position2, &begin_j, &d);
			j = 0;
			while ((begin_j + j) < l)
			{
					mini->begin_x = begin * BLOCK_L;
					mini->begin_y = begin_j * BLOCK_W;
					mini->end_y = l * BLOCK_L;
					mini->end_x = d * BLOCK_L;	
				if ((j + begin_j) < k && data[i + begin][j + begin_j] != ' ' && data[i + begin][j + begin_j] != 9)
					draw_block(m, (begin + i) * (BLOCK_L), (begin_j + j) * (BLOCK_W), data[i + begin][begin_j + j], mini);
				else
					draw_block(m, (begin + i) * (BLOCK_L), (begin_j + j) * (BLOCK_W), '5', mini);
				j++;
			}
		i++;
	}
}

void	draw_rectangle(t_map_e *m)
{
	int	i;
	int	w;
	int h;
	int	j;
	
	// i = (BLOCK_L / 2) - BORDER_WIDTH;
	i = 0;
	h = M_M_W * (BLOCK_W) + BLOCK_W / 3;
	w = M_M_H * (BLOCK_L) + BLOCK_L / 3;
	
	while (i < h)
	{
		// j = BLOCK_W / 2 - BORDER_WIDTH;
		j = 0;
		while (j < w)
		{
			// if (j < BLOCK_W)
				mlx_put_pixel(m->interface->new_img, j, i, get_rgba(255, 241, 219, 20));
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_map_e *m, char **data, int flag)
{
	// (void)data;
	// (void)flag;
	static t_minimap *mini;
	if (!mini)
		mini = ft_malloc(sizeof(t_minimap), 0);
	draw_rectangle(m);
	draw_map(m, data, flag, mini);
	draw_player(m, mini);
}
