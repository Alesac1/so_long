/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:10:14 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/04 18:55:08 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_map(t_game *game)
{
	draw_map(game);
	draw_obj(game);
	draw_pg(game);
	return (0);
}

char	**map_init(t_game *game, char *file)
{
	read_map(file, game);
	check_shape(file, game);
	altezza_mappa(file, game);
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
		return (0);
	return (game->map.map);
}