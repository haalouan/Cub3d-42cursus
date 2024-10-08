/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:19:17 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/08 18:49:32 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_all_allocated_data(t_data **data)
{
	t_data	*tmp;

	while (*data)
	{
		tmp = *data;
		*data = (*data)->next;
		free(tmp->data);
		free(tmp);
		tmp = NULL;
	}
}

void	ft_add_new_a_data(t_data **list, void *address)
{
	t_data	*new;

	new = ft_lstnew_ad(address);
	if (!new)
		exit (1);
	ft_lstadd_a_back(list, new);
}

void	*ft_malloc(size_t size, int flag)
{
	static t_data	*garbage;
	void			*address;

	if (flag)
		free_all_allocated_data(&garbage);
	else
	{
		address = malloc(size);
		if (!address)
			return (NULL);
		ft_add_new_a_data(&garbage, address);
		return (address);
	}
	return (NULL);
}