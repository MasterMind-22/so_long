#include "so_long.h"

int	main(int ac, char **av)
{
	char **a = read_map(av[1]);
	check_map(a, av[1]);
	//check_leaks();
	//system("a.out" leaks);
}
