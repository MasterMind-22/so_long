#include "so_long.h"


int main(int ac, char **av)
{
    char *map = "111111111111111111111111111111110";
    int x, y;
    void *mlx = mlx_init();
    void *window = mlx_new_window(mlx, 60*15, 60*6, "hello");
    void *img_6 = mlx_xpm_file_to_image(mlx, "./pics/floor_4.xpm", &x, &y);
    void *img_7 = mlx_xpm_file_to_image(mlx, "./pics/wall.xpm", &x, &y);
    int i =0; int j=0;
    while(map[i++]){

            mlx_put_image_to_window(mlx, window, img_7, i*60, j*60);
            mlx_put_image_to_window(mlx, window, img_6, i*60, j*60);
        }
    mlx_loop(mlx);
    mlx_destroy_window(mlx, window);
}