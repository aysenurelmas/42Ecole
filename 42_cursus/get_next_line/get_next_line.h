/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:24:27 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/15 13:24:58 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	**_line(char *left_str);
char	*ft_strjoin(char *s1, char *s2);

#endif
