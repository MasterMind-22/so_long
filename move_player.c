#include "so_long.h"


void move_handler(so_long *s_long, int key_pressed)
{
	if (key_pressed == 2)
	{
		if (s_long->map[s_long->x_player][s_long->y_player+1] == '0')
		{
			s_long->map[s_long->x_player][s_long->y_player] = '0';
			s_long->map[s_long->x_player][s_long->y_player+1] = 'P';

		}
	}
	
}

int get_keycode(int keycode, so_long so_long)
{

	move_handler(&so_long, keycode);
	return 0;
}