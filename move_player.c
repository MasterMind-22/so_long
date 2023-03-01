#include "so_long.h"


void move_handler(so_long *s_long)
{	
	s_long->x_player++;
	printf("x_player = %d\t y_player = %d\n", s_long->x_player, s_long->y_player);
	printf("x_win = %d\t y_win = %d\n", s_long->x_win, s_long->y_win);
	if ((s_long->map[s_long->y_player][s_long->x_player] == '0'
		|| s_long->map[s_long->y_player][s_long->x_player] == 'C') && s_long->map[s_long->y_player][s_long->x_player] != '1')
	{
		s_long->map[s_long->y_player][s_long->x_player-1] = '0';
		s_long->map[s_long->y_player][s_long->x_player] = 'P';
		for (int i=0;i<s_long->map_height-1;i++)
			printf("%s", s_long->map[i]);
		// print_on_screen(s_long);
	}
}

int get_keycode(int keycode, so_long *s_long)
{
	s_long->x_win = s_long->x_player * 64;
	s_long->y_win = s_long->y_player * 64;
	if (keycode == 2)
		move_handler(s_long);
	return 0;
}
