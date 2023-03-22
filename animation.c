/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:11:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/22 19:06:30 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_right_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 31)
		c = 0;
	if (c == 5)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/r1.xpm", &x, &y);
	if (c == 10)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/r2.xpm", &x, &y);
	if (c == 15)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/r3.xpm", &x, &y);
	if (c == 20)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/r4.xpm", &x, &y);
	if (c == 25)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/r5.xpm", &x, &y);
	if (c == 30)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/r6.xpm", &x, &y);
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
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/l1.xpm", &x, &y);
	if (c == 10)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/l2.xpm", &x, &y);
	if (c == 15)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/l3.xpm", &x, &y);
	if (c == 20)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/l4.xpm", &x, &y);
	if (c == 25)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/l5.xpm", &x, &y);
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
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/f1.xpm", &x, &y);
	if (c == 10)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/f2.xpm", &x, &y);
	if (c == 15)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/f3.xpm", &x, &y);
	if (c == 20)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/f4.xpm", &x, &y);
	if (c == 25)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/f5.xpm", &x, &y);
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
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/d1.xpm", &x, &y);
	if (c == 10)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/d2.xpm", &x, &y);
	if (c == 15)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/d3.xpm", &x, &y);
	if (c == 20)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/d4.xpm", &x, &y);
	if (c == 25)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/d5.xpm", &x, &y);
	c++;
	if (!s_long->player_down_img)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	collect_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 31)
		c = 0;
	if (c == 5)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/c1.xpm", &x, &y);
	if (c == 10)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/c2.xpm", &x, &y);
	if (c == 15)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/c3.xpm", &x, &y);
	if (c == 20)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/c4.xpm", &x, &y);
	if (c == 25)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/c5.xpm", &x, &y);
	if (c == 30)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/c6.xpm", &x, &y);
	c++;
	if (!s_long->collectible_img)
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
	collect_animation(s_long, x, y);
	print_on_screen(s_long);
	char *move = ft_itoa(s_long->print_move);
	mlx_string_put(s_long->mlx, s_long->win, 0, 0, 0xFFFFFF, move);
	return(free(move), 0);
}