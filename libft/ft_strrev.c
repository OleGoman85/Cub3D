#include "libft.h"

char *ft_strrev(char *str)
{
	int len = 0;
	int start = 0;
	
	while (str[len] != '\0')
		len++;
		
	int end = len - 1;

	while (start < end)
	{
		// Обмен символами на позициях start и end
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		// Перемещение указателя start вперед и указателя end назад
		start++;
		end--;
	}
	return str;
}

// Эта функция принимает строку в качестве входных данных и инвертирует ее на месте.
// Она использует два указателя (start и end), чтобы пройти через строку,
// обменивая символы, пока они не встретятся в середине. Функция возвращает инвертированную строку.




// #include <stdio.h>

// int main(void)
// {
//     char str[] = "Hello, World!";
//     printf("Original: %s\n", str);

//     ft_strrev(str);

//     printf("Reversed: %s\n", str);

//     return 0;
// }
