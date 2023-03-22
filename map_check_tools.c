/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:14:06 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/22 18:11:05 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char_int_line(char *str, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			count++;
		i++;
	}
	return (count);
}

int	walls_check(t_long *s_long)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	while (i < s_long->map_height)
	{
		j = 0;
		while (j < s_long->map_width)
		{
			if (s_long->map[i][j] != '1' && (i == 0 || j == 0
					|| i == s_long->map_height - 1 || j == s_long->map_width
					- 1))
			{
				result++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int	check_elements(t_long *s_long, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < s_long->map_height)
	{
		count += count_char_int_line(s_long->map[i], c);
		i++;
	}
	return (count);
}

int	check_strange(t_long *s_long)
{
	int		i;
	int		count;
	char	*elements;

	i = 0;
	count = 0;
	elements = "01ECP";
	while (elements[i])
	{
		count += check_elements(s_long, elements[i]);
		i++;
	}
	if (count == s_long->map_height * (s_long->map_width))
		return (1);
	return (0);
}

void	check_len(t_long *s_long)
{
	int	i;

	i = s_long->map_height;
	if (s_long->map_width != ft_strlen(s_long->map[i - 1])
	 || s_long->map_height == s_long->map_width)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	while (i - 2 >= 0)
	{
		if (s_long->map_width != ft_strlen(s_long->map[i - 2]) - 1)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		i--;
	}
}
