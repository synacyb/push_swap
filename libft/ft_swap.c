#include "libft.h"
#include "../ft_printf/ft_printf.h"

void    ft_swap(t_list *list)
{
    if (!list || !list->next)
        exit(0);
    int tmp = 0;
    int value1 = list->content;
    int value2 = list->next->content;
    
    tmp = value1;
    list->content = value2;
    list->next->content = tmp;
}

void    ft_swap_a(t_list *list)
{
    ft_swap(list);    
    ft_printf("sa\n");
}

void    ft_swap_b(t_list *list)
{
    ft_swap(list); 
    ft_printf("sb\n");
}

void    ft_swap_a_b(t_list *list1, t_list *list2)
{
    ft_swap(list1);
    ft_swap(list2);
    ft_printf("ss\n");
}