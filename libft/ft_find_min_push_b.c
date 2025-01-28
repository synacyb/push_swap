/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_push_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:56:00 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/28 16:00:28 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_pb(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	pos;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = ft_min_value(*stack_a);
		pos = ft_find_position(min, *stack_a);
		if (pos == 1)
		{
			ft_push_b(stack_a, stack_b, 1);
		}
		else if (pos == 2)
		{
			ft_swap_a(*stack_a, 1);
			ft_push_b(stack_a, stack_b, 1);
		}
		else
			ft_reverse_rotate_a(stack_a, 1);
	}
}
