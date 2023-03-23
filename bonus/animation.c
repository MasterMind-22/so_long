/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:59:12 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 17:14:29 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect_animation(t_long *s_long, int x, int y)
{
	static int	c;

	if (c == 31)
		c = 0;
	if (c == 5)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/c1.xpm", &x, &y);
	if (c == 10)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/c2.xpm", &x, &y);
	if (c == 15)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/c3.xpm", &x, &y);
	if (c == 20)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/c4.xpm", &x, &y);
	if (c == 25)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/c5.xpm", &x, &y);
	if (c == 30)
		s_long->collectible_img = mlx_xpm_file_to_image(s_long->mlx,
				"./p_bonus/c6.xpm", &x, &y);
	c++;
	if (!s_long->collectible_img)
		ft_error();
}

int	animation(t_long *s_long, int x, int y)
{
	char	*move;

	player_stand(s_long, x, y);
	player_right_animation(s_long, x, y);
	player_left_animation(s_long, x, y);
	player_up_animation(s_long, x, y);
	player_down_animation(s_long, x, y);
	enemy_pos_change(s_long);
	collect_animation(s_long, x, y);
	print_on_screen(s_long);
	move = ft_itoa(s_long->print_move);
	mlx_string_put(s_long->mlx, s_long->win, 0, 0, 0xFFFFFF, move);
	return (free(move), 0);
}
