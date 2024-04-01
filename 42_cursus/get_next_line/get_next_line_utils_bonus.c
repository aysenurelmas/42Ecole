/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:00:21 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/16 12:16:06 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *chr)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !chr)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(chr) + 1));
	if (!res)
		return (0);
	i = -1;
	while (str[++i] != '\0')
		res[i] = str[i];
	j = 0;
	while (chr[j] != '\0')
		res[i++] = chr[j++];
	res[i] = '\0';
	free(str);
	return (res);
}
