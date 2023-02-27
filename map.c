/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:17:20 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/27 17:39:06 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char	*file, t_game *game)
{
	int		fd;
	char	*line;
	int		c_line;

	c_line = 0;
	game->b = 0;
	fd = open("Maps/map_0.ber", O_RDONLY);
	line = get_next_line(fd);
	game->map.col = ft_strlen(line);
	game->map.map = malloc(sizeof(char *) * (game->b + 1));
	while (line)
	{
		game->map.map[c_line] = ft_strdup(line);
		if (game->map.map[c_line][ft_strlen(game->map.map[c_line]) - 1] == '\n')
		{
			game->map.map[c_line][ft_strlen(game->map.map[c_line]) - 1] = '\0';	
		}
		c_line++;
		// printf("Il valore di c_line: %d\n", c_line);
		game->b++;
		// printf("Il valore di b: %d\n", game->b);
		free(line);
		line = get_next_line(fd);
	}
	game->map.map[c_line] = 0;
	close(fd);
}

int	check_shape(char *file, t_game *game)
{
	int	i;
	int	width;

	width = ft_strlen(game->map.map[0]);
	i = 0;
	while (game->map.map[i])
	{
		if (ft_strlen(game->map.map[i]) != width)
			error_map();
		i++;
	}
	return (1);
}

void	player_check(char *file, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				if (game->player.nb > 0)
				{
					ft_printf("invalid player map");
					exit(2);
				}
				game->player.pos.x = i;
				game->player.pos.y = j;
				game->player.nb++;
			}
			j++;
		}
		i++;
	}
}

void	map_checkvalues(char *file, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1' &&
					game->map.map[i][j] != 'C' && game->map.map[i][j] != 'E' &&
					game->map.map[i][j] != 'P')
				error_map();
			if (game->map.map[i][j] == 'C')
				game->collectible.nb++;
			else if (game->map.map[i][j] == 'E')
			{
				game->exit.nb++;
				game->exit.pos.x = i;
				game->exit.pos.y = j;
			}
			j++;
		}
		i++;
	}
}

int check_map_border(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.col)
	{
		if (game->map.map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->b)
	{
		if (game->map.map[game->b - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->b)
	{
		if (game->map.map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->b)
	{
		j = ft_strlen(game->map.map[i] - 1);
		if (j >= 0 && game->map.map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

char	**map_init(t_game *game, char *file)
{
	read_map(file, game);
	map_checkvalues(file, game);
	if (!game->collectible.nb)
	{
		ft_printf("missing collectible\n");
		exit(2);
	}
	if (!game->exit.nb)
	{
		ft_printf("missing exit\n");
		exit(2);
	}
	player_check(file, game);
	if (!game->player.nb)
	{
		ft_printf("missing player");
		exit(2);
	}
	if (!check_map_border(game))
		return (NULL);
	return (game->map.map);
}
