/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:28:27 by shamdoun          #+#    #+#             */
/*   Updated: 2024/09/26 16:58:28 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_ray	*ft_lstnew(double x)
{
	t_ray	*n_node;

	n_node = (t_ray *)ft_malloc(sizeof(t_ray), 0);
	if (!n_node)
		return (NULL);
	n_node ->angle = x;
	n_node -> next = NULL;
	return (n_node);
}

t_data	*ft_lstnew_ad(void *address)
{
	t_data	*n_node;

	n_node = (t_data *)malloc(sizeof(t_data));
	if (!n_node)
		return (NULL);
	n_node ->data = address;
	n_node -> next = NULL;
	return (n_node);
}
