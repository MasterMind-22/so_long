#include "so_long.h"

void fillx(so_long *data, char *av)
{
	for (int i=0; i < map_height(av); i++)
		for (int j=0; j< map_width(av); j++)
		{
			if (data->map[i][j] == 'P')
			{
				data->y_player=i;
				data->x_player=j;
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

int	main(int ac, char **av)
{
	so_long *a;
	a = malloc(sizeof(so_long));
	a->map = read_map(av[1]);
	fillx(a, av[1]);
	int f = backtrack(a->map, a->x_player, a->y_player);
	printf("\n%d\n", f);
}