#include "get_next_line.h"

char	*ft_strdup_bns(const char *str)
{
	size_t	i;
	char	*ptr;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	ptr = malloc((len + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = ' ';
	ptr[i + 1] = '\0';
	return (ptr);
}