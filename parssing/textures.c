/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:53:33 by haalouan          #+#    #+#             */
/*   Updated: 2024/08/23 15:23:56 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

char    *put_textures(char *str, int plus)
{
    char    *s;
    int     i;

    s = NULL;
    i = plus;
    while (str && str[i] && str[i] == ' ' && str[i] == '\t')
        i++;
    s = ft_strdup(str + i);
    s = ft_strtrim(s, "\n");
    // printf("%s", s);
    return (s);
}


void	check_so(char **str, t_textures *textures)
{
	int	i;
	int	flag;
    int save;

	i = 0;
	flag = 0;
    save = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "SO", 2) == 0 && (str[i][2] == ' '
            || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP\n"));
    if (flag == 1)
        textures->so = put_textures(str[save], 2);
}

void	check_no(char **str, t_textures *textures)
{
	int	i;
	int	flag;
    int save;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "NO", 2) == 0 && (str[i][2] == ' ' || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP\n"));
    if (flag == 1)
        textures->no = put_textures(str[save], 2);
}

void	check_we(char **str, t_textures *textures)
{
	int	i;
	int	flag;
    int save;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "WE", 2) == 0 && (str[i][2] == ' ' || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP\n"));
    if (flag == 1)
        textures->we = put_textures(str[save], 2);
}

void	check_ea(char **str, t_textures *textures)
{
	int	i;
    int save;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "EA", 2) == 0 && (str[i][2] == ' ' || str[i][2] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP\n"));
    if (flag == 1)
        textures->ea = put_textures(str[save], 2);
}

void	check_f(char **str, t_textures *textures)
{
	int	i;
    int save;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "F", 1) == 0 && (str[i][1] == ' ' || str[i][1] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP\n"));
    if (flag == 1)
        textures->f = put_textures(str[save], 1);
}

void	check_c(char **str, t_textures *textures)
{
	int	i;
    int save;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "C", 1) == 0 && (str[i][1] == ' ' || str[i][1] == '\t'))
		{
            flag++;
            save = i;
        }
		i++;
	}
	if (flag != 1)
		exit(printf("ERROR IN MAP\n"));
    if (flag == 1)
        textures->c = put_textures(str[save], 1);
}

void	parse_textures(char **str, t_textures *textures)
{
	check_no(str, textures);
	check_so(str, textures);
	check_we(str, textures);
	check_ea(str, textures);
	check_f(str, textures);
	check_c(str, textures);
}