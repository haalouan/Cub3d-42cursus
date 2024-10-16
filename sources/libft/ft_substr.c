/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:09:42 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/16 16:09:45 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	ls;
	char	*d;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ls = ft_strlen(s);
	if (start >= ls)
	{
		start = ls;
		len = 0;
	}
	else if (start + len > ls)
		len = ls - start;
	d = (char *)malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
