/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:12:02 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/13 19:46:24 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_all_exit(t_map_e *map, t_map *data)
{
	free_map(data);
	ft_malloc(0, 1);
	free(map);
	exit(1);
}

void	close_function(void *param)
{
	t_map_e	*m;

	m = (t_map_e *)param;
	terminate_game(m);
}
