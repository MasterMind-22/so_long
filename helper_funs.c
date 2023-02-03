#include "so_long.h"

int ft_strchr(char *s)
{
    int i =0;

    if (!s)
        return(0);
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

// int main()
// {
//     printf("%d", ft_strchr(NULL));
// }