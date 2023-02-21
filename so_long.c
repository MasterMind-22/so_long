#include "so_long.h"

int	main(int ac, char **av)
{
	static int x;
    static int y;
	so_long *s_long;
	on_screen *fill;

	s_long = malloc(sizeof(so_long));
	fill = malloc(sizeof(on_screen));
	read_map(s_long, av[1]);
	read_map1(s_long, av[1]);
	//check_map(s_long, av[1]);
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 60*s_long->map_width, 60*s_long->map_height, "hello");
	xpm_to_img(fill, mlx);
	int i = 0;
	int j = 0;
	while (i < s_long->map_height)
	{
		while (s_long->map[i][j])
		{
			print_on_screen(fill, mlx, win, s_long->map[i][j], x , y);
			j++;
		}
		i++;
	}
	

	mlx_loop(mlx);




	// for(int i=0;i<map_height(av[1]);i++)
	// 	printf("%s", s_long->map[i]);
	// printf("\n\n");
	// for(int i=0;i<map_height(av[1]);i++)
	// 	printf("%s", s_long->backtracking_map[i]);

}
