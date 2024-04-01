/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:55:52 by aelmas            #+#    #+#             */
/*   Updated: 2022/02/22 17:17:46 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void		*str;

	str = (void *)malloc(size * num);
	if (str == 0)
		return (0);
	ft_bzero(str, num * size);
	return (str);
}
