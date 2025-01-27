/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:07:01 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/27 12:07:05 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_argument(char **argv, char *arr)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_valid_arguments(argv[i]))
		{
			write(2, "Error\n", 6);
			free_args(argv, arr);
			exit(1);
		}
		i++;
	}
	if (ft_has_duplicates_bns(argv))
	{
		write(2, "Error\n", 6);
		free_args(argv, arr);
		exit(1);
	}
	return (0);
}
