#include "so_long.h"

void fillx(so_long *s_long, char *av)
{
	for (int i=0; i < s_long->map_height; i++)
		for (int j=0; j< s_long->map_height; j++)
		{
			if (s_long->map[i][j] == 'P')
			{
				s_long->y_player=i;
				s_long->x_player=j;
			}
		}
}

int backtrack(char **map,int i, int j)
{
	if (map[i][j] == 'E')
		return 1;
	if (map[i][j] == '1')
		return 0;
	map[i][j] = '1';
	if (backtrack(map, i+1, j) == 1)
		return 1;
	if (backtrack(map, i-1, j) == 1)
		return 1;
	if (backtrack(map, i, j+1) == 1)
		return 1;
	if (backtrack(map, i, j-1) == 1)
		return 1;
	return 0;
}