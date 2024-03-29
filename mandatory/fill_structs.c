/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:01:22 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/19 14:41:30 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_long *s_long)
{
	int	x;
	int	y;

	s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics/player_right.xpm", &x, &y);
	s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics/player_left.xpm", &x, &y);
	s_long->wall_img = mlx_xpm_file_to_image(s_long->mlx, "./pics/wall.xpm", &x,
			&y);
	s_long->bg_img = mlx_xpm_file_to_image(s_long->mlx, "./pics/floor_4.xpm",
			&x, &y);
	s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics/collect.xpm", &x, &y);
	s_long->door_open_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics/open.xpm", &x, &y);
	s_long->door_closed_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics/closed.xpm", &x, &y);
	if (!s_long->door_closed_img || !s_long->door_open_img
		|| !s_long->collectible_img || !s_long->bg_img || !s_long->wall_img
		|| !s_long->player_right_img || !s_long->player_left_img)
	{
		ft_putstr("Error\nInvalid resources");
		exit(0);
	}
}

void	img_to_window(t_long *s_long, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(s_long->mlx,
			s_long->win, s_long->wall_img, x, y);
	else
		mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->bg_img, x, y);
	if (c == 'C')
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->collectible_img, x, y);
	if (c == 'E' && s_long->c_count == 0)
		mlx_put_image_to_window(s_long->mlx,
			s_long->win, s_long->door_open_img, x, y);
	if (c == 'E' && s_long->c_count != 0)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->door_closed_img, x, y);
	if (c == 'P' && s_long->player_left_right == 1)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->player_right_img, x, y);
	if (c == 'P' && s_long->player_left_right == 0)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->player_left_img, x, y);
}

void	print_on_screen(t_long *s_long)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -1;
	y = -1;
	mlx_clear_window(s_long->mlx, s_long->win);
	while (++i < s_long->map_height)
	{
		j = -1;
		x = -60;
		while (++j < s_long->map_width)
			img_to_window(s_long, s_long->map[i][j], x += 60, y);
		y += 60;
	}
}
