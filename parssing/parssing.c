/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:56:23 by haalouan          #+#    #+#             */
/*   Updated: 2024/08/23 15:25:57 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void parssing(int arc, char **arv)
{
	ssize_t fd;
	int     i;
	char    **all_lines;
	char	*line;
	t_textures	*textures;

	(void)arc;
	i = 0;
	if (parse_args(arv[1]) == 0)
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
	all_lines = parse_all_lines(all_lines, textures);
	printf("%s\n",textures->c);
	printf("%s\n",textures->f);
	printf("%s\n",textures->no);
	printf("%s\n",textures->so);
	printf("%s\n",textures->ea);
	printf("%s\n",textures->we);
}

char	**parse_all_lines(char **str, t_textures *textures)
{
	char	**s;
	int		i;
	int		j;

	s = allocate_str(str);
	i = 0;
	j = 0;
	while (str && str[i])
	{	
		if (check_line_spaces(str[i]) == 1)
		{
			s[j] = ft_strdup(str[i]);
			i++;
			j++;
		}
		else
			i++;
	}
	parse_textures(s, textures);
	return (s);
}

