/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:14:25 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 13:16:06 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "limits.h"

int	windowlen(char **map, char mod)
{
	int	i;

	i = 1;
	if (mod == 'y')
	{
		while (map[i])
			i++;
		return (i * 45);
	}
	if (mod == 'x')
	{
		while (map[0][i])
			i++;
		return (i * 45);
	}
	return (0);
}

int	game_over(t_game *oyun, char *msg)
{
	int	x;

	x = 0;
	while (oyun->map[x])
		free(oyun->map[x++]);
	free(oyun->sprite.floor);
	free(oyun->sprite.karakter);
	free(oyun->sprite.rkarakter);
	free(oyun->sprite.door);
	free(oyun->sprite.crate);
	free(oyun->sprite.wall);
	printf("%s", msg);
	exit(mlx_destroy_window(oyun->mlx, oyun->win));
	return (1);
}

void	game_play(t_game *game)
{
	game->yon = RIGHT;
	game->haraket_sayisi = 0;
	game->durum = 1;
	game->mlx = mlx_init();
	printf("Oyun Basliyor \n");
	content_fill(game);
	if (game->sprite.wall)
		printf("\n\n");
	game->win = mlx_new_window(game->mlx, windowlen(game->map, 'x'),
			windowlen(game->map, 'y'), "so_long");
	map_draw(game);
	mlx_hook(game->win, ON_KEYDOWN, 0, key_press, game);
	mlx_hook(game->win, ON_DESTROY, 1L << 0, game_over, game);
	mlx_loop(game->mlx);
}
