/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:14:51 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 10:15:09 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%d\n", list->content);
		list = list->next;
	}
}
