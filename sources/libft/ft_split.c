/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:02:42 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/08 19:08:44 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count(char const *s, char c, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			(*count)++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
}

char	*ft_strdnup(const char *s, int start, int len)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)ft_malloc(sizeof(char) * len + 1, 0);
	if (!ret)
		return (NULL);
	while (s[i] && len)
	{
		if (i >= start)
		{
			ret[j++] = s[i];
			len--;
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

static char	**ft_add_data(char **array, const char *s, char c, int *range)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			(i)++;
		else
		{
			while (s[i] && s[i] != c)
			{
				(*range)++;
				i++;
			}
			array[j] = ft_strdnup(s, i - *range, *range);
			if (!array[j])
				return (NULL);
			j++;
			*range = 0;
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**array;
	int		range;

	count = 0;
	range = 0;
	if (s == NULL)
		return (NULL);
	ft_count(s, c, &count);
	array = (char **)ft_malloc((count + 1) * sizeof(char *), 0);
	if (!array)
		return (NULL);
	array[count] = 0;
	array = ft_add_data(array, s, c, &range);
	return (array);
}