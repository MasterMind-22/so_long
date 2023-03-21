/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:52:19 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/20 17:05:16 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_handler(t_long *s_long, int x, int y)
{
	s_long->x_player += x;
	s_long->y_player += y;
	if ((s_long->map[s_long->y_player][s_long->x_player] == '0'
		|| s_long->map[s_long->y_player][s_long->x_player] == 'C'))
	{
		if (s_long->map[s_long->y_player][s_long->x_player] == 'C')
			s_long->c_count--;
		s_long->map[s_long->y_player][s_long->x_player] = 'P';
		s_long->map[s_long->y_player - y][s_long->x_player - x] = '0';
		ft_putnbr(s_long->print_move++);
		ft_putchar('\n');
	}
	if (s_long->map[s_long->y_player][s_long->x_player] == 'E'
		&& s_long->c_count == 0)
		exit(0);
	else if (s_long->map[s_long->y_player][s_long->x_player] == 'E'
			&& s_long->c_count != 0)
	{
		s_long->x_player -= x;
		s_long->y_player -= y;
	}
	print_on_screen(s_long);
}

int	close_mark(int keycode, t_long s_long)
{
	(void)keycode;
	(void)s_long;
	exit(0);
}

int	get_keycode(int keycode, t_long *s_long)
{
	if (keycode == 65307)
		exit(0);
	if ((keycode == 2 || keycode == 124)
		&& s_long->map[s_long->y_player][s_long->x_player + 1] != '1')
	{
		s_long->player_left_right = 1;
		move_handler(s_long, 1, 0);
	}
	if ((keycode == 1 || keycode == 125)
		&& s_long->map[s_long->y_player + 1][s_long->x_player] != '1')
		move_handler(s_long, 0, 1);
	if ((keycode == 0 || keycode == 123)
		&& s_long->map[s_long->y_player][s_long->x_player - 1] != '1')
	{
		s_long->player_left_right = 0;
		move_handler(s_long, -1, 0);
	}
	if ((keycode == 13 || keycode == 126)
		&& (s_long->map[s_long->y_player - 1][s_long->x_player] != '1'))
		move_handler(s_long, 0, -1);
	return (0);
}
