/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:56:03 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/08 18:34:10 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	mouvement_is_blocked(char **mapValues, int map_y, int map_x, double angle)
{
	int	len;
	int	h;

	h = 0;
	while (mapValues[h])
		h++;
	len = ft_strlen(mapValues[map_y]);
	if (map_x >= len - 1)
		return (1);
	if ((mapValues[map_y][map_x] == '1') || (!ray_is_facing_down(angle)
			&& ray_is_facing_left(angle) && (mapValues[map_y][map_x + 1] == '1')
					&& (((map_y + 1) < h)
					&& (map_x < ((int)ft_strlen(mapValues[map_y + 1]))))
					&& (mapValues[map_y + 1][map_x] == '1')) ||
		(!ray_is_facing_down(angle) && !ray_is_facing_left(angle)
				&& (mapValues[map_y][map_x - 1] == '1')
				&& ((map_y + 1) < h
				&& (map_x < (int)ft_strlen(mapValues[map_y + 1])))
				&& (mapValues[map_y + 1][map_x] == '1')) ||
		(ray_is_facing_down(angle) && ray_is_facing_left(angle)
				&& (mapValues[map_y][map_x + 1] == '1')
				&& (mapValues[map_y - 1][map_x] == '1')))
		return (1);
	return (0);
}

void	move_up(t_player *p, char **mapValues)
{
	double	old_x;
	double	old_y;

	old_x = p->x_p;
	old_y = p->y_p;
	p->x_p = p->x_p + cos(-p->angle * (M_PI / 180)) * 25;
	p->y_p = p->y_p + sin(-p->angle * (M_PI / 180)) * 25;
	if (wall_contact(p, mapValues))
	{
		p->x_p = old_x;
		p->y_p = old_y;
	}
}

void	move_down(t_player *p, char **mapValues)
{
	double	old_x;
	double	old_y;

	old_x = p->x_p;
	old_y = p->y_p;
	p->x_p = p->x_p + cos(-p->angle * (M_PI / 180)) * -25;
	p->y_p = p->y_p + sin(-p->angle * (M_PI / 180)) * -25;
	if (wall_contact(p, mapValues))
	{
		p->x_p = old_x;
		p->y_p = old_y;
	}
}

void	move_right(t_player *p, char **mapValues)
{
	double	old_x;
	double	old_y;

	old_x = p->x_p;
	old_y = p->y_p;
	p->x_p = p->x_p + cos(-p->angle * (M_PI / 180) + (M_PI / 2)) * 25;
	p->y_p = p->y_p + sin(-p->angle * (M_PI / 180) + (M_PI / 2)) * 25;
	if (wall_contact(p, mapValues))
	{
		p->x_p = old_x;
		p->y_p = old_y;
	}
}

void	move_left(t_player *p, char **mapValues)
{
	double	old_x;
	double	old_y;

	old_x = p->x_p;
	old_y = p->y_p;
	p->x_p = p->x_p + cos(-p->angle * (M_PI / 180) - (M_PI / 2)) * 25;
	p->y_p = p->y_p + sin(-p->angle * (M_PI / 180) - (M_PI / 2)) * 25;
	if (wall_contact(p, mapValues))
	{
		p->x_p = old_x;
		p->y_p = old_y;
	}
}
