#include "libft.h"

void	ft_insertion_sort(int *str, int len)
{
	int i = 1;
	while(i < len)
	{
		int tmp = str[i];
		int j = i - 1;
		while(j >= 0)
		{
			if(str[j] > tmp)
			{
				str[j + 1] = str[j];
				str[j] = tmp;
			}
			j--;
		}
		i++;
	}
}