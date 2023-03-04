#include "so_long.h"

int map_height(char *av)
{
    int map_height;
    char *line;
    int fd;

    fd = open(av, O_RDONLY);
    map_height = 0;
    line = get_next_line(fd);
    while (line)
    {
        map_height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    free (line);
    return (map_height);
}

int map_width(char *av)
{
    int fd;
    int len;
    char *line;

    fd = open(av, O_RDONLY);
    line = get_next_line(fd);
    len = ft_strlen(line);
    close(fd);
    free(line);
    return (len);
}

void    read_map(so_long *s_long, char *av)
{
    int i = 0;
    int fd;
    char *read_line;

    s_long->map_height = map_height(av);
    s_long->map_width = map_width(av);
    fd = open(av, O_RDONLY);
    s_long->map = (char **)malloc(map_height(av) * sizeof(char *));
    if (!s_long->map)
        ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
    read_line = get_next_line(fd);
    while (read_line != NULL)
    {
        s_long->map[i] = read_line;
        i++;
        read_line = get_next_line(fd);
    }
    close(fd);
    fillx(s_long);
}

void    read_map1(so_long *s_long, char *av)
{
    int i = 0;
    int fd = open(av, O_RDONLY);
    s_long->backtracking_map = (char **)malloc(map_height(av) * sizeof(char *));
    if (!s_long->backtracking_map)
        ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
    char *read_line = get_next_line(fd);
    while (read_line != NULL)
    {
        s_long->backtracking_map[i] = read_line;
        i++;
        read_line = get_next_line(fd);
    }
    close(fd);
}