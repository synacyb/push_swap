/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:34:08 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/30 11:18:03 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	ft_has_duplicates(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	if (ft_has_duplicates(argv))
	{
		write(2, "Error\n", 6);
		free_args(argv, arr);
		exit(1);
	}
	return (0);
}

void	creat_linked_list(char **av, t_list **stack, t_list **actual_node)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		*actual_node = creat_node(number);
		if (!stack)
			stack = actual_node;
		else
			ft_lstadd_back(stack, *actual_node);
		i++;
	}
}

int	main(int arc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*arr;
	t_list	*actual_node;

	if (arc > 1)
	{
		actual_node = NULL;
		stack_a = NULL;
		stack_b = NULL;
		arr = ft_join_args(argv);
		argv = ft_split(arr, ' ');
		check_argument(argv, arr);
		creat_linked_list(argv, &stack_a, &actual_node);
		if (is_sorted(stack_a))
		{
			ft_full_sort(&stack_a, &stack_b);
			ft_last_sort(&stack_a, &stack_b);
		}
		ft_free_stack(&stack_a);
		free_args(argv, arr);
	}
}
