#include "so_long.h"

int	main(int ac, char **av)
{
	void *mlx;
	mlx = mlx_init();
	void *win;
	win = mlx_new_window(mlx, 1800, 1000, "hello");

	mlx_loop(mlx);


}
