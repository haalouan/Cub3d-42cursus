/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:09 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 17:03:47 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

char	**allocate_map(int i)
{
	char	**str;
	int		k;

	str = NULL;
	k = 0;
	str = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	if (!str)
		exit(EXIT_FAILURE);
	while (k <= i)
	{
		str[k] = NULL;
		k++;
	}
	return (str);
}

int	count_map(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	manage_error(char **str, t_map *textures)
{
	free_all_lines(str);
	free_map(textures);
	exit(printf("ERROR IN MAP\n"));
}

void	protecte_map(char **all_lines, t_map *textures, int i, int k)
{
	if (textures->map[i][k] != '0' && textures->map[i][k] != '1'
		&& textures->map[i][k] != 'E' && textures->map[i][k] != 'N'
		&& textures->map[i][k] != 'S' && textures->map[i][k] != 'W'
		&& textures->map[i][k] != ' ' && textures->map[i][k] != '\t')
		manage_error(all_lines, textures);
}

void	check_dup(char **all_lines, t_map *textures)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	flag = 0;
	while (textures->map && textures->map[i])
	{
		k = 0;
		while (textures->map[i] && textures->map[i][k])
		{
			if (textures->map[i][k] == 'E' || textures->map[i][k] == 'N'
				|| textures->map[i][k] == 'S' || textures->map[i][k] == 'W')
				flag++;
			k++;
		}
		i++;
	}
	if (flag != 1)
		manage_error(all_lines, textures);
}
