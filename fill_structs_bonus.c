/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:17:39 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/21 20:54:37 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void	protect_imgs(t_long *s_long)
{
	if (!s_long->player_right_img || !s_long->player_left_img
		|| !s_long->player_up_img || !s_long->player_down_img
		|| !s_long->door_closed_img || !s_long->door_open_img
		|| !s_long->collectible_img || !s_long->bg_img || !s_long->wall_img)
	{
		ft_putstr("Error\nInvalid resources");
		exit(0);
	}

}

void	xpm_to_img(t_long *s_long)
{
	int	x;
	int	y;

	s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics_bonus/Right (1).xpm", &x, &y);
	s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics_bonus/Left (1).xpm", &x, &y);
	s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics_bonus/Front (1).xpm", &x, &y);
	s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx,
			"./pics_bonus/Left (1).xpm", &x, &y);
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
	protect_imgs(s_long);
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
		mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->door_open_img,
			x, y);
	if (c == 'E' && s_long->c_count != 0)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->door_closed_img, x, y);
	if (c == 'P' && s_long->player_left_right == 1)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->player_right_img, x, y);
	if (c == 'P' && s_long->player_left_right == 0)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->player_left_img, x, y);
	if (c == 'P' && s_long->player_left_right == 2)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->player_down_img, x, y);
	if (c == 'P' && s_long->player_left_right == 4)
		mlx_put_image_to_window(s_long->mlx, s_long->win,
			s_long->player_up_img, x, y);
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
