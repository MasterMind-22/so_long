#include "so_long.h"

void map_height(so_long *s_long, char *av)
{
    int fd;
    char *line;

    fd = open(av, O_RDONLY);
    line = get_next_line(fd);
    s_long->map_height = 0;
    s_long->map_width = strlen(line);
    while (line)
    {
        s_long->map_height++;
        line = get_next_line(fd);
    }
    free(line);
}

void    read_map(so_long *s_long, char *av)
{
    int fd;
    char *read_line;
    int i = 0;

    map_height(s_long, av);
    fd = open(av, O_RDONLY);
    read_line = get_next_line(fd);
    s_long->map = malloc (s_long->map_height * sizeof(char *));
    s_long->map_copy = malloc (s_long->map_height * sizeof(char *));
    while (read_line)
    {
        s_long->map[i] = read_line;
        s_long->map_copy[i] = read_line;
        read_line = get_next_line(fd);
        i++;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    so_long *s_long;
    s_long = malloc(sizeof(so_long));
    map_height(s_long, av[1]);
    read_map(s_long, av[1]);
    for (size_t i = 0; i < s_long->map_height; i++)
        printf("%s", s_long->map[i]);
    
   // check_map(s_long, av[1]);
    
    
}