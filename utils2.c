/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:07:44 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/01 18:51:30 by asacchin         ###   ########.fr       */
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

t_game	*allocate_struct(void)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	if (!g)
	{
		free(g);
		ft_printf("g é null");
		exit(0);
	}
	return (g);
}

void	init_objects(t_game *game)
{
	game->exit.nb = 0;
	game->collectible.nb = 0;
	game->player.nb = 0;
	game->map.col = 0;
	game->map.altezza = 0;
}

int	altezza_mappa(char *file, t_game *game)
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
