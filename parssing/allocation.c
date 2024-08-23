/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:28 by haalouan          #+#    #+#             */
/*   Updated: 2024/08/23 15:26:14 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

char	**allocate_all_lines(int fd)
{
	char	**all_lines;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (get_next_line(fd))
		i++;
	all_lines = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	if (!all_lines)
		exit(EXIT_FAILURE);
	while (j <= i)
		all_lines[j++] = NULL;
	return (all_lines);
}

char	**allocate_str(char **str)
{
	int		i;
	int		j;
	char	**s;

	s = NULL;
	i = 0;
	j = 0;
	while (str && str[i])
		i++;
	s = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	if (!s)
		exit(EXIT_FAILURE);
	while (j <= i)
		s[j++] = NULL;
	return (s);
}

t_textures	*allocate_textures(void)
{
	t_textures	*textures;

	textures = NULL;
	textures = (t_textures *)malloc(sizeof(t_textures) + 1);
	if (!textures)
		exit(EXIT_FAILURE);
	textures->map = NULL;
	textures->c = NULL;
	textures->f = NULL;
	textures->no = NULL;
	textures->so = NULL;
	textures->ea = NULL;
	textures->we = NULL;
	return (textures);
}
