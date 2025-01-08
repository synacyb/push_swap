#include "libft.h"

char	*ft_join_args(char **argv)
{
	int j;
	char *arr;
	char *tmp;

	arr = NULL;
	j = 1;
	if (argv[j][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (argv[j])
	{
		tmp = arr;
		arr = ft_strjoin(arr, argv[j]);
		if (tmp)
			free(tmp);
		j++;
	}
	return arr;
}