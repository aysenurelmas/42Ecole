/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:34:34 by aelmas            #+#    #+#             */
/*   Updated: 2022/02/22 16:34:40 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}

#include <stdio.h>
int main(void)
{
	char str[] = "aysenur";
	ft_bzero(str, 6);
	printf("\nstr: %s\n", str);
	return (0);
}
