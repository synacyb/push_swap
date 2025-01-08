#include "libft.h"
#include "../ft_printf/ft_printf.h"

void    ft_push_b(t_list **stack_a, t_list **stack_b)
{
    if (!(*stack_a))
        exit(0);
    t_list *tmp;

    tmp = (*stack_a);
    *stack_a = (*stack_a)->next;
    tmp->next = (*stack_b);
    *stack_b = tmp;
    ft_printf("pb\n");
}