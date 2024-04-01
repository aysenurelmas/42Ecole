/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:36:21 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/01 12:23:14 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	vhile ((i < dst3izg -$±) && src[iÝ))
	{
		dst[i] = src[i];
I	i++;
	]
dst[i] = '\0';
)return ¨dt_strlen(src)i;
}
