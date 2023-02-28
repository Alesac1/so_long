/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/28 18:45:28 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	altezza_mappa(av[1], game);
	check_mapextension(av[1]);
	init_objects(game);
	map_init(game, av[1]);
	printf("Il valore di player: %d\n", game->player.nb);
	printf("Il valore di collectible: %d\n", game->collectible.nb);
	printf("Il valore di exit: %d\n", game->exit.nb);
	printf("Il valore di numcol: %d\n", game->map.col);
	printf("valore dell'altezza: %d\n", game->map.alt);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map.col) * 64,
			(game->map.alt) * 64, "Gioco Porcodio");
	mlx_loop(game->mlx);
	return (0);
}
