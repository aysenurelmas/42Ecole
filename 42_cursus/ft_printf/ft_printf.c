/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:10:29 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/22 13:19:48 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchr(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		count = ft_unputnbr(va_arg(args, unsigned int));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_hex_nbr(va_arg(args, unsigned long), c);
	}
	else if (c == 'x' || c == 'X')
		count = ft_hex_nbr(va_arg(args, unsigned int), c);
	else if (c == '%')
		count = ft_putchr('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count += ft_formats(args, str[++i]);
		else
			count += ft_putchr(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

#include "limits.h"
#include <stdio.h>
int	main(void)
{
	ft_printf("ft_uzunluk : %d", ft_printf("%u\n", -12));
	printf("n_uzunluk :%d\n",printf("\n%u\n", -12));

	ft_printf("haraket sayıs:%d",12);
	ft_printf("/r");
	ft_printf("sayısı:%d", 32);
	return (0);
}

