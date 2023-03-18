#include "so_long.h"

static void	free_fun1(so_long *s_long)
{
	free_ptr(s_long->map, s_long->map_height);
	mlx_destroy_window(s_long->mlx, s_long->win);
	free(s_long);
	free(s_long->map);
	free(s_long->backtracking_map);
}

int	main(int ac, char **av)
{
	so_long *s_long;

	s_long = malloc(sizeof(so_long));
	if (ac == 2)
	{
		if (ft_strcmp(".ber", av[1]+(ft_strlen(av[1])-4)) != 0)
		{
			ft_putstr("Error\nInavlid Extension");
			exit(0);
		}
		s_long->print_move = 1;
		read_map(s_long, av[1]);
		s_long->backtracking_map = read_map1(s_long, av[1]);
		check_map(s_long, av[1]);
		s_long->mlx = mlx_init();
		s_long->win = mlx_new_window(s_long->mlx, 60*(s_long->map_width), 60*(s_long->map_height), "so_long");
		xpm_to_img(s_long);
		print_on_screen(s_long);
		mlx_hook(s_long->win, 2, 1L<<0, get_keycode, s_long);
		mlx_hook(s_long->win, 17, 1L<<0, close_mark, s_long);
		mlx_loop(s_long->mlx);
		free_ptr(s_long->map, s_long->map_height);
		mlx_destroy_window(s_long->mlx, s_long->win);
		free_fun1(s_long);
	}
	else
		ft_putstr("Error\nPlease input a valid argument");
}
