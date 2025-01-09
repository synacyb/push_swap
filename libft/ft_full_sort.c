#include "libft.h"
#include "../ft_printf/ft_printf.h"

int     get_runge(t_list *stack_a)
{
    int len = ft_lstsize(stack_a);

    if (len <= 16)
        return 3;
    else if(len <= 100)
        return 13;
    else if (len <= 500)
        return 30;
    else if (len > 500)
        return 45;
    
    return 0;
}
int	*ft_insertion_sort(int *str, int len)
{
	int i;
	int j;
    int tmp;

	i = 1;
	while(i < len)
	{
		tmp = str[i];
		j = i - 1;
		while(j >= 0)
		{
			if(str[j] > tmp)
			{
				str[j + 1] = str[j];
				str[j] = tmp;
			}
			j--;
		}
		i++;
	}
    return (str);
}
int    *ft_add_arr(t_list **stack_a)
{
    int *arr;
    int i;
    t_list *current;

    current = *stack_a;
    arr = malloc(ft_lstsize(*stack_a) * sizeof(int));
    i = 0;
    while (current)
    {
        arr[i] = current->content;
        current = current->next;
        i++;
    }
    return arr;
}
void check_stack_b(t_list *stack_b)
{
    int len = ft_lstsize(stack_b);

    if (len >= 2)
    {
        if (stack_b->content < stack_b->next->content)
            ft_swap_b(stack_b);
    }
    
}
void    ft_sort(t_list **stack_a, t_list **stack_b)
{
    int *str;
    str = ft_add_arr(stack_a);
    int i = 0;
    int j = 0;
    int r = get_runge(*stack_a);
    int len = ft_lstsize(*stack_a);

    str = ft_insertion_sort(str, len);
    t_list  *cup;
    while (*stack_a)
    {
        cup = *stack_a;
        if (r + i >= len)
            r = len - i - 1; 
        if ((*stack_a)->content >= str[i] && (*stack_a)->content <= str[r + i])
        {
            ft_push_b(stack_a, stack_b);
            check_stack_b(*stack_b);
            i++;
        }
        else if ((*stack_a)->content < str[i])
        {
            ft_push_b(stack_a, stack_b);
            ft_rotate_b(stack_b);
            i++;
        }
        else
        {
            while ((cup))
            {
                if ((cup)->next && (cup)->content > (cup)->next->content)
                    j++;
                cup = (cup)->next;
            }
            if (j == ft_lstsize(cup))
                ft_reverse_rotate_a(stack_a);
            else
                ft_rotate_a(stack_a);
                
        }
    }
}

int ft_max_value(t_list *list)
{
    int max;

    max = list->content;
    list = list->next;
    while (list)
    {
        if (max < list->content)
            max = list->content;
        list = list->next;
    }
    return max;
}

void    ft_last_sort(t_list **stack_a, t_list **stack_b)
{
    int max_value , max_pos;
    int len_stack_b;

    max_value = ft_max_value(*stack_b);
    max_pos = ft_find_position(max_value, *stack_b);
    len_stack_b = ft_lstsize(*stack_b);

    if (max_pos <= len_stack_b / 2)
    {
        while ((*stack_b)->content != max_value)
            ft_rotate_b(stack_b);
    }
    else if (max_pos > len_stack_b / 2)
    {
        while ((*stack_b)->content != max_value)
            ft_reverse_rotate_b(stack_b);
    }
    ft_push_a(stack_a, stack_b);

}
void    ft_full_sort(t_list **stack_a, t_list **stack_b)
{
    int num_node;
    num_node = ft_lstsize(*stack_a);
    if (num_node == 1)
        return ;
    else if(num_node == 2)
		ft_sort_2nbr(stack_a);
	else if (num_node == 3)
		ft_sort_list(stack_a);
    else if (num_node == 4 || num_node == 5)
    {
	    if (num_node == 5)
	    {
	       ft_find_min_push_b(stack_a, stack_b);
	    	ft_find_min_push_b(stack_a, stack_b);
	    	ft_sort_list(stack_a);
	    	while (*stack_b)
	    		ft_push_a(stack_a, stack_b);
    	}
    	if (num_node == 4)
	    {
	        ft_find_min_push_b(stack_a, stack_b);
	    	ft_sort_list(stack_a);
	    	while (*stack_b)
         	    ft_push_a(stack_a, stack_b);
	    }
    }
    else
    {
        ft_sort(stack_a, stack_b);
        while (*stack_b)
        {
            ft_last_sort(stack_a, stack_b);
        }
    }
       
}