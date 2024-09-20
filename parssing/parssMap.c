/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:16:29 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 17:02:43 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

void	check_valid_for0(char **all_lines, t_map *textures, int i, int k)
{
	if (textures->map[i][k + 1] == '\0')
		manage_error(all_lines, textures);
	if (k < (int)ft_strlen(textures->map[i + 1]))
	{
		if (textures->map[i + 1][k] != '1' && textures->map[i + 1][k] != '0'
			&& textures->map[i + 1][k] != 'E' && textures->map[i + 1][k] != 'S'
			&& textures->map[i + 1][k] != 'W' && textures->map[i + 1][k] != 'N')
			manage_error(all_lines, textures);
	}
	else
		manage_error(all_lines, textures);
	if (k < (int)ft_strlen(textures->map[i - 1]))
	{
		if (textures->map[i - 1][k] != '1' && textures->map[i - 1][k] != '0'
			&& textures->map[i - 1][k] != 'E' && textures->map[i - 1][k] != 'S'
			&& textures->map[i - 1][k] != 'W' && textures->map[i - 1][k] != 'N')
			manage_error(all_lines, textures);
	}
	else
		manage_error(all_lines, textures);
}

void	check_end_line(char **all_lines, t_map *textures, int k)
{
	int	i;

	i = 0;
	while (textures->map[k] && textures->map[k][i])
		i++;
	if (textures->map[k][i - 1] == 'E' || textures->map[k][i - 1] == 'N'
		|| textures->map[k][i - 1] == 'W' || textures->map[k][i - 1] == 'S')
		manage_error(all_lines, textures);
}

void	check_valid_for_player(char **all_lines, t_map *textures, int i, int k)
{
	check_end_line(all_lines, textures, i);
	if (textures->map[i][k + 1] == ' ' || textures->map[i][k + 1] == '\t'
		|| textures->map[i][k - 1] == ' ' || textures->map[i][k - 1] == '\t')
		manage_error(all_lines, textures);
	if (k < (int)ft_strlen(textures->map[i + 1]))
	{
		if (textures->map[i + 1] && textures->map[i + 1][k] != '1'
			&& textures->map[i + 1][k] != '0')
			manage_error(all_lines, textures);
	}
	else
		manage_error(all_lines, textures);
	if (k < (int)ft_strlen(textures->map[i - 1]))
	{
		if (textures->map[i - 1] && textures->map[i - 1][k] != '1'
			&& textures->map[i - 1][k] != '0')
			manage_error(all_lines, textures);
	}
	else
		manage_error(all_lines, textures);
}

void	check_empty_line(char **all_lines, t_map *textures)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	check_dup(all_lines, textures);
	while (textures->map && textures->map[i])
	{
		k = 0;
		while (textures->map[i][k] && (textures->map[i][k] == ' '
			|| textures->map[i][k] == '\t'))
			k++;
		while (textures->map[i] && textures->map[i][k])
		{
			protecte_map(all_lines, textures, i, k);
			if (textures->map[i][k] == '0')
				check_valid_for0(all_lines, textures, i, k);
			if (textures->map[i][k] == 'E' || textures->map[i][k] == 'W'
				|| textures->map[i][k] == 'S' || textures->map[i][k] == 'N')
				check_valid_for_player(all_lines, textures, i, k);
			k++;
		}
		i++;
	}
}

void	parsse_map(char **all_lines, t_map *textures)
{
	int	i;

	i = 0;
	while (textures->map && textures->map[0] && textures->map[0][i])
	{
		if (textures->map[0][i] != '1')
		{
			free_all_lines(all_lines);
			free_map(textures);
			exit(printf("invalid map (open map)\n"));
		}
		i++;
	}
	check_empty_line(all_lines, textures);
}
