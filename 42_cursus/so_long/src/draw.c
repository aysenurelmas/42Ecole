/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:13:42 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 13:13:48 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	content_draw(void *img, const t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, 45 * x, 45 * y);
}

void	content_fill(t_game *game)
{
	int		sprlen;

	sprlen = 45;
	game->sprite.door = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door.xpm", &sprlen, &sprlen);
	game->sprite.floor = mlx_xpm_file_to_image(game->mlx,
			"./sprites/floor.xpm", &sprlen, &sprlen);
	game->sprite.wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall.xpm", &sprlen, &sprlen);
	game->sprite.crate = mlx_xpm_file_to_image(game->mlx,
			"./sprites/crate.xpm", &sprlen, &sprlen);
	game->sprite.karakter = mlx_xpm_file_to_image(game->mlx,
			"./sprites/character1.xpm", &sprlen, &sprlen);
	game->sprite.rkarakter = mlx_xpm_file_to_image(game->mlx,
			"./sprites/rcharacter1.xpm", &sprlen, &sprlen);
}

static void	player_draw(t_game *game, int x, int y)
{
	if (game -> yon == RIGHT)
		content_draw(game->sprite.karakter, game, x, y);
	else
		content_draw(game->sprite.rkarakter, game, x, y);
}

void	map_draw(t_game *game)
{
	int			x;
	int			y;

	y = -1;
	mlx_clear_window(game->mlx, game->win);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			content_draw(game->sprite.floor, game, x, y);
			if (game->map[y][x] == '1')
				content_draw(game->sprite.wall, game, x, y);
			else if (game->map[y][x] == 'C')
				content_draw(game->sprite.crate, game, x, y);
			else if (game->map[y][x] == 'E')
				content_draw(game->sprite.door, game, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, x, y);
		}
	}
}
