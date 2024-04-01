/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:34:24 by aelmas            #+#    #+#             */
/*   Updated: 2022/09/28 13:35:04 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef MLX_H
#  include "../minilibx/mlx.h"
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mapcheck
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
}	t_mapcheck;

# define LEFT -1
# define RIGHT 1
# define UP 2
# define DOWN -2

typedef struct s_sprites
{
	int		sprlen;
	void	*wall;
	void	*floor;
	void	*karakter;
	void	*rkarakter;
	void	*door;
	void	*crate;
}	t_sprites;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	int				haraket_sayisi;
	int				coincount;
	char			**map;
	t_pos			pos;
	char			yon;
	char			durum;
	t_sprites		sprite;
	unsigned char	animtime;
}	t_game;

char	*get_next_line(char **map, int fd);
char	map_cntrl(t_game *game);
void	game_play(t_game *game);
void	content_fill(t_game *game);
void	map_draw(t_game *game);
int		game_over(t_game *game, char *msg);
void	git(t_game *game, int x, int y);
int		key_press(int keycode, t_game *game);

#endif
