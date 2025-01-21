#include "libft.h"

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
    int max_value;
    int max_pos;


    while ((*stack_b))
    {
        max_value = ft_max_value(*stack_b);
        max_pos = ft_find_position(max_value, *stack_b);
        int len = ft_lstsize(*stack_b);
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