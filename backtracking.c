#include "so_long.h"

void fillx(so_long *s_long)
{
	for (int i=0; i < s_long->map_height; i++)
		for (int j=0; j< s_long->map_width; j++)
		{
			if (s_long->map[i][j] == 'P')
			{
				s_long->x_player=j;
				s_long->y_player=i;
			}
		}
}

int backtrack(so_long *s_long,char c, int i, int j)
{
	static int x = 0;
	if (s_long->backtracking_map[i][j] == c)
	{
		s_long->a[x] = j;
		s_long->b[x] = i;
		x++;
		return 1;
	}
	if (s_long->backtracking_map[i][j] == '1')
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

void c_backtracking(so_long *s_long, char *av)
{
	int i;

	i = -1;
	s_long->a = (int *)malloc(sizeof(int)*s_long->c_count);
	s_long->b = (int *)malloc(sizeof(int)*s_long->c_count);
	while (++i < s_long->c_count)
	{
		if (backtrack(s_long, 'C', s_long->x_player, s_long->y_player) != 1
			&& i < s_long->c_count)
		{
			ft_putstr("Error\nNo Valid Path to Collectibles");
			exit(0);
		}
		read_map1(s_long, av);
		s_long->k = -1;
		while (++s_long->k < i+1)
			s_long->backtracking_map[s_long->b[s_long->k]][s_long->a[s_long->k]] = '0';
	}
}