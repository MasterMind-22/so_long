#include "so_long.h"

// void *leaks()
// {
// 	system("leaks so_long");
// }
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
	check_map(s_long, av[1]);
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 60*(s_long->map_width-1), 60*(s_long->map_height), "hello");
	xpm_to_img(fill, mlx);
	int i = 0;
	int j = 0;
	while (i < s_long->map_height)
	{
		j = 0;
		x = 0;
		while (j < s_long->map_width - 1)
		{
			img_to_window(fill, mlx, win, s_long->map[i][j], x, y);
			j++;
			x+=60;
		}
		i++;
    	y+=60;
	}
	// int i=-1;
	// while (++i < s_long->map_height)
	// 	printf("%s", s_long->map[i]);

	mlx_loop(mlx);
	// printf("\n\n");
	// for(int i=0;i<map_height(av[1]);i++)
	// 	printf("%s", s_long->backtracking_map[i]);
	//system("leaks so_long");
	return 0;
}
