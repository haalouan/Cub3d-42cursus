/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:15:51 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 19:15:54 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*sr;
	char		*ds;
	size_t		i;

	ds = (char *)dst;
	sr = (char *)src;
	if (ds == NULL && sr == NULL)
		return (0);
	i = 0;
	while (n > 0)
	{
		*ds = *sr;
		ds++;
		sr++;
		n--;
	}
	return (dst);
}
