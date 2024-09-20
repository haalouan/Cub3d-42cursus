/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:15:31 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 16:55:00 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

void	free_all_lines(char **all_lines)
{
	int	i;

	i = 0;
	while (all_lines && all_lines[i])
	{
		if (all_lines[i])
			free(all_lines[i]);
		i++;
	}
	if (all_lines)
		free(all_lines);
}

void	free_map(t_map *Map)
{
	int	i;

	i = 0;
	if (Map->c)
		free(Map->c);
	if (Map->f)
		free(Map->f);
	if (Map->no)
		free(Map->no);
	if (Map->so)
		free(Map->so);
	if (Map->we)
		free(Map->we);
	if (Map->ea)
		free(Map->ea);
	if (Map->map)
		free_all_lines(Map->map);
	if (Map)
		free(Map);
}
