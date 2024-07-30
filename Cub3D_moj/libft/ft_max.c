#include "libft.h"

int		ft_max(int* tab, unsigned int len)
{
	int	result;
	unsigned int	i;
	
	i = 0;
	result = tab[i];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}

// int main(void)
// {
// 	int tab[] = {1, 4, 5, 10, 2, 23, 43};
// 	unsigned int size = sizeof(tab) / sizeof(tab[0]);
// 	printf ("%d", max(tab, size));
	
// 	return (0);
// }

