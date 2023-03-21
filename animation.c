/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:11:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/21 21:03:01 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_right_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 31)
		c = 0;
	if (c == 5)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Right (1).xpm", &x, &y);
	if (c == 10)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Right (2).xpm", &x, &y);
	if (c == 15)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Right (3).xpm", &x, &y);
	if (c == 20)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Right (4).xpm", &x, &y);
	if (c == 25)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Right (5).xpm", &x, &y);
	if (c == 30)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Right (6).xpm", &x, &y);
	c++;
	if (!s_long->player_right_img)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}
void	player_left_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 26)
		c = 0;
	if (c == 5)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Left (1).xpm", &x, &y);
	if (c == 10)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Left (2).xpm", &x, &y);
	if (c == 15)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Left (3).xpm", &x, &y);
	if (c == 20)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Left (4).xpm", &x, &y);
	if (c == 25)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Left (5).xpm", &x, &y);
	c++;
	if (!s_long->player_left_img)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	player_up_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 26)
		c = 0;
	if (c == 5)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Front (1).xpm", &x, &y);
	if (c == 10)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Front (2).xpm", &x, &y);
	if (c == 15)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Front (3).xpm", &x, &y);
	if (c == 20)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Front (4).xpm", &x, &y);
	if (c == 25)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Front (5).xpm", &x, &y);
	c++;
	if (!s_long->player_up_img)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	player_down_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 26)
		c = 0;
	if (c == 5)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Down (1).xpm", &x, &y);
	if (c == 10)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Down (2).xpm", &x, &y);
	if (c == 15)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Down (3).xpm", &x, &y);
	if (c == 20)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Down (4).xpm", &x, &y);
	if (c == 25)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Down (5).xpm", &x, &y);
	c++;
	if (!s_long->player_down_img)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

int animation(t_long *s_long, int x, int y)
{
	player_right_animation(s_long, x, y);
	player_left_animation(s_long, x, y);
	player_up_animation(s_long, x, y);
	player_down_animation(s_long, x, y);
	print_on_screen(s_long);
	char *move = ft_itoa(s_long->print_move);
	mlx_string_put(s_long->mlx, s_long->win, 0, 0, 0xFFFFFF, move);
	return(free(move), 0);
}