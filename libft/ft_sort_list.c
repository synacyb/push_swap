/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:32:39 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/26 15:23:39 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_list(t_list **list)
{
	int (min_node), (pos);
	min_node = ft_min_value(*list);
	pos = ft_find_position(min_node, *list);
	if (pos == 1)
	{
		if (((*list)->next->content > (*list)->next->next->content))
			(ft_swap_a(*list, 1), ft_rotate_a(list, 1));
	}
	else if (pos == 2)
	{
		if (((*list)->content > (*list)->next->content)
			&& ((*list)->content > (*list)->next->next->content))
			ft_rotate_a(list, 1);
		else if ((*list)->content > (*list)->next->content)
			ft_swap_a(*list, 1);
	}
	else if (pos == 3)
	{
		if (((*list)->content > (*list)->next->content)
			&& ((*list)->content > (*list)->next->next->content))
			ft_swap_a(*list, 1);
		if (((*list)->content < (*list)->next->content)
			&& ((*list)->content > (*list)->next->next->content))
			ft_reverse_rotate_a(list, 1);
	}
}
