/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveevents.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:22:51 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 13:23:55 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		game_over(game, "\nbye\n");
	if (game->durum == 1)
	{
		if (keycode == KEY_W || keycode == KEY_UP)
			git(game, 0, -1);
		else if (keycode == KEY_S || keycode == KEY_DOWN)
			git(game, 0, 1);
		else if (keycode == KEY_D || keycode == KEY_RIGHT)
			git(game, 1, 0);
		else if (keycode == KEY_A || keycode == KEY_LEFT)
			git(game, -1, 0);
		map_draw(game);
		printf("\033[A\033[2K");
		printf("Haraket Sayısı:%d\n", game->haraket_sayisi);
	}
	return (keycode);
}

void	swapmod(char *e, char *n, t_game *game, char mod)
{
	if (mod == 'S')
	{
		*e ^= *n;
		*n ^= *e;
		*e ^= *n;
		return ;
	}
	if (mod == RIGHT)
		game->yon = RIGHT;
	else if (mod == LEFT)
		game->yon = LEFT;
}

void	git(t_game *game, int x, int y)
{
	char	*e;
	char	*n;

	e = &(game->map[game->pos.y][game->pos.x]);
	n = &(game->map[game->pos.y + y][game->pos.x + x]);
	(game->haraket_sayisi)++;
	if ('1' == *n)
		return ;
	else if ('E' == *n)
	{
		if (game->coincount == 0)
			game_over(game, "\nTebrikler\n");
		return ;
	}
	else if ('C' == *n && (game->coincount)--)
		*n = '0';
	swapmod(e, n, game, 'S');
	game->pos.y += y;
	game->pos.x += x;
	if (x == 1)
		game->yon = RIGHT;
	if (x == -1)
		game->yon = LEFT;
}
