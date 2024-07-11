#include "libft.h"

void ft_union(char *s1, char *s2) 
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (s1[i] != '\0')
        i++;

    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    while (s1[k] != '\0')
    {
        j = 0;
        while (j < k)
        {
            if (s1[k] == s1[j])
                break ;
            j++;
        }
        if (j == k)
            write(1, &s1[k], 1);
        k++;
    }
    write(1, "\n", 1);
}

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$