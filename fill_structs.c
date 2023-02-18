#include "so_long.h"

void xpm_to_img(on_screen *fill, void *mlx)
{
    int x;
    int y;

    fill->player_img = mlx_xpm_file_to_image(mlx, "./pics/knight.xpm", &x, &y);
        if (!fill->player_img)
            ft_putstr("Error\n");
    fill->wall_img = mlx_xpm_file_to_image(mlx, "./pics/wall.xpm", &x, &y);
        if (!fill->wall_img)
            ft_putstr("Error\n");
    fill->bg_img = mlx_xpm_file_to_image(mlx, "./pics/floor.xpm", &x, &y);
        if (!fill->bg_img)
            ft_putstr("Error\n");
    fill->collectible_img = mlx_xpm_file_to_image(mlx, "./pics/knight.xpm", &x, &y);
        if (!fill->collectible_img)
            ft_putstr("Error\n");
    fill->enemy_img = mlx_xpm_file_to_image(mlx, "./pics/knight.xpm", &x, &y);
        if (!fill->enemy_img)
            ft_putstr("Error\n");
}

void print_on_screen(on_screen *fill, void *mlx, void *window, char c)
{
    int x = 0;
    int y = 0;

    if (c == '0')
        mlx_put_image_to_window(mlx, window, fill->bg_img, x*60, y*60);
    if (c == '1')
        mlx_put_image_to_window(mlx, window, fill->wall_img, x*60, y*60);
    if (c == 'P')
        mlx_put_image_to_window(mlx, window, fill->player_img, x*60, y*60);
    if (c == 'E')
        mlx_put_image_to_window(mlx, window, fill->enemy_img, x*60, y*60);
    if (c == 'C')
        mlx_put_image_to_window(mlx, window, fill->collectible_img, x*60, y*60);
}