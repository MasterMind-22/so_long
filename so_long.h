#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 10


#include<stdio.h>
#include<unistd.h>
#include<string.h>
# include<fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct too_long
{
	char **map;
	char **map_copy;
	int map_lenth;
	int map_width;
} so_long;


#endif