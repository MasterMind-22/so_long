/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:11:20 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 21:18:34 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		s_long->print_move++;
	}
	if (s_long->map[s_long->y_player][s_long->x_player] == 'N')
	{
		ft_putstr("\n\n\t\t\t\033[1;31mGame Over!\033[0m\n\n\n");
		exit(0);
	}
	if (s_long->map[s_long->y_player][s_long->x_player] == 'E'
		&& s_long->c_count == 0)
		return (ft_putstr("\n\n\t\t\t\033[1;32mYou Won!\033[0m\n\n\n"), exit(0));
	else if (s_long->map[s_long->y_player][s_long->x_player] == 'E'
			&& s_long->c_count != 0)
	{
		s_long->x_player -= x;
		s_long->y_player -= y;
	}
}

int	close_mark(int keycode, t_long s_long)
{
	(void)keycode;
	(void)s_long;
	exit(0);
}

int	esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	get_keycode(int keycode, t_long *s_long)
{
	if ((keycode == 2 || keycode == 124)
		&& s_long->map[s_long->y_player][s_long->x_player + 1] != '1')
	{
		s_long->player_left_right = 1;
		move_handler(s_long, 1, 0);
	}
	if ((keycode == 1 || keycode == 125)
		&& s_long->map[s_long->y_player + 1][s_long->x_player] != '1')
	{
		s_long->player_left_right = 2;
		move_handler(s_long, 0, 1);
	}
	if ((keycode == 0 || keycode == 123)
		&& s_long->map[s_long->y_player][s_long->x_player - 1] != '1')
	{
		s_long->player_left_right = 0;
		move_handler(s_long, -1, 0);
	}
	if ((keycode == 13 || keycode == 126)
		&& s_long->map[s_long->y_player - 1][s_long->x_player] != '1')
	{	
		s_long->player_left_right = 4;
		move_handler(s_long, 0, -1);
	}
	return (esc(keycode), 0);
}

int	standing(int keycode, t_long *s_long)
{
	if (keycode == 2 || keycode == 1 || keycode == 0 || keycode == 13
		|| keycode == 124 || keycode == 125 || keycode == 123 || keycode == 126)
		s_long->player_left_right = 5;
	return (0);
}
