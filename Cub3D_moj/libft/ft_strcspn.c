#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		count;
	const char	*r;

	count = 0;
	while (*s != '\0')
	{
		r = reject;
		while (*r != '\0')
		{
			if (*s == *r)
			{
				return (count);
			}
			r++;
		}
		s++;
		count++;
	}
	return (count);
}

// int main() {
//     const char *str = "Hello, World!";
//     const char *reject = "azlziou";

//     size_t result = ft_strcspn(str, reject);

//     printf("Length of the initial segment without characters from reject: %zu\n", result);

//     return 0;
// }

//funkcija poluchaet dve strok i proverjaet sovpadaet li kazdij simvol iz stroki 2 s simvolom
//iz stroki odin esli ne sovpadaet, perehodit k sledujuwemu. Esli sovpadaet, vozvrawaet
//kolichestvo proverennih simvolov v stroke odin

// The strcspn() function spans the initial part of the null-terminated string s as long as the characters from s do not occur in the null-terminated string charset (it spans the
//      complement of charset).  In other words, it computes the string array index of the first character of s which is also in charset, else the index of the first null character.

// RETURN VALUES
//      The strspn() and strcspn() functions return the number of characters spanned.

