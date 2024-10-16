/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:53:33 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/16 15:11:07 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

void	put_so(char **str, t_map *textures)
{
	int	i;
	int	flag;
	int	save;

	i = 0;
	flag = 0;
	save = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "SO", 2) == 0)
		{
			if (str[i][2] != ' ' && str[i][2] != '\t')
				manage_error(str, textures);
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
	int	save;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "NO", 2) == 0)
		{
			if (str[i][2] != ' ' && str[i][2] != '\t')
				manage_error(str, textures);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures);
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
	int	save;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "WE", 2) == 0)
		{
			if (str[i][2] != ' ' && str[i][2] != '\t')
				manage_error(str, textures);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures);
	if (flag == 1)
	{
		str[save] = escape_spaces(str[save]);
		textures->we = put_map(str[save], 2);
	}
}

void	put_ea(char **str, t_map *textures)
{
	int	i;
	int	save;
	int	flag;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "EA", 2) == 0)
		{
			if (str[i][2] != ' ' && str[i][2] != '\t')
				manage_error(str, textures);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures);
	if (flag == 1)
	{
		str[save] = escape_spaces(str[save]);
		textures->ea = put_map(str[save], 2);
	}
}

void	put_f(char **str, t_map *textures)
{
	int	i;
	int	save;
	int	flag;

	i = 0;
	flag = 0;
	while (str && str[i] && str[i][0] != '1')
	{
		str[i] = escape_spaces(str[i]);
		if (ft_strncmp(str[i], "F", 1) == 0)
		{
			if (str[i][1] != ' ' && str[i][1] != '\t')
				manage_error(str, textures);
			flag++;
			save = i;
		}
		i++;
	}
	if (flag != 1)
		manage_error(str, textures);
	if (flag == 1)
	{
		str[save] = escape_spaces(str[save]);
		textures->f = put_map(str[save], 1);
	}
}
