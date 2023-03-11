#include "so_long.h"

void move_handler(so_long *s_long, int x, int y)
{
	if (s_long->map[s_long->y_player+y][s_long->x_player+x] == 'E'
		&& s_long->c_count == 0)
		exit(0);
	if ((s_long->map[s_long->y_player+y][s_long->x_player+x] == '0'
		|| s_long->map[s_long->y_player+y][s_long->x_player+x] == 'C'))
	{
		if (s_long->map[s_long->y_player+y][s_long->x_player+x] == 'C')
			s_long->c_count--;
		s_long->map[s_long->y_player+y][s_long->x_player+x] = 'P';
		s_long->map[s_long->y_player][s_long->x_player] = '0';
	}
	s_long->x_player+=x;
	s_long->y_player+=y;
	ft_putnbr(s_long->print_move++);
	ft_putchar('\n');
}

int close_mark(int keycode, so_long s_long)
{
	(void) keycode;
	(void) s_long;
	exit(0);
}

int get_keycode(int keycode, so_long *s_long)
{
	if (keycode == 65307) // close mark
		exit(0);
	if ((keycode == 100 || keycode == 124)
		&& s_long->map[s_long->y_player][s_long->x_player+1] != '1') //D == Imac : 2 - Linux : 100
	{
		s_long->player_left_right = 1;
		move_handler(s_long, 1, 0);
	}
	if ((keycode == 115 || keycode == 125)
		&& s_long->map[s_long->y_player+1][s_long->x_player] != '1') // S == Imac : 1 - Linux : 115
		move_handler(s_long, 0, 1);
	if ((keycode == 97 || keycode == 123)
		&& s_long->map[s_long->y_player][s_long->x_player-1] != '1') // A == Imac : 0 - Linux : 97
	{
		s_long->player_left_right = 0;
		move_handler(s_long, -1, 0);
	}
	if ((keycode == 119 || keycode == 126)
		&& s_long->map[s_long->y_player-1][s_long->x_player] != '1') // W == Imac : 13 - Linux : 119
		move_handler(s_long, 0, -1);
	print_on_screen(s_long);
	return 0;
}