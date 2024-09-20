/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:11:33 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 19:11:37 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 == '\0' || *str2 == '\0' || *str1 != *str2)
			return ((unsigned char)(*str1) - (unsigned char)(*str2));
		str1++;
		str2++;
		n--;
	}
	return (0);
}
