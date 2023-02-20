#include "so_long.h"

int	main(int ac, char **av)
{
	so_long *s_long;

	s_long = malloc(sizeof(so_long));
	check_map(s_long, av[1]);
	read_map(s_long, av[1]);
	// for(int i=0;i<map_height(av[1]);i++)
	// 	printf("%s", s_long->map[i]);










	// for(int i=0;i<map_height(av[1]);i++)
	// 	printf("%s", s_long->backtracking_map[i]);

	// printf("\n\n");
}
