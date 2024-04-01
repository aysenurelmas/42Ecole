/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:46:02 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/16 12:13:43 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*next_line(char *left_str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (left_str[i] != '\0' && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\0')
	{
		free(left_str);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (left_str[++i] != '\0')
		res[j++] = left_str[i];
	res[j] = '\0';
	free(left_str);
	return (res);
}

char	*get_line(char	*left_str)
{
	int		i;
	char	*res;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] != '\0' && left_str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = -1;
	while (left_str[++i] != '\0' && left_str[i] != '\n')
		res[i] = left_str[i];
	if (left_str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rbyte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rbyte = 1;
	while (!ft_strchr(left_str, '\n') && rbyte != 0)
	{
		rbyte = read(fd, buff, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rbyte] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str[fd] = ft_read(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = get_line(left_str[fd]);
	left_str[fd] = next_line(left_str[fd]);
	return (line);
}
