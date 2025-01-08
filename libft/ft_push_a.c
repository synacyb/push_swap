#include "libft.h"
#include "../ft_printf/ft_printf.h"

void    ft_push_a(t_list **stack_a, t_list **stack_b)
{
    if (!(*stack_b))
        exit(0);
    t_list *tmp;

    tmp = (*stack_b);
    *stack_b = (*stack_b)->next;
    tmp->next = (*stack_a);
    *stack_a = tmp;
    ft_printf("pa\n");
}