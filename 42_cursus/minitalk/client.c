/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:38:02 by aelmas            #+#    #+#             */
/*   Updated: 2022/07/06 14:40:02 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	faction(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr(received);
		ft_putchr('\n');
	}
}

static void	ft_send(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		c = *str++;
		i = 8;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	ft_putstr("Received: ");
	signal(SIGUSR1, faction);
	signal(SIGUSR2, faction);
	ft_send(ft_atoi(av[1]), av[2]);
	return (0);
}
