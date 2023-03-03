/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/03 20:02:40 by asacchin         ###   ########.fr       */
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
		mlx_loop_hook(game->mlx, update_map, (void *)game);
		mlx_hook(game->win, 2, 0, key_hook, game);
		mlx_hook(game->win, 17, 0, ft_close, 0);
		ft_printf("ciao  fra fumo un baobab\n");
		setup_sprites(game);
		update_map(game);
		mlx_loop(game->mlx);
	}
	return (0);
}
