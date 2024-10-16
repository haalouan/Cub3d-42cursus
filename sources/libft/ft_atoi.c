/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:26:37 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/16 15:26:53 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f(unsigned long x, int signe, int count)
{
	if (x > 9223372036854775807 || count >= 20)
	{
		if (signe == 1)
			return (-1);
		else if (signe == -1)
			return (0);
	}
	return (x * signe);
}

static unsigned long	ft_ct(const char *str, unsigned long result, int *count)
{
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
		*count += 1;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				signe;
	int				count;

	i = 0;
	result = 0;
	signe = 1;
	count = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			signe = -1;
		}
		i++;
	}
	while (str[i] == '0')
		i++;
	result = ft_ct(str + i, result, &count);
	return (f(result, signe, count));
}
