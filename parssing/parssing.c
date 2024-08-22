/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:56:23 by haalouan          #+#    #+#             */
/*   Updated: 2024/08/22 15:54:37 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (ft_strncmp(str + i, ".cub", ft_strlen(str + i)) == 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

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

void parssing(int arc, char **arv)
{
	ssize_t fd;
	int     i;
	char    **all_lines;
	char	*line;
	// t_pars	*cub;

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
	all_lines = parse_all_lines(all_lines);
	// int l = 0;
	// while (all_lines && all_lines[l])
	// 	printf("%s", all_lines[l++]);
	// cub = put_in_struct(all_lines);
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

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
char	**parse_all_lines(char **str)
{
	char	**s;
	int		i;
	int		j;

	s = allocate_str(str);
	i = 0;
	j = 0;
	while (str && str[i])
	{	
		if (check_line(str[i]) == 1)
		{
			s[j] = ft_strdup(str[i]);
			i++;
			j++;
		}
		else
			i++;
	}
	return (s);
}

t_pars	*put_in_struct(char **all_lines)
{
	int		i;
	int		j;
	int		k;
	t_pars	*cub;

	i = 0;
	j = 0;
	k = 0;
	cub = allocate_cub();
	cub->path = allocate_path_fc(4);
	while (i < 4)
		cub->path[j++] = ft_strdup(all_lines[i++]);
	cub->f_c = allocate_path_fc(2);
	j = 0;
	while (i < 6)
		cub->f_c[j++] = ft_strdup(all_lines[i++]);
	j = i;
	i = 0;
	while (all_lines && all_lines[i + 1] != NULL)
		i++;
	cub->map = allocate_path_fc(i - 6);
	while (j <= i)
		cub->map[k++] = ft_strdup(all_lines[j++]);
	return (cub);
}

char	**allocate_path_fc(int i)
{
	char	**str;
	int		j;

	j = 0;
	str = NULL;
	str = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	if (!str)
		exit(EXIT_FAILURE);
	while (j <= i)
		str[j++] = NULL;
	return (str);
}

t_pars	*allocate_cub(void)
{
	t_pars	*cub;

	cub = NULL;
	cub = (t_pars *)malloc(sizeof(t_pars) + 1);
	if (!cub)
		exit(EXIT_FAILURE);
	cub->map = NULL;
	cub->f_c = NULL;
	cub->path = NULL;
	return (cub);
}
