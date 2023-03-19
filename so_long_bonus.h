/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:54:49 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/19 16:28:40 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./get_next_line/get_next_line.h"
# include<mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct so_long
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

	char	*wall_img;
	char	*bg_img;
	char	*player_left_img;
	char	*collectible_img;
	char	*door_closed_img;
	char	*player_right_img;
	char	*door_open_img;
	int		*a;
	int		*b;
	int		k;
	int		fd;

}	t_long;

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
char		*ft_itoa(int n);

#endif