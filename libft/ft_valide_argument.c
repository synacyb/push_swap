/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:55:04 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 10:56:02 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_valid_arguments(char *nptr)
{
	if (ft_atoi(nptr) == 2147483649)
		return (1);
	else if (*nptr == '+' || *nptr == '-')
	{
		nptr++;
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (1);
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
		nptr++;
	if (!*nptr)
		return (0);
	else
		return (1);
}
