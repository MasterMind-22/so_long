/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:11:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 21:36:13 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_right_animation(t_long *s_long, int x, int y)
{
	static int	c;

	if (c == 61)
		c = 0;
	if (c == 10)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/r1.xpm", &x, &y);
	if (c == 20)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/r2.xpm", &x, &y);
	if (c == 30)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/r3.xpm", &x, &y);
	if (c == 40)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/r4.xpm", &x, &y);
	if (c == 50)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/r5.xpm", &x, &y);
	if (c == 60)
		s_long->player_right_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/r6.xpm", &x, &y);
	c++;
	if (!s_long->player_right_img)
		ft_error();
}

void	player_left_animation(t_long *s_long, int x, int y)
{
	static int	c;

	if (c == 51)
		c = 0;
	if (c == 10)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/l1.xpm", &x, &y);
	if (c == 20)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/l2.xpm", &x, &y);
	if (c == 30)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/l3.xpm", &x, &y);
	if (c == 40)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/l4.xpm", &x, &y);
	if (c == 50)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/l5.xpm", &x, &y);
	c++;
	if (!s_long->player_left_img)
		ft_error();
}

void	player_up_animation(t_long *s_long, int x, int y)
{
	static int	c;

	if (c == 51)
		c = 0;
	if (c == 10)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/f1.xpm", &x, &y);
	if (c == 20)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/f2.xpm", &x, &y);
	if (c == 30)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/f3.xpm", &x, &y);
	if (c == 40)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/f4.xpm", &x, &y);
	if (c == 50)
		s_long->player_up_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/f5.xpm", &x, &y);
	c++;
	if (!s_long->player_up_img)
		ft_error();
}

void	player_down_animation(t_long *s_long, int x, int y)
{
	static int	c;

	if (c == 51)
		c = 0;
	if (c == 10)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/d1.xpm", &x, &y);
	if (c == 20)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/d2.xpm", &x, &y);
	if (c == 30)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/d3.xpm", &x, &y);
	if (c == 40)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/d4.xpm", &x, &y);
	if (c == 50)
		s_long->player_down_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/d5.xpm", &x, &y);
	c++;
	if (!s_long->player_down_img)
		ft_error();
}

void	player_stand(t_long *s_long, int x, int y)
{
	static int	c;

	if (c == 51)
		c = 0;
	if (c == 10)
		s_long->player_stand_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/s1.xpm", &x, &y);
	if (c == 20)
		s_long->player_stand_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/s2.xpm", &x, &y);
	if (c == 30)
		s_long->player_stand_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/s3.xpm", &x, &y);
	if (c == 40)
		s_long->player_stand_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/s4.xpm", &x, &y);
	if (c == 50)
		s_long->player_stand_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/s5.xpm", &x, &y);
	c++;
	if (!s_long->player_stand_img)
		ft_error();
}
