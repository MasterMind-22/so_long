/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:20:32 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/20 18:25:36 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_1(t_long *s_long)
{
	check_len(s_long);
	if (walls_check(s_long) != 0)
	{
		ft_putstr("Error\nTHE MAP MUST BE CLOSED/SURROUNDED BY WALLS!");
		exit(0);
	}
	if (check_strange(s_long) == 0)
	{
		ft_putstr("Error\nTHE MAP MUST CONTAIN ONLY THE ELEMENTS \"ECP01\"!");
		exit(0);
	}
	if (check_elements(s_long, 'P') != 1)
	{
		ft_putstr("Error\nTHE MAP MUST CONTAIN 1 PLAYER!");
		exit(0);
	}
}

void	check_map(t_long *s_long, char *av)
{
	check_1(s_long);
	if (check_elements(s_long, 'E') != 1)
	{
		ft_putstr("Error\nTHE MAP MUST CONTAIN 1 EXIT!");
		exit(0);
	}
	if (check_elements(s_long, 'C') < 1)
	{
		ft_putstr("Error\nTHE MAP MUST CONTAIN 1 OR MORE COLLECTIBLES!");
		exit(0);
	}
	c_backtracking(s_long, av);
	if (backtrack(s_long, 'E', s_long->y_player, s_long->x_player) != 1)
	{
		ft_putstr("Error\nNO VALID PATH TO EXIT!");
		exit(0);
	}
}
