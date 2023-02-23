#include "so_long.h"

// void *leaks()
// {
// 	system("leaks so_long");
// }

int	main(int ac, char **av)
{
	// atexit(leaks());
	int x;
    int y;
	so_long *s_long;
	on_screen *fill;

	s_long = malloc(sizeof(so_long));
	fill = malloc(sizeof(on_screen));
	read_map(s_long, av[1]);
	read_map1(s_long, av[1]);
	check_map(s_long, av[1]);
	print_on_screen(s_long, fill);
	// printf("%d\n", s_long->c_count);




	// for (int i=0;i<s_long->map_height;i++)
	// 	printf("%s", s_long->map[i]);
	// printf("\n\n");
	// for(int i=0;i<map_height(av[1]);i++)
	// 	printf("%s", s_long->backtracking_map[i]);
	// system("leaks so_long");
	return 0;
}
