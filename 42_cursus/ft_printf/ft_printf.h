/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:08:18 by aelmas            #+#    #+#             */
/*   Updated: 2022/03/23 16:08:22 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, char c);
int		ft_putchr(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_unputnbr(unsigned int nbr);
int		ft_hex_nbr(size_t nbr, char c);

#endif
