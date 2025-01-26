#include "get_next_line.h"

void	check_empty_bns(char **av)
{
	int		i;
	size_t	j;

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

char	*ft_join_args_bns(char **argv)
{
	int		j;
	char	*arr;
	char	*tmp;

	arr = NULL;
	j = 1;
	check_empty_bns(argv);
	while (argv[j])
	{
		tmp = arr;
		arr = ft_strjoin_bns(arr, argv[j]);
		if (tmp)
			free(tmp);
		j++;
	}
	return (arr);
}