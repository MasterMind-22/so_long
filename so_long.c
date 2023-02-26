#include "so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;


int	key_hook(int keycode, so_long s_long)
{
	printf("%d\n", keycode);
    return 0;
}

int	main(int ac, char **av)
{
	so_long *s_long;

	s_long = malloc(sizeof(so_long));

	printf("%d\n", getpid());
	read_map(s_long, av[1]);
	read_map1(s_long, av[1]);
	check_map(s_long, av[1]);
	s_long->mlx = mlx_init();
	s_long->win = mlx_new_window(s_long->mlx, 60*(s_long->map_width-1), 60*(s_long->map_height), "hello");
	print_on_screen(s_long);
	mlx_hook(s_long->win, 2, 1L<<0, get_keycode, &s_long);
	mlx_loop(s_long->mlx);
	return 0;
}
