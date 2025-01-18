#include "libft.h"

int	get_range(t_list *stack)
{
	int len;

	len = ft_lstsize(stack);
	if (len <= 16)
		return (3);
	else if(len <= 100)
		return (13);
	else if (len <= 500)
		return (30);
	else
		return (45);
}
int	*creat_arr(t_list *list)
{
	d_sort my_arr;
	my_arr.len = ft_lstsize(list);
	my_arr.arr = malloc(my_arr.len * sizeof(int));
	if (!(my_arr.arr))
		return 0;
	my_arr.index = 0;
	while (list)
	{
		my_arr.arr[my_arr.index] = list->content;
		list = list->next;
		my_arr.index++;
	}
	return my_arr.arr;
}

void	ft_check_stack_b(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) >= 2)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_swap_b(*stack_b);
	}
}

void	ft_sort2(t_list **list)
{
	d_sort sort2;
	sort2.index = 0;
	t_list *tmp = *list;

	while ((tmp)->next && (tmp)->content > (tmp)->next->content)
	{
		sort2.index++;
		tmp = tmp->next;
	}
	if (sort2.index > ft_lstsize(*list) / 2)
		ft_reverse_rotate_a(list);
	else
		ft_rotate_a(list);
}

void    ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	d_sort my_data;

	my_data.range = get_range(*stack_a);
	my_data.arr = creat_arr(*stack_a);
	my_data.len = ft_lstsize(*stack_a);
	my_data.index = 0;
	ft_insertion_sort(my_data.arr, ft_lstsize(*stack_a));
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
			ft_sort2(stack_a);
	}
}