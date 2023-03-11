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

void    read_map(so_long *s_long, char *av)
{
    int i;
    int fd;
    char *read_line;

    i = 0;
    s_long->map_height = map_height(av);
    fd = open(av, O_RDONLY);
    s_long->map = (char **)malloc(s_long->map_height * sizeof(char *));
    if (!s_long->map)
        ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
    read_line = get_next_line(fd);
    s_long->map_width = ft_strlen(read_line)-1;
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
    int i;
    int fd;
    char *read_line;

    i = 0;
    fd = open(av, O_RDONLY);
    s_long->c_count = check_elements(s_long, 'C');
    s_long->backtracking_map = (char **)malloc(s_long->map_height * sizeof(char *));
    if (!s_long->backtracking_map)
        ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
    read_line = get_next_line(fd);
    while (read_line != NULL)
    {
        s_long->backtracking_map[i] = read_line;
        i++;
        read_line = get_next_line(fd);
    }
    close(fd);
}