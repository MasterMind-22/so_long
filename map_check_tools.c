#include "so_long.h"

static int count_char_int_line(char *str, int c)
{
    int i =0;
    int count=0;

    while(str[i])
    {
        if(str[i] == (char)c)
            count++;
        i++;
    }
    return count;
}

int extension_check(char *av)
{
    int i = 0;
    while (av[i] != '.')
        i++;
    while (av[i] == '.')
        i++;
    i--;
    return(strcmp(".ber", av+i));
}

int walls_check(char **map, char *av)
{
    int i;
    int j;
    int result;

    i=0;
    j=0;
    result = 0;
    while (i<map_height(av))
    {
        j=0;
        while (j<ft_strlen(map[0]) - 1)
        {
            if (map[i][j] != '1' && (i == 0 || j == 0 || i == map_height(av)-1 || j == ft_strlen(map[0])-2))
            {
                result++;
                break;
            }
            j++;
        }
        i++;
    }
    return (result);
}

int check_elements(char **map, char c, char *av)
{
    int i = 0;
    int count = 0;

    while (i < map_height(av))
    {
        count += count_char_int_line(map[i], c);
        i++;
    }
    return (count);
}

int check_strange(char **map, char *av)
{
    int i = 0;
    int count = 0;

    char *elements = "01ECP";
    while (elements[i])
    {
        count += check_elements(map, elements[i], av);
        i++;
    }
    if (count == map_height(av) * (map_width(av)-1))
        return (1);
    return (0);
}