/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:00 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/26 18:01:11 by asacchin         ###   ########.fr       */
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

typedef struct s_element
{
	int			framecount;
	int			nb;
	void		*reference;
	t_vector	pos;
}	t_element;

typedef struct s_map
{
	char	**map;
	int		col;
}	t_map;

typedef struct s_game
{
	void		*img;
	t_map		map;
	void		*mlx;
	void		*win;
	t_element	player;
	t_element	collectible;
	t_element	exit;
	t_element	floor;
	t_element	wall;
	int			nbmoves;
	char		*str;
	int			status;
	int			b;
	int			h;
	int			numcol;
}	t_game;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	t_vector	pos;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

char	**map_init(t_game *game, char *file);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmeb, size_t size);
void	ft_bzero(void *str, size_t n);
void	error_map(void);

#endif