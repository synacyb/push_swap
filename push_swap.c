#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

static int	ft_has_duplicates(char **arr)
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

int check_argument(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		if (ft_valid_arguments(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	if (ft_has_duplicates(argv))
	{
			write(2, "Error\n", 6);
			exit(1);
	}
	return 0;
}

int main(int arc, char **argv)
{
	if (arc > 1)
	{
		int i;
		int number;
		int num_node;
		t_list	*stack_a;
		t_list	*stack_b;
		char *arr;

		t_list	*actual_node = NULL;
		stack_a = NULL;
		stack_b = NULL;
		i = 0;
		arr = ft_join_args(argv);
		argv = ft_split(arr, ' ');
		check_argument(argv);
		while (argv[i])
		{
		 	number = ft_atoi(argv[i]);
		 	actual_node = creat_node(number);
		 	if (!stack_a)
		 		stack_a = actual_node;
		 	else
		 		ft_lstadd_back(&stack_a, actual_node);
		 	i++;
		}
		num_node = ft_lstsize(stack_a);
		if(num_node == 2)
			ft_sort_2nbr(&stack_a);
		else if (num_node == 3)
			ft_sort_list(&stack_a);
		else if (num_node == 4 || num_node == 5)
		{
			if (num_node == 5)
			{
				ft_find_min_push_b(&stack_a, &stack_b);
				ft_find_min_push_b(&stack_a, &stack_b);
				ft_sort_list(&stack_a);
				while (stack_b)
					ft_push_a(&stack_a, &stack_b);
				// ft_push_a(stack_a, stack_b);
			}
			if (num_node == 4)
			{
				ft_find_min_push_b(&stack_a, &stack_b);
				ft_sort_list(&stack_a);
				while (stack_b)
					ft_push_a(&stack_a, &stack_b);
			}
		}
		ft_printf("-----stack_a----\n");
		// ft_swap_a(stack_a);
		ft_print_list(stack_a);
		ft_free_stack(&stack_a);

		i = i - 1;
		while (i >= 0)
		{
			free(argv[i]);
			i--;
		}
		free(argv);
		free(arr);
	}
}