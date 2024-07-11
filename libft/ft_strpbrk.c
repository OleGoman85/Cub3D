#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*temp;

	while (*s1)
	{
		temp = s2;
		while (*temp)
		{
			if (*s1 == *temp)
				return ((char *)s1);
			temp++;
		}
		s1++;
	}

	return NULL; // Если не найдено совпадение
}
// Функция ft_strpbrk ищет в строке s1 первое вхождение любого символа из строки s2.
// Если такой символ найден, функция возвращает указатель на этот символ в строке s1;
// в противном случае, она возвращает нулевой указатель (NULL).

