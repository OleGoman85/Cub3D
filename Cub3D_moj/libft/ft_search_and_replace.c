#include "libft.h"

// int	main(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;

// 	if (argc == 4 && !argv[2][1] && !argv[3][1])
// 	{
// 		while (argv[1][i] != '\0')
// 		{
// 			if (argv[1][i] == argv[2][0])
// 			{
// 				argv[1][i] = argv[3][0];
// 			}
// 			write(1, &argv[1][i], 1);
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// }
void ft_search_and_replace(char *str, char s1, char s2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s1)
		{
			str[i] = s2;
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
