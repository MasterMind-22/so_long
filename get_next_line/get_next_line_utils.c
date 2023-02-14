/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:50:22 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/28 18:51:00 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (*s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	newline_found(char *read_line)
{
	int	i;

	i = 0;
	if (!read_line)
		return (1);
	while (read_line[i] != '\0')
	{
		if (read_line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*sum;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	sum = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sum)
		return (NULL);
	while (s1[++i])
		sum[i] = s1[i];
	while (s2[j])
		sum[i++] = s2[j++];
	sum[i] = '\0';
	free (s1);
	return (sum);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;
	size_t	len;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (!copy)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
