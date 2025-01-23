/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:35 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/23 10:48:05 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_range(t_list *stack)
{
	int	len;

	len = ft_lstsize(stack);
	if (len <= 16)
		return (len / 2);
	else if (len <= 100)
		return (len / 5);
	else if (len <= 500)
		return (len / 12);
	else
		return (len / (len / 2));
}

int	*creat_arr(t_list *list)
{
	d_sort	my_arr;

	my_arr.len = ft_lstsize(list);
	my_arr.arr = malloc(my_arr.len * sizeof(int));
	if (!(my_arr.arr))
		return (0);
	my_arr.index = 0;
	while (list)
	{
		my_arr.arr[my_arr.index] = list->content;
		list = list->next;
		my_arr.index++;
	}
	return (my_arr.arr);
}

void	ft_check_stack_b(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) >= 2)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_swap_b(*stack_b);
	}
}

void	helper(d_sort *my_data, t_list **stack_a)
{
	my_data->range = get_range(*stack_a);
	my_data->arr = creat_arr(*stack_a);
	my_data->len = ft_lstsize(*stack_a);
	my_data->index = 0;
	ft_insertion_sort(my_data->arr, ft_lstsize(*stack_a));
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	d_sort	my_data;

	helper(&my_data, stack_a);
	while (*stack_a)
	{
		if (my_data.range + my_data.index >= my_data.len)
			my_data.range = (my_data.len - my_data.index) - 1;
		if ((*stack_a)->content >= my_data.arr[my_data.index]
			&& (*stack_a)->content <= my_data.arr[(my_data.range)
				+ (my_data.index)])
		{
			ft_push_b(stack_a, stack_b);
			ft_check_stack_b(stack_b);
			my_data.index++;
		}
		else if ((*stack_a)->content < my_data.arr[my_data.index])
		{
			ft_push_b(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next)
				ft_rotate_b(stack_b);
			my_data.index++;
		}
		else
			ft_rotate_a(stack_a);
	}
}
