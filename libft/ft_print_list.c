#include "libft.h"
#include "../ft_printf/ft_printf.h"
void    ft_print_list(t_list *list)
{
    while (list)
    {
        ft_printf("%d\n", list->content);
        list = list->next;
    }
}