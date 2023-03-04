#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 10

#include <mlx.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include "./get_next_line/get_next_line.h"

typedef struct m_checker{
	int count_player;
	int count_ones;
	int count_zeros;
	int count_exit;
	int count_collect;
} map_checker;

typedef struct too_long{
	char **map;
	char **backtracking_map;
	int map_height;
	int map_width;
	int c_count;
	int player_left_right;
	int print_move;

	// Player Position
	int x_player;
	int y_player;

	// Mlx Pointers
	void *win;
	void *mlx;

	// Img Resources
	char *wall_img;
	char *bg_img;
	char *player_left_img;
	char *collectible_img;
	char *door_closed_img;
	char *player_right_img;
	char *door_open_img;

} so_long;

int		map_height(char *av);
int		map_width(char *av);
void    read_map(so_long *s_long, char *av);
void    read_map1(so_long *s_long, char *av);
void	extension_check(char *av);
int		walls_check(char **map, char *av);
int		check_elements(char **map, char c, char *av);
int		check_strange(char **map, char *av);
void	ft_putstr(char *str);
void	check_map(so_long *s_long, char *av);
int		backtrack(so_long *s_long, int i, int j);
void	fillx(so_long *s_long);
void	xpm_to_img(so_long *s_long);
void	img_to_window(so_long *s_long, char c, int x, int y);
int		get_keycode(int keycode, so_long *s_long);
void	print_on_screen(so_long *s_long);
int close_mark(int keycode, so_long s_long);
int count_char_int_line(char *str, int c);

#endif