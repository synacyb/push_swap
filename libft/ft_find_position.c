/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:53:21 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/13 11:54:03 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_position(int target, t_list *lst)
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
