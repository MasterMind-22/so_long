/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:23:13 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/22 20:33:47 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

void	free_ptr(char **map, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(map[i]);
}

void	fillx(t_long *s_long)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (i < s_long->map_height)
	{
		j = 0;
		while (j < s_long->map_width)
		{
			if (s_long->map[i][j] == 'P')
			{
				s_long->x_player = j;
				s_long->y_player = i;
			}
			j++;
		}
		i++;
	}
}

int backtrack(t_long *s_long,char c, int i, int j)
{
	static int x = 0;
	if (s_long->backtracking_map[i][j] == c)
	{
		s_long->a[x] = j;
		s_long->b[x] = i;
		x++;
		return 1;
	}
	if (s_long->backtracking_map[i][j] == '1'
		|| s_long->backtracking_map[i][j] == 'E'
		|| i < 0 || j < 0 || i > s_long->map_height-1 || j > s_long->map_width-1)
		return 0;
	s_long->backtracking_map[i][j] = '1';
	if (backtrack(s_long, c, i, j+1) == 1)
		return 1;
	if (backtrack(s_long, c, i+1, j) == 1)
		return 1;
	if (backtrack(s_long, c, i-1, j) == 1)
		return 1;
	if (backtrack(s_long, c, i, j-1) == 1)
		return 1;
	return 0;
}

void c_backtracking(t_long *s_long, char *av)
{
	int i;

	i = -1;
	s_long->a = (int *)ft_calloc(sizeof(int),s_long->c_count);
	s_long->b = (int *)ft_calloc(sizeof(int),s_long->c_count);
	while (++i < s_long->c_count)
	{
		if (backtrack(s_long, 'C', s_long->y_player, s_long->x_player) != 1)
		{
			ft_putstr("Error\nNo Valid Path to Collectibles");
			exit(0);
		}
			printf("i == %d\tc == %d\n",i, s_long->c_count);
		free_ptr(s_long->backtracking_map, s_long->map_height);
		free(s_long->backtracking_map);
		s_long->backtracking_map = read_map1(s_long, av);
		s_long->k = -1;
		while (++s_long->k <= i)
			s_long->backtracking_map[s_long->b[s_long->k]][s_long->a[s_long->k]] = '0';
	}
}