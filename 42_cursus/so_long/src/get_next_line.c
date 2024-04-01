/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:16:26 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 13:22:23 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*get_next_line(char **map, int fd)
{
	char		buffer;
	char		*line;
	int			rd_byte;
	int			i;
	static int	y = 0;

	line = (char *)malloc(sizeof(char *) * 8888);
	rd_byte = 1;
	i = 0;
	buffer = 0;
	while (rd_byte != 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte == -1 || buffer == '\n' || buffer == '\0')
			break ;
		line[i++] = buffer;
	}
	line[i] = '\0';
	map[y] = line;
	map[y++][i] = '\0';
	if (!line)
		free(line);
	return (line);
}
