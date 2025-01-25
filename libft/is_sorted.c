/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:07:20 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/25 19:13:48 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(int a, int b)
{
	return (a < b);
}

int	is_sorted(t_list *list)
{
	int	first;
	int	second;

	while (list->next)
	{
		first = list->content;
		second = list->next->content;
		if (checker(first, second) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}
