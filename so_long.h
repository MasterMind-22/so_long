#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 10

#include "./mlx_linux/mlx.h"
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include "./get_next_line/get_next_line.h"

typedef struct screen_img{
	char *player_img;
	char *wall_img;
	char *bg_img;
	char *collectible_img;
	char *enemy_img;
} on_screen;

typedef struct too_long{
	char **map;
	char **backtracking_map;
	int map_height;
	int map_width;
	size_t x_player;
	size_t y_player;

} so_long;

size_t map_height(char *av);
size_t map_width(char *av);
void    read_map(so_long *s_long, char *av);
int extension_check(char *av);
int walls_check(char **map, char *av);
int check_elements(char **map, char c);
int check_strange(char **map, char *av);
void ft_putstr(char *str);
void check_map(so_long *s_long, char *av);
int backtrack(char **map,int i, int j);
void fillx(so_long *s_long);
void map_copy(char **s1, char **s2);

#endif