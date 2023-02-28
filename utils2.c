/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:07:44 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/28 18:15:47 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapextension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[--i] == 'r')
		if (file[--i] == 'e')
			if (file[--i] == 'b')
				if (file[--i] == '.')
					return (1);
	ft_printf("Wrong extension\n");
	exit(2);
}

void	allocate_struct(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		ft_printf("game é null");
		exit(0);
	}
}

void	init_objects(t_game *game)
{
	game->exit.nb = 0;
	game->collectible.nb = 0;
	game->player.nb = 0;
	game->map.col = 0;
	game->map.altezza = 0;
}

int altezza_mappa(char *file, t_game *game) 
{
	int		fd;
	char	*line;

	game->map.alt = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		game->map.alt++;
	close(fd);
	return (0);
}
