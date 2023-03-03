/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:28:02 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/03 19:47:07 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == 'C')
	{
		game->collectible.nb--;
		game->map.map[game->player.pos.y -1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == '0'
		|| game->map.map[game->player.pos.y - 1][game->player.pos.x] == 'E')
	{
		game->map.map[game->player.pos.y - 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	// if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == 'A')
	// {
	// 	ft_printf("you lose\n");
	// 	ft_close(game);
	// }
}

int	key_hook(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (key == 53 || key == 13 || key == 0 || key == 1 || key == 2)
	{
		if (key == 13)
		{
			move_up(game);
			ft_printf("per questo c'ho la voce rauca\n");
		}
	}
	return (0);
}

void	update_player(t_game *game)
{
	game->player.currentimg.reference = game->player.img0.reference;
	if (game->player.framecount > 5 && game->player.framecount < 35)
		game->player.currentimg.reference = game->player.img1.reference;
	else if (game->player.framecount >= 60)
		game->player.framecount = 0;
	game->player.framecount++;
}


int	update_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	update_player(game);
	draw_obj(game);
	return (1);
}
