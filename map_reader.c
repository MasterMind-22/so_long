#include "so_long.h"

size_t map_height(char *av)
{
    int map_height;
    int fd;

    map_height = 0;
    fd = open(av, O_RDONLY);
    while (get_next_line(fd))
        map_height++;
    return (map_height);
}

size_t map_width(char *av)
{
    int fd;

    fd = open(av, O_RDONLY);
    return (strlen(get_next_line(fd)));
}

void    read_map(so_long *s_long, char *av)
{
    int i = 0;
    //s_long->map_height = map_height(av);
    //s_long->map_width = map_width(av);
    int fd = open(av, O_RDONLY);
    s_long->map = (char **)malloc(map_height(av) * sizeof(sizeof(char *)));
    if (!s_long->map)
        ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
    char *read_line = get_next_line(fd);
    while (read_line != NULL)
    {
        s_long->map[i] = read_line;
        i++;
        read_line = get_next_line(fd);
    }
    fillx(s_long);
}