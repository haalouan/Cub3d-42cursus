/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:53:33 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/15 16:18:09 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

char    *put_map(char *str, int plus)
{
    char    *s;
    int     i;

    s = NULL;
    i = plus;
    while (str && str[i] && str[i] == ' ' && str[i] == '\t')
        i++;
    s = ft_strdup(str + i);
    s = ft_strtrim(s, "\n");
	s = escape_spaces(s);
    return (s);
}


void	put_so(char **str, t_map *textures)
{
	int	i;
	int	flag;
    int save;

	i = 0;
	flag = 0;
    save = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "SO", 2) == 0 && (str[i][2] == ' '
            || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP (SO)\n"));
    if (flag == 1)
    {
		str[save] = escape_spaces(str[save]);
		textures->so = put_map(str[save], 2);
	}
}

void	put_no(char **str, t_map *textures)
{
	int	i;
	int	flag;
    int save;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "NO", 2) == 0 && (str[i][2] == ' ' || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP (NO)\n"));
    if (flag == 1)
    {
		str[save] = escape_spaces(str[save]);
		textures->no = put_map(str[save], 2);
	}
}

void	put_we(char **str, t_map *textures)
{
	int	i;
	int	flag;
    int save;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "WE", 2) == 0 && (str[i][2] == ' ' || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP (WE)\n"));
    if (flag == 1)
    {
		str[save] = escape_spaces(str[save]);
		textures->we = put_map(str[save], 2);
	}
}

void	put_ea(char **str, t_map *textures)
{
	int	i;
    int save;
	int	flag;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "EA", 2) == 0 && (str[i][2] == ' ' || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP (EA)\n"));
   	if (flag == 1)
    {
		str[save] = escape_spaces(str[save]);
		textures->ea = put_map(str[save], 2);
	}
}

void	put_f(char **str, t_map *textures)
{
	int	i;
    int save;
	int	flag;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "F", 1) == 0 && (str[i][1] == ' ' || str[i][1] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP (F)\n"));
    if (flag == 1)
    {
		str[save] = escape_spaces(str[save]);
		textures->f = put_map(str[save], 1);
	}
}

void	put_c(char **str, t_map *textures)
{
	int	i;
    int save;
	int	flag;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "C", 1) == 0 && (str[i][1] == ' ' || str[i][1] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP (C)\n"));
    if (flag == 1)
    {
		str[save] = escape_spaces(str[save]);
		textures->c = put_map(str[save], 1);
	}

}

void	put_0_1(char **str, t_map *textures)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	i = checkMapValid(str);
	textures->map = allocate_map(count_map(str + i));
	while (str && str[i])
	{
		if (str[i][0] == '\n')
			exit(printf("Error (Empty line in Map)\n"));
		str[i] = ft_strtrim(str[i], "\n");
		textures->map[k] = ft_strdup(str[i]);
		k++;
		i++;
	}
}

void	parsse_textures(char **str, t_map *textures)
{
	put_no(str, textures);
	put_so(str, textures);
	put_we(str, textures);
	put_ea(str, textures);
	put_f(str, textures);
	put_c(str, textures);
	put_0_1(str, textures);
}

char	*escape_spaces(char *str)
{
	str = ft_strtrim(str, " ");
	str = ft_strtrim(str, "\t");
	return (str);
}