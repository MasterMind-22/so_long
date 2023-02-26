#include "so_long.h"

void fillx(so_long *s_long)
{
	for (int i=0; i < s_long->map_height; i++)
		for (int j=0; j< s_long->map_height; j++)
		{
			if (s_long->map[i][j] == 'P')
			{
				s_long->x_player=i;
				s_long->y_player=j;
			}
		}
}

int backtrack(so_long *s_long, int i, int j)
{
	if (s_long->backtracking_map[i][j] == 'E')
		return 1;
	if (s_long->backtracking_map[i][j] == '1')
		return 0;
	s_long->backtracking_map[i][j] = '1';
	if (backtrack(s_long, i+1, j) == 1)
		return 1;
	if (backtrack(s_long, i-1, j) == 1)
		return 1;
	if (backtrack(s_long, i, j+1) == 1)
		return 1;
	if (backtrack(s_long, i, j-1) == 1)
		return 1;
	return 0;
}
