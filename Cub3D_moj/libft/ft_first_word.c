#include "libft.h"

void ft_first_word(char *str)
{
	char *currentchar;

	currentchar = str;
	while (*currentchar == ' ' || *currentchar == '\t')
		currentchar++;
	while (*currentchar != ' ' && *currentchar != '\t' && *currentchar != '\0')
	{
		write(1, currentchar, 1);
		currentchar++;
	}
	write(1, "\n", 1);
}