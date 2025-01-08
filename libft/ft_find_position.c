#include "libft.h"

int ft_find_position(int target, t_list *lst)
{
	size_t	i;

	i = 1;
	while (lst != NULL)
	{
        if (target == lst->content)
            break ;
		lst = lst->next;
        i++;
	}
	return (i);
}