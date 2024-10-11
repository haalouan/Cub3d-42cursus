/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:32:54 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/11 19:53:03 by shamdoun         ###   ########.fr       */
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
