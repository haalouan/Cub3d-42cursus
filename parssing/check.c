/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:18:29 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/16 17:03:01 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

int	check_line_spaces(char *str)
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

int	parsse_args(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
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

void	check_f_c(char **str, t_map *textures)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i][0] == 'C' || str[i][0] == 'F')
			continue_check_f_c(str, textures, str[i]);	
		i++;
	}
}

void	continue_check_f_c(char **str, t_map *textures, char *s)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (s && s[j] && s[j] != '\n')
	{
		if (s[j] <= '9' && s[j] >= '0')
		{
			continue_f_c(str, textures, s, &j);
			flag++;
		}
		if (flag > 3)
			manage_error(str, textures);
		j++;
	}
}

void	continue_f_c(char **str, t_map *textures, char *s, int *j)
{
	int		start;
	int		end;
	int		res;
	char	*save;
	
	start = *j;
	while (s[*j] && s[*j] != '\n' && s[*j] != ',')
		(*j)++;
	end = *j - 1;
	save = ft_copy(s, start, end);
	start = 0;
	while (save && save[start])
	{
		if (save[start] > '9' || save[start] < '0')
		{
			free(save);
			manage_error(str, textures);
		}
		start++;
	}
	res = ft_atoi(save);
	free(save);
	if (res < 0 || res > 255)
		manage_error(str, textures);
}

char	*ft_copy(char *str, size_t start, size_t end)
{
    int		len;
    char	*new_str;
	int		i;	
	
	len = end - start + 1;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
    if (!new_str)
	{
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < len)
	{
        new_str[i] = str[start + i];
        i++;
    }
    new_str[len] = '\0';
    return (new_str);
}
