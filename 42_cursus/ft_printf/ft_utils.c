/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:51 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/30 15:08:11 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		i += ft_putstr("-2");
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		i += ft_putchr('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		i += ft_putnbr(nbr / 10);
	i += ft_putchr((nbr % 10) + '0');
	return (i);
}

int	ft_unputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_unputnbr(nb / 10);
	i += ft_putchr((nb % 10) + '0');
	return (i);
}

int	ft_hex_nbr(size_t nbr, char c)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += ft_hex_nbr(nbr / 16, c);
	if (c == 'X')
		len += ft_putchr("0123456789ABCDEF"[nbr % 16]);
	else if (c == 'x' || c == 'p')
		len += ft_putchr("0123456789abcdef"[nbr % 16]);
	return (len);
}
