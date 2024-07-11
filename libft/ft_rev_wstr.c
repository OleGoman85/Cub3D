#include "libft.h"

void ft_rev_wstr(char *str)
{
	int start;
	int end;
	int i = 0;
	int flag = 0;

	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		while (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
			i--;
		end = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i--;
		if (i == 0)
		{
			start = i;
			flag = 0;
		}
		else 
		{	
			start = i + 1;
			flag = start;
		}
		while (start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
		if (flag != 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}




// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$