/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:06:48 by ayadouay          #+#    #+#             */
/*   Updated: 2025/01/28 15:58:07 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int	display_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	use_instraction(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_swap_a(*stack_a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_swap_b(*stack_b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_swap_a_b(*stack_a, *stack_b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_push_a(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_push_b(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate_a(stack_a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate_b(stack_b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rotate_a_b(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_reverse_rotate_a(stack_a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_reverse_rotate_b(stack_b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_reverse_rotate_a_b(stack_a, stack_b, 0);
	else
		return (display_error());
	return (0);
}

void	take_istcraction(t_list **stack_a, t_list **stack_b)
{
	char	*string;
	int		check;

	while (1)
	{
		string = get_next_line(0);
		if (!string)
			break ;
		check = use_instraction(string, stack_a, stack_b);
		free(string);
		if (check == 1)
			return ;
	}
	if (is_sorted(*stack_a) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		arr = ft_join_args_bns(argv);
		argv = ft_split(arr, ' ');
		check_argument(argv, arr);
		creat_linked_list(argv, &stack_a, &actual_node);
		take_istcraction(&stack_a, &stack_b);
		ft_free_stack(&stack_a);
		if (stack_b)
			ft_free_stack(&stack_b);
		free_args(argv, arr);
	}
	return (0);
}
