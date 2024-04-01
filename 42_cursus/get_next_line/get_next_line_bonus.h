/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:58:03 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/16 12:13:29 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char	*str, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_read(int fd, char *left_str);
char	*get_line(char *left_str);
char	*next_line(char *left_str);

#endif
