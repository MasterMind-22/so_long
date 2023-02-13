#include "so_long.h"
int exit_found(char **map, int x, int y)
{
	int i = 0;
	int j = 0;
	int found = 0;;
	while(map[i][j])
	{
		if (map[i][j] == '0')
	}
}
int	main(int ac, char **av)
{
	so_long data;

	data.map = read_map(av[1]);
	printf("%d\n", check_map_elements(data.map, av[1]));
}