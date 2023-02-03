#include <mlx.h>
#include "so_long.h"


int	main(void)
{
    void *mlx;
    void *window;
    void  *img;
    int x, y;


    mlx = mlx_init();
    window = mlx_new_window(mlx, 640, 480, "hello");
    img = mlx_xpm_file_to_image(mlx, "/home/kali/Downloads/PNG_transparency_demonstration_1.xpm", &x, &y);
    mlx_put_image_to_window(mlx, window, img, 0, 0);
    mlx_loop(mlx);
    
}

