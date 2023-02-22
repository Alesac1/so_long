/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:00 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/22 17:18:26 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl_20191021/mlx.h"
# include "ft_printf/ft_printf.h"
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

typedef struct s_game
{
	void		*img;
	char		**map;
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

char	*ft_strjoin(char *s1, char *s2);
char	*get_line(int fd, char *line);
char	*ft_strchr(char *s, int c);
char	*get_new_line(char *line);
char	*get_next_line(int fd);
char	*new_line(char *line);
int		ft_strlen(char *s);

#endif