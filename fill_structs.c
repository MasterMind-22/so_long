#include "so_long.h"

void xpm_to_img(on_screen *fill, void *mlx)
{
    int x;
    int y;

    fill->player_img = mlx_xpm_file_to_image(mlx, "./pics/knight.xpm", &x, &y);
        if (!fill->player_img)
            ft_putstr("1\n");
    fill->wall_img = mlx_xpm_file_to_image(mlx, "./pics/wall.xpm", &x, &y);
        if (!fill->wall_img)
            ft_putstr("2\n");
    fill->bg_img = mlx_xpm_file_to_image(mlx, "./pics/floor_4.xpm", &x, &y);
        if (!fill->bg_img)
            ft_putstr("3\n");
    fill->collectible_img = mlx_xpm_file_to_image(mlx, "./pics/collect.xpm", &x, &y);
        if (!fill->collectible_img)
            ft_putstr("4\n");
    fill->door_open_img = mlx_xpm_file_to_image(mlx, "./pics/open.xpm", &x, &y);
        if (!fill->collectible_img)
            ft_putstr("4\n");
    fill->door_closed_img = mlx_xpm_file_to_image(mlx, "./pics/closed.xpm", &x, &y);
    if (!fill->door_closed_img || !fill->door_open_img || !fill->collectible_img
            || !fill->bg_img || !fill->wall_img || !fill->player_img )
    {
        ft_putstr("Error\nInvalid resources");
        exit(0);
    }
}

void img_to_window(on_screen *fill, void *mlx, void *window, char c, int x, int y)
{
    if (c == '1')
        mlx_put_image_to_window(mlx, window, fill->wall_img, x, y);
    else
        mlx_put_image_to_window(mlx, window, fill->bg_img, x, y);
    if (c == 'P')
        mlx_put_image_to_window(mlx, window, fill->player_img, x, y);
    if (c == 'E')
        mlx_put_image_to_window(mlx, window, fill->door_open_img, x, y);
    if (c == 'C')
        mlx_put_image_to_window(mlx, window, fill->collectible_img, x, y);
}

// void print_on_screen(char *line, void *mlx, void *win, on_screen *fill)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     while ()

// }