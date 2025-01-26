/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2rndom_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:47:47 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/26 15:13:26 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_2nbr(t_list **list)
{
	int	min_node;
	int	pos;

	min_node = ft_min_value(*list);
	pos = ft_find_position(min_node, *list);
	if (pos == 2)
	{
		if ((*list)->content > (*list)->next->content)
			ft_swap_a(*list, 1);
	}
}
