/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:17:20 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/04 18:57:10 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char	*file, t_game *game)
{
	int		fd;
	char	*line;
	int		c_line;

	c_line = 0;
	game->map.altezza = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	game->map.col = ft_strlen(line) - 1;
	game->map.map = malloc(sizeof(char *) * (game->map.alt));
	while (line)
	{
		game->map.map[c_line] = ft_strdup(line);
		if (game->map.map[c_line][ft_strlen(game->map.map[c_line]) - 1] == '\n')
		{
			game->map.map[c_line][ft_strlen(game->map.map[c_line]) - 1] = '\0';
		}
		c_line++;
		game->map.altezza++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map.map[c_line] = 0;
	close(fd);
}

int	check_shape(char *file, t_game *game)
{
	int	i;
	int	width;

	width = 0;
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
				game->player.pos.y = i;
				game->player.pos.x = j;
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
					game->map.map[i][j] != 'P' && game->map.map[i][j] != 'A')
				error_map();
			if (game->map.map[i][j] == 'C')
				game->collectible.nb++;
			if (game->map.map[i][j] == 'A')
				game->enemy.nb++;
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
		{
			error_map();
			return (0);
		}
			i++;
	}
	i = 0;
	while (i < game->map.col)
	{
		if (game->map.map[game->map.alt - 1][i] != '1')
		{
			error_map();
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map.alt)
	{
		if (game->map.map[i][0] != '1')
		{
			error_map();
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map.alt)
	{
		j = ft_strlen(game->map.map[i]) - 1;
		if (j >= 0 && game->map.map[i][j] != '1')
		{
			error_map();
			return (0);
		}
		i++;
	}
	return (1);
}
