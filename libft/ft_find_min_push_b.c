/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_push_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:56:00 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/26 15:29:17 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_pb(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	size;
	int	pos;

	min = ft_min_value(*stack_a);
	size = ft_lstsize(*stack_a);
	pos = ft_find_position(min, *stack_a);
	if (pos <= size / 2)
	{
		while (pos != 1)
		{
			ft_rotate_a(stack_a, 1);
			pos = ft_find_position(min, *stack_a);
		}
	}
	else if (pos > size / 2)
	{
		while (pos != 1)
		{
			ft_rotate_a(stack_a, 1);
			pos = ft_find_position(min, *stack_a);
		}
	}
	ft_push_b(stack_a, stack_b, 1);
}
