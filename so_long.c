#include "so_long.h"

int	main(int ac, char **av)
{
	so_long *s_long;

	s_long = malloc(sizeof(so_long));
	read_map(s_long, av[1]);
	check_map(s_long, av[1]);
	for(int i=0;i<map_height(av[1]);i++)
		printf("%s", s_long->map[i]);









	printf("\n\n");

	for(int i=0;i<map_height(av[1]);i++)
		printf("%s", s_long->backtracking_map[i]);

}
