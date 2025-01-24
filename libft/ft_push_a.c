/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:15:29 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 10:17:23 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_a);
	*stack_a = tmp;
	ft_printf("pa\n");
}
