# include "libft.h"

// vazno dlja ponimanija! znachenija ne zamenjajutsja,
//a chitajutsja i vivodjatsja poocheredno

void ft_epur_str(char *str)
{
    int i;
    i = 0;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] && (str[i] != ' ' && str[i] != '\t'))
    {
        write(1, &str[i], 1);
        i++;
    }
    while(str[i])
    {
        if(str[i] && (str[i - 1] == ' ' || str[i - 1] == '\t') && (str[i] != ' ' && str[i] != '\t'))
        {
            write(1, " ", 1);
            while(str[i] && (str[i] != ' ' && str[i] != '\t'))
            {
                write(1, &str[i], 1);
                i++;
            }
        }
        else
            i++;
    }

    write(1, "\n", 1);
}

// odin probel mezdu slovami