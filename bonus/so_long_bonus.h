/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:54:49 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 16:42:07 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mandatory/get_next_line.h"
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

	void	*wall_img;
	void	*bg_img;
	void	*collectible_img;
	void	*door_closed_img;
	void	*player_right_img;
	void	*player_left_img;
	void	*player_up_img;
	void	*player_down_img;
	void	*door_open_img;
	void	*player_stand_img;
	void	*ni;
	int		*a;
	int		*b;
	int		k;
	int		fd;

}	t_long;

void		ft_error(void);
int			animation(t_long *s_long, int x, int y);
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
int			standing(int keycode, t_long *s_long);
void		player_stand(t_long *s_long, int x, int y);
void		player_down_animation(t_long *s_long, int x, int y);
void		player_up_animation(t_long *s_long, int x, int y);
void		player_left_animation(t_long *s_long, int x, int y);
void		player_right_animation(t_long *s_long, int x, int y);
void		enemy_pos_change(t_long *s_long);

#endif