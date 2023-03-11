#include "so_long.h"

// int key(int keycode, so_long *s_long)
// {
// 	// (void)s_long;
// 	printf("%d\n", keycode);
// }
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		// if (ft_strcmp(".ber", av[1]+(ft_strlen(av[1])-4)) != 0)
		// {
		// 	ft_putstr("Error\nInavlid Extension");
		// 	exit(0);
		// }
		so_long *s_long;

		s_long = malloc(sizeof(so_long));
		s_long->print_move = 1;
		read_map(s_long, av[1]);
		read_map1(s_long, av[1]);
		check_map(s_long, av[1]);
		s_long->mlx = mlx_init();
		s_long->win = mlx_new_window(s_long->mlx, 60*(s_long->map_width), 60*(s_long->map_height), "so_long");
		print_on_screen(s_long);
		mlx_hook(s_long->win, 2, 1L<<0, get_keycode, s_long);
		mlx_hook(s_long->win, 17, 1L<<0, close_mark, s_long);
		mlx_loop(s_long->mlx);
	}
	else
		ft_putstr("Error\nPlease input a valid argument");
	return 0;
}
