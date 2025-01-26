/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:18:23 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/26 15:25:25 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

void	ft_push_b(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_b);
	*stack_b = tmp;
	if(flag == 1)
		ft_printf("pb\n");
}
