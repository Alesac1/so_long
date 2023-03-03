/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:00 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/03 19:48:23 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl_20191021/mlx.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	t_vector	size;
	t_vector	pos;
	void		*reference;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_element
{
	t_vector	pos;
	int			framecount;
	void		*background;
	int			nb;
	void		*reference;
	t_image		currentimg;
	t_image		img0;
	t_image		img1;
}	t_element;

typedef struct s_map
{
	char	**map;
	int		col;		/* larghezza */
	int		altezza;	/* altezza */
	int		alt;
}	t_map;

typedef struct s_textures
{
	void	*background;
	void	*wall;
	void	*escape;
	void	*player;
	void	*collect;
	void	*mlx;
	void	*win_screen;
}				t_textures;

typedef struct s_game
{
	t_map		map;
	t_element	player;
	t_element	collectible;
	t_element	exit;
	t_element	floor;
	t_element	wall;
	t_textures	*images;
	void		*img;
	void		*mlx;
	void		*win;
	char		*str;
	int			counter;
	int			nbmoves;
	int			status;
	int			height;
	int			widht;
}	t_game;

/*			Map			*/
int			check_mapextension(char *file);
int			altezza_mappa(char *file, t_game *game);
void		init_objects(t_game *game);
char		**map_init(t_game *game, char *file);
void		setup_sprites(t_game *game);
void		draw_map(t_game *game);
void		draw_obj(t_game *game);
int			map_compiler(t_game *game);
int			update_map(t_game *game);
void		update_player(t_game *game);

t_game		*allocate_struct(void);
char		*ft_strdup(const char *s);
void		error_map(void);
int			ft_close(void);
int			key_hook(int key, t_game *game);
void		move_up(t_game *game);

#endif