/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:56:23 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 16:54:39 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*parssing(int arc, char **arv)
{
	ssize_t	fd;
	char	**all_lines;
	t_map	*textures;
	int		i;

	(void)arc;
	i = 0;
	if (parsse_args(arv[1]) == 0)
		exit(printf("Error in ARGS\n"));
	fd = open(arv[1], O_RDONLY);
	if (fd < 0)
		exit(printf("READ FAILED\n"));
	all_lines = allocate_all_lines(fd, arv);
	all_lines = parsse_all_lines(all_lines);
	textures = allocate_textures();
	parsse_textures(all_lines, textures);
	parsse_map(all_lines, textures);
	free_all_lines(all_lines);
	return (textures);
}

char	**parsse_all_lines(char **str)
{
	char	**s;
	int		i;

	s = allocate_str(str);
	i = 0;
	while (str && str[i])
	{
		s[i] = ft_strdup(str[i]);
		i++;
	}
	check_map(str);
	free_all_lines(str);
	return (s);
}

void	check_map(char **str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str && str[i])
	{
		k = 0;
		while (str && str[i] && (str[i][k] == ' ' || str[i][k] == '\t'))
			k++;
		if (ft_strncmp(str[i] + k, "NO", 2) != 0
			&& ft_strncmp(str[i] + k, "SO", 2) != 0
			&& ft_strncmp(str[i] + k, "EA", 2) != 0
			&& ft_strncmp(str[i] + k, "WE", 2) != 0
			&& ft_strncmp(str[i] + k, "C", 1) != 0
			&& ft_strncmp(str[i] + k, "F", 1) != 0
			&& str[i][k] != '1' && str[i][k] != '\n')
		{
			free_all_lines(str);
			exit(printf("ERROR IN MAP (unaccpected character)\n"));
		}
		i++;
	}
}

int	check_map_valid(char **str)
{
	int		i;
	char	*save;

	i = 0;
	while (str && str[i])
	{
		save = ft_strtrim(str[i], "\n");
		if (save[0] == '1')
		{
			free(save);
			return (i);
		}
		free(save);
		i++;
	}
	return (0);
}
