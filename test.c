#include "so_long.h"

void walls_check1(char **map, char *av)
{
    int i;
    int j;

    i=0;
    j=0;
    while (map[i] != NULL)
    {
        j=0;
        while (map[i][j] != '\n')
        {
            if (i == 0 || j == 0 || i == map_height(av) || j == ft_strlen(map[0]))
                printf("%s", map[i]);
            j++;
        }
		printf("\n");
        i++;
    }
}
int	main(int ac, char **av)
{
	so_long *s_long;
	s_long = malloc(sizeof(so_long));

	read_map(s_long, av[1]);
	int i = -1;
	// while (s_long->map[++i])
	// 	printf("%s", s_long->map[i]);
	walls_check1(s_long->map, av[1]);

}
