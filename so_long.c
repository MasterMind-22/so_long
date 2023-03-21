/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:52:21 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/20 17:18:15 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void frame_protect(t_long *s_long, char *av)
{
	if(s_long->map_height * 60 > 1800 || s_long->map_width * 60 > 3200
		|| ft_strcmp(".ber", av + (ft_strlen(av) - 4)) != 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

static void	free_fun1(t_long *s_long)
{
	free_ptr(s_long->map, s_long->map_height);
	mlx_destroy_window(s_long->mlx, s_long->win);
	free(s_long);
	free(s_long->map);
	free(s_long->backtracking_map);
}

int	main(int ac, char **av)
{
	t_long	*s_long;

	s_long = malloc(sizeof(t_long));
	if (ac == 2)
	{
		s_long->print_move = 1;
		read_map(s_long, av[1]);
		frame_protect(s_long, av[1]);
		check_map(s_long, av[1]);
		s_long->mlx = mlx_init();
		s_long->win = mlx_new_window(s_long->mlx, 60 * (s_long->map_width),
				60 * (s_long->map_height), "so_long");
		xpm_to_img(s_long);
		print_on_screen(s_long);
		mlx_hook(s_long->win, 2, 1L << 0, get_keycode, s_long);
		mlx_hook(s_long->win, 17, 1L << 0, close_mark, s_long);
		mlx_loop(s_long->mlx);
		free_fun1(s_long);
	}
	else
		ft_putstr("Error\nPlease input a valid argument");
}
