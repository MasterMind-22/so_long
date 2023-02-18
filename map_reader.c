#include "so_long.h"

int map_height(char *av)
{
    int fd;
    char *line;
    int map_height;

    fd = open(av, O_RDONLY);
    line = get_next_line(fd);
    map_height = 0;
    while (line)
    {
        map_height++;
        line = get_next_line(fd);
    }
    free(line);
    return(map_height);
}
int map_width(char *av)
{
    int fd;
    char *line;

    fd = open(av, O_RDONLY);
    line = get_next_line(fd);
    return(ft_strlen(line));
}

char **read_map(char *av)
{
    int fd;
    char *read_line;
    int i = 0;
    char **map;

    fd = open(av, O_RDONLY);
    map = malloc (map_height(av) * sizeof(char *));
    read_line = get_next_line(fd);
    while (read_line)
    {
        map[i] = read_line;
        read_line = get_next_line(fd);
        i++;
    }
    return(map);
}

int main(int ac, char **av)
{
    (void)ac;
    on_screen *fill;
    char **map;
    map = read_map(av[1]);
    void *mlx = mlx_init();
    int x = map_height(av[1]);
    int y = map_width(av[1]);

    void *window = mlx_new_window(mlx, x*=60, y*=60, "WINDOW");
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
        print_on_screen(fill, mlx, window, map[i][j]);
    mlx_loop(mlx);
}