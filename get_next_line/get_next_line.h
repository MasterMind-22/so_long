/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:49:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/19 14:46:49 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 20

# endif

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<string.h>
# include<fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		newline_found(char *read_line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif