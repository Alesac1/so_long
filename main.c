/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/01 20:21:04 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (1 * ft_printf("Missing .ber file"));
	else
	{
		check_mapextension(av[1]);
		game = malloc(sizeof(t_game));
		game->mlx = mlx_init();
		altezza_mappa(av[1], game);
		init_objects(game);
		map_init(game, av[1]);
		// printf("Il valore di player: %d\n", game->player.nb);
		// printf("Il valore di collectible: %d\n", game->collectible.nb);
		// printf("Il valore di exit: %d\n", game->exit.nb);
		// printf("Il valore di numcol: %d\n", game->map.col);
		// printf("valore dell'altezza: %d\n", game->map.alt);
		// set_sprites(game);
		game->win = mlx_new_window(game->mlx, (game->map.col) * 64,
				(game->map.alt) * 64, "Gioco Porcodio");
		game->images->background = put_image(game);
		draw_map(game);
		mlx_loop(game->mlx);
	}
	return (0);
}
