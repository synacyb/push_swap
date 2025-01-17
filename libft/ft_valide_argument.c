#include "libft.h"

int ft_valid_arguments(char *nptr)
{
    if (ft_atoi(nptr) == 2147483649)
        return 1;

	else if (*nptr == '+' || *nptr == '-')
    {
		nptr++;
        if (!(*nptr >= '0' && *nptr <= '9'))
            return 1;
    }

	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
        nptr++;
    if (!*nptr)
        return 0;
    else
        return 1;
}
