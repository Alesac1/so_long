/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:17:20 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/22 19:30:39 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char	*file, t_game *game)
{
	int		fd;
	char	*line;
	int		c_line;
	int		n_line;

	c_line = 0;
	game->b = 0;
	n_line = get_map_lines(file);
	game->map = malloc(sizeof(char *) * n_line + 1);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == 10)
			break ;
		game->map[c_line] = ft_strdup(line);
		if (game->map[c_line][ft_strlen(game->map[c_line]) - 1] == '\n')
			game->map[c_line][ft_strlen(game->map[c_line]) - 1] == '\0';
		free(line);
		c_line++;
		game->b++;
	}
	free(line);
	close(fd);
	game->map[c_line] = 0;
}