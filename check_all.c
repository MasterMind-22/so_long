#include "so_long.h"

void check_map(so_long *s_long, char *av)
{
    if (extension_check(av) != 0)
    {
        ft_putstr("Error\nINVALID FILE EXTENSION!");
        exit(0);
    }
    if (walls_check(s_long->map, av) != 0)
    {
        ft_putstr("Error\nTHE MAP MUST BE CLOSED/SURROUNDED BY WALLS!");
        exit(0);
    }
    if (check_strange(s_long->map, av) == 0)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN ONLY THE ELEMENTS \"ECP01\"!");
        exit(0);
    }
    if (check_elements(s_long->map, 'E', av) != 1)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN 1 EXIT!");
        exit(0);
    }
    if (check_elements(s_long->map, 'P', av) != 1)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN 1 PLAYER!");
        exit(0);
    }
    if (check_elements(s_long->map, 'C', av) < 1)
    {
        ft_putstr("Error\nTHE MAP MUST CONTAIN 1 OR MORE COLLECTIBLES!");
        exit(0);
    }

    if (backtrack(s_long, s_long->x_player, s_long->y_player) != 1)
    {
        ft_putstr("Error\nNO VALID PATH TO EXIT!");
        exit(0);
    }

}