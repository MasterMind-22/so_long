#include "so_long.h"

void backtrack(so_long *data, char *av)
{
	for (int i = data->x_player; i < map_height(av); i++)
		for (int j = data->y_player; j < map_width(av); j++)
		{
			if (data->map[i][j+1] == '0')
			{
				data->map[i][j+1] = 'P';
				data->map[i][j] = '1';
			}
			if (data->map[i+1][j] == '0')
			{
				data->map[i+1][j] = 'P';
				data->map[i][j] = '1';
			}
		}

	for (int i = 0; i < map_height(av); i++)
		printf("%s", data->map[i]);
}



void fillx(so_long *data, char *av)
{
	for (int i=0; i < map_height(av); i++)
		for (int j=0; j< map_width(av); j++)
		{
			if (data->map[i][j] == 'P')
			{
				data->x_player=i;
				data->y_player=j;
			}
		}
}



int	main(int ac, char **av)
{
	so_long *data;
	data = malloc(sizeof(so_long));
	data->map = read_map(av[1]);
	fillx(data, av[1]);
	backtrack(data, av[1]);
}