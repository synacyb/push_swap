/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:30:40 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/28 09:34:17 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

void	ft_rotate(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*shift;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	shift = tmp->next;
	*stack_a = shift;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
}

void	ft_rotate_a(t_list **stack_a, int flag)
{
	ft_rotate(stack_a);
	if (flag == 1)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_list **stack_b, int flag)
{
	ft_rotate(stack_b);
	if (flag == 1)
		ft_printf("rb\n");
}

void	ft_rotate_a_b(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (flag == 1)
		ft_printf("rr\n");
}
