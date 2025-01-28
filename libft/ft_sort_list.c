/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:32:39 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/28 16:00:09 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_list(t_list **list)
{
	t_list	*tmp;

	tmp = (*list)->next;
	if ((*list)->content > tmp->content)
		ft_swap_a(*list, 1);
	if (tmp->next->content < tmp->content)
	{
		ft_reverse_rotate_a(list, 1);
		if (is_sorted(*list))
			ft_swap_a(*list, 1);
	}
}
