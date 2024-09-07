/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:09 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/05 15:05:08 by haalouan         ###   ########.fr       */
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
void	print_textures(t_map *textures)
{
	printf("%s\n",textures->c);
	printf("%s\n",textures->f);
	printf("%s\n",textures->no);
	printf("%s\n",textures->so);
	printf("%s\n",textures->ea);
	printf("%s\n",textures->we);
	int g = 0;
	while (textures->map[g])
	{
		printf("%s\n", textures->map[g]);
		g++;
	}
}
