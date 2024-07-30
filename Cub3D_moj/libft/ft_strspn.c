
#include "libft.h"

size_t ft_strspn(const char *s, const char *accept) 
{
    size_t i = 0;

    while (s[i] != '\0') 
    {
        // Check if the current character of s exists in accept
        const char *a = accept;
        while (*a != '\0') 
        {
            if (*a == s[i])
                break;
            a++;
        }
        // If the character doesn't exist in accept, return the current index
        if (*a == '\0')
            return i;
        i++;
    }
    return i;
}


// int main()
// {
// 	const char *s = "gabc123";
// 	const char *accept = "gba";

// 	size_t result = ft_strspn(s, accept);

// 	printf("Length of initial segment matching: %zu\n", result);
// 	return 0;
// }
