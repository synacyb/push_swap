/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:48:51 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 09:50:54 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insertion_sort(int *str, int len)
{
	int	i;
	int	tmp;
	int	j;

	i = 1;
	while (i < len)
	{
		tmp = str[i];
		j = i - 1;
		while (j >= 0)
		{
			if (str[j] > tmp)
			{
				str[j + 1] = str[j];
				str[j] = tmp;
			}
			j--;
		}
		i++;
	}
}
