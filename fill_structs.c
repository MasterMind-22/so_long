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

void print_on_screen(so_long *s_long, on_screen *fill)
{
    int x;
    int y;

    x = 0;
    y = 0;
    s_long->mlx = mlx_init();
	s_long->win = mlx_new_window(s_long->mlx, 60*(s_long->map_width-1), 60*(s_long->map_height), "hello");
	xpm_to_img(fill, s_long->mlx);
	int i = 0;
	int j = 0;
	while (i < s_long->map_height)
	{
		j = 0;
		x = 0;
		while (j < s_long->map_width - 1)
		{
			img_to_window(fill, s_long->mlx, s_long->win, s_long->map[i][j], x, y);
			j++;
			x+=60;
		}
		i++;
    	y+=60;
	}
    mlx_loop(s_long->mlx);

}