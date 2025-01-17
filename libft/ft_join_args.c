#include "libft.h"

char	*ft_join_args(char **argv)
{
	int j;
	char *arr;
	char *tmp;

	arr = NULL;
	j = 1;
	unsigned int i;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] == ' ' || (argv[j][i] >= 9 && argv[j][i] <= 13))
			i++;

		if (i == ft_strlen(argv[j]))
		{
			write(2, "Error\n", 6);
			free(arr);
			exit(1);
		}
		else if (argv[j][0] == '\0')
		{
			write(2, "Error\n", 6);
			free(arr);
			exit(1);
		}
		tmp = arr;
		arr = ft_strjoin(arr, argv[j]);
		if (tmp)
			free(tmp);
		j++;
	}
	return arr;
}