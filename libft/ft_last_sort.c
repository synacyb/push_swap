/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:10:47 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 10:11:21 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_value(t_list *list)
{
	int	max;

	max = list->content;
	list = list->next;
	while (list)
	{
		if (max < list->content)
			max = list->content;
		list = list->next;
	}
	return (max);
}

void	ft_last_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_value;
	int	max_pos;
	int	len;

	while ((*stack_b))
	{
		max_value = ft_max_value(*stack_b);
		max_pos = ft_find_position(max_value, *stack_b);
		len = ft_lstsize(*stack_b);
		if (max_pos <= len / 2)
		{
			while ((*stack_b)->content != max_value)
				ft_rotate_b(stack_b);
		}
		else if (max_pos > len / 2)
		{
			while ((*stack_b)->content != max_value)
				ft_reverse_rotate_b(stack_b);
		}
		ft_push_a(stack_a, stack_b);
	}
}
