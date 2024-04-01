/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:18:33 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 14:39:59 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <assert.h>

static char	is_wall(char **map, int *i, int *j)
{
	*i = 0;
	while (map[0][*i])
	{
		if ('1' != map[0][(*i)++])
			return (0);
	}
	(*i)--;
	*j = 0;
	while (map[*j][0])
	{
		if ('1' != map[*j][0] || '1' != map[*j][*i])
			return (0);
		(*j)++;
	}
	(*j)--;
	*i = 0;
	while (map[*j][*i])
	{
		if ('1' != map[*j][(*i)++])
			return (0);
	}
	return (1);
}

static char	is_cep(char c, t_mapcheck *test, char mod)
{
	if (mod == 1)
	{
		test->c = 0;
		test->e = 0;
		test->p = 0;
		return (1);
	}
	if (c == 'C')
		test->c++;
	else if (c == 'E')
		test->e++;
	else if (c == 'P')
		test->p++;
	if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1')
		return (0);
	return (1);
}

static void	is_pos(t_game *game, t_mapcheck mapc)
{
	int	xx;
	int	yy;

	yy = 0;
	game->coincount = mapc.c;
	while (game->map[yy])
	{
		xx = 0;
		while (game->map[yy][xx])
		{
			if (game->map[yy][xx] == 'P')
			{
				game->pos.x = xx;
				game->pos.y = yy;
				return ;
			}
			xx++;
		}
		yy++;
	}
}

char	map_cntrl(t_game *game)
{
	t_mapcheck	*test;
	int			i_max;
	int			j_max;

	if (!is_wall(game->map, &i_max, &j_max))
		return (0);
	test = (t_mapcheck *)malloc(sizeof(t_mapcheck));
	is_cep(0, test, 1);
	test -> j = -1;
	while (++(test -> j) < j_max)
	{
		test -> i = -1;
		i_max--;
		while (++(test -> i) < i_max)
			is_cep(game->map[test -> j][test -> i], test, 0);
	}
	if (test -> c < 1 || test -> e < 1 || test -> p < 1)
		return (0);
	is_pos(game, *test);
	free(test);
	return (1);
}
