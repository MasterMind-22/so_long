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

char **read_map(char *av)
{
    int i = 0;
    char **map;
    int fd = open(av, O_RDONLY);
    map = (char **)malloc(map_height(av) * sizeof(sizeof(char *)));
    if (!map)
        return(free(map), NULL);
    char *read_line = get_next_line(fd);
    while (read_line != NULL)
    {
        map[i] = read_line;
        i++;
        read_line = get_next_line(fd);
        free(read_line);
    }
    map[i] = NULL;
    //free(read_line);
    return(map);
}