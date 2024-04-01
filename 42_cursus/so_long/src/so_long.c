/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:24:25 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 13:51:11 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	j;
	int	i;
	int	a;

	j = 0;
	while (s2[j] != '\0')
	{
		j++;
	}
	i = -1;
	a = 0;
	while (a < 4 && s1[++i] == s2[--j])
	{
		a++;
	}
	return (s1[i] - s2[j]);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;
	char	*line;

	if (ac != 2)
		return (printf("ERROR: Kullanım: ./solong map_file\n") * 0);
	if (ft_strcmp("reb.", av[1]))
		return (printf("isim hatalı.\n") * 0);
	game = (t_game *)malloc(sizeof(t_game));
	fd = open(av[1], O_RDONLY);
	if (!game || fd < 0)
		return (0);
	game->map = malloc(sizeof(char **) * 8888);
	while (1)
	{
		line = get_next_line(game->map, fd);
		if (!*line)
			break ;
	}
	fd = map_cntrl(game);
	if (!fd)
		return (printf("Error\nMap Bu şekilde olamaz!!\n"));
	else
		game_play(game);
	free(game);
}
