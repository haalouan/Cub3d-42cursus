/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:56:23 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/05 13:39:45 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*parssing(int arc, char **arv)
{
	ssize_t fd;
	int i;
	char **all_lines;
	char *line;
	t_map *textures;

	(void)arc;
	i = 0;
	if (parsse_args(arv[1]) == 0)
		exit(printf("Error in ARGS\n"));
	fd = open(arv[1], O_RDONLY);
	if (fd < 0)
		exit(printf("READ FAILED\n"));
	all_lines = allocate_all_lines(fd);
	fd = open(arv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		all_lines[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	textures = allocate_textures();
	all_lines = parsse_all_lines(all_lines);
	parsse_textures(all_lines, textures);
	parsse_map(textures->map);
	// print_textures(textures);
	return (textures);
}

char	**parsse_all_lines(char **str)
{
	char **s;
	int i;

	s = allocate_str(str);
	i = 0;
	while (str && str[i])
	{
		s[i] = ft_strdup(str[i]);
		i++;
	}
	check_map(str);
	return (s);
}

void	check_map(char **str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str && str[i])
	{
		k = 0;
		while (str && str[i] && (str[i][k] == ' ' || str[i][k] == '\t'))
			k++;
		if (ft_strncmp(str[i] + k, "NO", 2) != 0 && ft_strncmp(str[i] + k, "SO", 2) != 0
			&& ft_strncmp(str[i] + k, "EA", 2) != 0 && ft_strncmp(str[i] + k, "WE", 2) != 0
			&& ft_strncmp(str[i] + k, "C", 1) != 0 && ft_strncmp(str[i] + k, "F", 1) != 0
			&& str[i][k] != '1' && str[i][k] != '\n')
			exit(printf("ERROR IN MAP (unaccpected character)\n"));
		i++;
	}
}

int checkMapValid(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		str[i] = ft_strtrim(str[i], "\n");
		if (str[i][0] == '1')
			return (i);
		i++;
	}
	return (0);
}
