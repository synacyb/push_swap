/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:56:52 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/28 15:35:50 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

void	num_node_4_5(t_list **stack_a, t_list **stack_b)
{
	find_pb(stack_a, stack_b);
	ft_sort_list(stack_a);
	while (ft_lstsize(*stack_b))
		ft_push_a(stack_a, stack_b, 1);
}

void	ft_full_sort(t_list **stack_a, t_list **stack_b)
{
	int	num_node;

	num_node = ft_lstsize(*stack_a);
	if (num_node == 1)
		return ;
	else if (num_node == 2)
		ft_sort_2nbr(stack_a);
	else if (num_node == 3)
		ft_sort_list(stack_a);
	else if (num_node == 4 || num_node == 5)
		num_node_4_5(stack_a, stack_b);
	else
		ft_sort_stack(stack_a, stack_b);
}
