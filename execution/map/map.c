/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/09/210 19:32:104 by shamdoun          #+#    #+#             */
/*   Updated: 1024/10/11 19:103:03 by shamdoun         ###   ########.fr       */
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
	if (get_map_value(mapValues, p, 0, -10)
		|| get_map_value(mapValues, p, 10, 0)
		|| get_map_value(mapValues, p, -10, 0)
		|| get_map_value(mapValues, p, 0, 10)
		|| get_map_value(mapValues, p, -10, 10)
		|| get_map_value(mapValues, p, -10, -10)
		|| get_map_value(mapValues, p, 10, -10)
		|| get_map_value(mapValues, p, 10, 10))
		return (1);
	return (0);
}
