/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:44:11 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/23 14:32:52 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(int fd, char *read_line)
{
	int		read_int;
	char	*from_read;

	read_int = 1;
	from_read = malloc(BUFFER_SIZE + 1);
	if (!from_read)
		return (NULL);
	while (newline_found(read_line) && read_int)
	{
		read_int = read(fd, from_read, BUFFER_SIZE);
		if (read_int == -1 || (read_int == 0 && !read_line))
			return (free(from_read), free(read_line),
				ft_putstr("Error\n"), exit(0), NULL);
		from_read[read_int] = '\0';
		read_line = ft_strjoin(read_line, from_read);
	}
	free(from_read);
	if (read_line[0] == '\0')
	{
		free(read_line);
		return (NULL);
	}
	return (read_line);
}

char	*return_line_f(char *read_line)
{
	int		i;
	char	*return_line;

	i = -1;
	while (read_line[++i])
	{
		if (read_line[i] == '\n')
		{
			i++;
			break ;
		}
	}
	return_line = (char *)malloc((i + 1) * sizeof(char));
	if (!return_line)
		return (NULL);
	i = -1;
	while (read_line[++i] && read_line[i] != '\n')
		return_line[i] = read_line[i];
	if (read_line[i] == '\n')
	{
		return_line[i] = '\n';
		i++;
	}
	return_line[i] = '\0';
	return (return_line);
}

char	*save_line_f(char *read_line)
{
	int		i;
	char	*save_line;
	int		j;

	j = 0;
	i = -1;
	while (read_line[++i])
	{
		if (read_line[i] == '\n')
		{
			i++;
			break ;
		}
	}
	save_line = malloc(ft_strlen(&read_line[i]) + 1);
	if (!save_line)
		return (free(read_line), NULL);
	while (read_line[i])
	{
		save_line[j] = read_line[i];
		i++;
		j++;
	}
	save_line[j] = '\0';
	return (free(read_line), save_line);
}

char	*get_next_line(int fd)
{
	char		*return_line;
	static char	*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = read_fd(fd, read_line);
	if (!read_line)
		return (NULL);
	return_line = return_line_f(read_line);
	read_line = save_line_f(read_line);
	return (return_line);
}

// int main(void)
// {
// 	int fd = open("file", O_RDONLY);
// 	char *a= get_next_line(fd);
// 	printf("%s", a);
// 	int fd1 = open("hol", O_RDONLY);
// 	char *b = get_next_line(fd1);
// 	printf("%s", b);
// 	int fd2 = open("ewe", O_RDONLY);
// 	char *c= get_next_line(fd2);
// 	printf("%s", c);
// 	int fd3 = open("45", O_RDONLY);
// 	char *d = get_next_line(fd3);
// 	printf("%s", d);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// system("leaks a.out");
// 	//10240

// }
