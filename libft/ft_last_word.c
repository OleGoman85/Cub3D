#include "libft.h"

void	ft_last_word(char *str)
{
	int word_start = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] >= 33 && str[i + 1] <= 126))
			word_start = i + 1;
		i++;
	}
	while (str[word_start] >= 33 && str[word_start] <= 127)
	{
		write(1, &str[word_start], 1);
		word_start++;
	}
}

// int main(void)
// {
// 	char *word = "FOR PONY";
// 	last_word(word);
// 	write(1, "\n", 1);
// 	return (0);
// }
