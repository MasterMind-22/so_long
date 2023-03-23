/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:05:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 21:19:34 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_n_mv(t_long *s_long, int i, int j)
{
	int	x;
	int	y;
	int	z;

	if (s_long->map[i][j] == 'N')
	{
		x = rand() % 3 - 1;
		y = rand() % 3 - 1 ;
		z = rand() % 2;
		if (z)
			x = 0;
		else
			y = 0;
		if (s_long->map[i + y][j + x] == '0')
		{
			s_long->map[i][j] = '0';
			s_long->map[i + y][j + x] = 'N';
			i += y;
			j += x;
		}
		else if (s_long->map[i + y][j + x] == 'P')
			return (ft_putstr("\n\n\t\t\t\033[1;31mGame Over!\033[0m\n\n\n"), exit(0));
		else
			return ;
	}
}

void	enemy_pos_change(t_long *s_long)
{
	static int	n;
	int			i;
	int			j;

	i = -1;
	while (++i < s_long->map_height)
	{
		j = -1;
		while (++j < s_long->map_width)
		{
			if (s_long->map[i][j] == 'N')
			{
				if (n == 20)
					n = 0;
				if (n == 10)
					check_n_mv(s_long, i, j);
				n++;
			}
		}
	}
}
