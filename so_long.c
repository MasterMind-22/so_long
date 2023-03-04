#include "so_long.h"

int	key_hook(int keycode, so_long s_long)
{
	printf("%d\n", keycode);
    return 0;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		// check extension
		so_long *s_long;

		s_long = malloc(sizeof(so_long));
		s_long->print_move = 1;
		read_map(s_long, av[1]);
		read_map1(s_long, av[1]);
		check_map(s_long, av[1]);
		s_long->mlx = mlx_init();
		s_long->win = mlx_new_window(s_long->mlx, 60*(s_long->map_width-1), 60*(s_long->map_height), "hello");
		print_on_screen(s_long);
		//mlx_string_put(s_long->mlx, s_long->win, 0, 0, 0x78f000, "hello");
		mlx_hook(s_long->win, 2, 1L<<0, get_keycode, s_long);
		mlx_hook(s_long->win, 17, 1L<<0, close_mark, s_long);
		mlx_loop(s_long->mlx);
	}
	else
		ft_putstr("Error\nPlease input a valid argument");
	return 0;
}
