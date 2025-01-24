/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:13:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 10:14:21 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min_value(t_list *list)
{
	int	min;

	min = list->content;
	list = list->next;
	while (list)
	{
		if (min > list->content)
			min = list->content;
		list = list->next;
	}
	return (min);
}
