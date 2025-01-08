#include "libft.h"
#include "../ft_printf/ft_printf.h"

int ft_min_value(t_list *list)
{
    int min;

    min = list->content;
    list = list->next;
    while (list)
    {
        if (min > list->content)
            min = list->content;
        list = list->next;
    }
    return min;
}