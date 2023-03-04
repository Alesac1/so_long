/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/04 16:12:47 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
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
		game->map.map = map_init(game, av[1]);
		game->win = mlx_new_window(game->mlx, (game->map.col) * 32,
				(game->map.alt) * 32, "Gioco Porcodio");
		setup_sprites(game);
		update_map(game);
		mlx_key_hook(game->win, key_hook, (void *)game);
		mlx_hook(game->win, 17, 0, ft_close, 0);
		ft_printf("ciaooo\n");
		mlx_loop(game->mlx);
	}
	return (0);
}
