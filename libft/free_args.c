#include "libft.h"

void    free_args(char **av, char *arr)
{
    int i = 0;
    while(av[i])
        i++;
    i = i - 1;
    while (i >= 0)
			free(av[i--]);
    free(av);
    free(arr);
}