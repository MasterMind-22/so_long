#include "so_long.h"

int main(int ac, char **av)
{
    char a[3][4] = {"saoa",
                    "axax",
                    "axax",
                    };
    void	*mlx;
	void	*window;
	void	*img;
    int i = 0;
    int j = 0;

	int x, y ;
    int c = 0;
    int k = 0;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1080, 720, "hello");
    while (a[i])
    {
        while (a[i][j])
    {
	    img = mlx_xpm_file_to_image(mlx,"/home/kali/Downloads/PNG_transparency_demonstration_1.xpm", &x,&y);
	    mlx_put_image_to_window(mlx, window, img, c, k);
        c+=64;
        k+=64;
        j++;
    }
        i++;
    }
	mlx_loop(mlx);
}