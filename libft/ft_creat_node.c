#include "libft.h"

void    *creat_node(int element)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = element;
    node->next = NULL;
    return (node);
}