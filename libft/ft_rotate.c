#include "libft.h"
#include "../ft_printf/ft_printf.h"

void    ft_rotate(t_list **stack_a)
{
    t_list *tmp;
    t_list *shift;

    tmp = *stack_a;
    shift = tmp->next;
    *stack_a = shift;
    tmp->next = NULL;
    ft_lstadd_back(stack_a, tmp);
}

void    ft_rotate_a(t_list **stack_a)
{
    ft_rotate(stack_a);
    ft_printf("ra\n");
}
void    ft_rotate_b(t_list **stack_b)
{
    ft_rotate(stack_b);
    ft_printf("rb\n");
}
void    ft_rotate_a_b(t_list **stack_a , t_list **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_printf("rr\n");
}