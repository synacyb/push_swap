/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:58:34 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/24 10:07:12 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_empty(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
			j++;
		if (j == ft_strlen(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else if (av[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

char	*ft_join_args(char **argv)
{
	int		j;
	char	*arr;
	char	*tmp;

	arr = NULL;
	j = 1;
	check_empty(argv);
	while (argv[j])
	{
		tmp = arr;
		arr = ft_strjoin(arr, argv[j]);
		if (tmp)
			free(tmp);
		j++;
	}
	return (arr);
}
