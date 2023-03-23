/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:59:52 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 16:25:58 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct too_long
{
	char	**map;
	char	**backtracking_map;
	int		map_height;
	int		map_width;
	int		c_count;
	int		player_left_right;
	int		print_move;

	int		x_player;
	int		y_player;

	void	*win;
	void	*mlx;

	void	*wall_img;
	void	*bg_img;
	void	*player_left_img;
	void	*collectible_img;
	void	*door_closed_img;
	void	*player_right_img;
	void	*door_open_img;
	int		*a;
	int		*b;
	int		k;
	int		fd;
	int		is_bonus;

}			t_long;

void		ft_putnbr_fd(int n);
int			map_height(char *av);
void		read_map(t_long *s_long, char *av);
char		**read_map1(t_long *s_long, char *av);
void		extension_check(char *av);
int			walls_check(t_long *s_long);
int			check_elements(t_long *s_long, char c);
int			check_strange(t_long *s_long);
void		ft_putstr(char *str);
void		check_map(t_long *s_long, char *av);
int			backtrack(t_long *s_long, char c, int i, int j);
void		fillx(t_long *s_long);
void		xpm_to_img(t_long *s_long);
void		img_to_window(t_long *s_long, char c, int x, int y);
int			get_keycode(int keycode, t_long *s_long);
void		print_on_screen(t_long *s_long);
int			close_mark(int keycode, t_long s_long);
int			count_char_int_line(char *str, int c);
int			ft_strcmp(const char *s1, const char *s2);
void		c_backtracking(t_long *s_long, char *av);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		free_ptr(char **map, int len);
void		check_len(t_long *s_long);

#endif