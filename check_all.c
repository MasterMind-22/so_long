#include "so_long.h"

void check_map(char **map, char *av)
{
    if (extension_check(av) != 0)
    {
        ft_putstr("Error\nINVALID FILE EXTENSION!");
        exit(0);
    }
    if (walls_check(map, av) != 0)
    {
        ft_putstr("Error\nTHE MAP MUST BE CLOSED/SURROUNDED BY WALLS!");
        exit(0);
    }
    if (check_strange(map, av) == 0)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN ONLY THE ELEMENTS \"ECP01\"!");
        exit(0);
    }
    if (check_elements(map, 'E') != 1)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN 1 EXIT!");
        exit(0);
    }
    if (check_elements(map, 'P') != 1)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN 1 PLAYER!");
        exit(0);
    }
    if (check_elements(map, 'C') < 1)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN 1 OR MORE COLLECTIBLES!");
        exit(0);
    }
}