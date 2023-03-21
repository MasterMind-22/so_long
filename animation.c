/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:11:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/20 19:07:20 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	player_animation(t_long *s_long, int x, int y)
{
	static int c;

	if (c == 11)
		c = 0;
	if (c == 5)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics_bonus/Walk (1).xpm", &x, &y);
	if (c == 10)
		s_long->player_left_img = mlx_xpm_file_to_image(s_long->mlx, "./pics/open.xpm", &x, &y);
	c++;
	
	print_on_screen(s_long);
	char *move = ft_itoa(s_long->print_move);
	mlx_string_put(s_long->mlx, s_long->win, 0, 0, 0xFFFFFF, move);
	return(free(move), 0);
}
