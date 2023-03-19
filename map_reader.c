/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:51:31 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/19 14:51:51 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *av)
{
	int		map_height;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\nFILE NOT FOUNT");
		exit(0);
	}
	map_height = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (map_height);
}

char	**read_map1(t_long *s_long, char *av)
{
	int		i;
	int		fd;
	char	*read_line;
	char	**backtracking_map;

	i = 0;
	fd = open(av, O_RDONLY);
	s_long->c_count = check_elements(s_long, 'C');
	backtracking_map = (char **)malloc(s_long->map_height * sizeof(char *));
	if (!backtracking_map)
		ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
	read_line = get_next_line(fd);
	while (read_line != NULL)
	{
		backtracking_map[i] = read_line;
		i++;
		read_line = get_next_line(fd);
	}
	close(fd);
	return (backtracking_map);
}

void	read_map(t_long *s_long, char *av)
{
	int		i;
	int		fd;
	char	*read_line;

	i = 0;
	s_long->map_height = map_height(av);
	fd = open(av, O_RDONLY);
	s_long->map = (char **)malloc(s_long->map_height * sizeof(char *));
	if (!s_long->map)
		ft_putstr("Error\nUNABLE TO ALLOCATE MEMORY");
	read_line = get_next_line(fd);
	s_long->map_width = ft_strlen(read_line) - 1;
	while (read_line != NULL)
	{
		s_long->map[i] = read_line;
		i++;
		read_line = get_next_line(fd);
	}
	s_long->backtracking_map = read_map1(s_long, av);
	fillx(s_long);
	close(fd);
}
