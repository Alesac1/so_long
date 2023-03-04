/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:28:02 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/04 18:31:18 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == 'C')
	{
		game->collectible.nb--;
		game->map.map[game->player.pos.y - 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == '0')
	{
		game->map.map[game->player.pos.y - 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == 'E' &&
		game->collectible.nb == 0)
	{
		game->map.map[game->player.pos.y - 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
		ft_printf("You Win :)\n");
		ft_close();
	}
	if (game->map.map[game->player.pos.y - 1][game->player.pos.x] == 'A')
	{
		ft_printf("You Lose :(\n");
		ft_close();
	}
	update_map(game);
}

void	move_down(t_game *game)
{
	if (game->map.map[game->player.pos.y + 1][game->player.pos.x] == 'C')
	{
		game->collectible.nb--;
		game->map.map[game->player.pos.y + 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y + 1][game->player.pos.x] == '0')
	{
		game->map.map[game->player.pos.y + 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y + 1][game->player.pos.x] == 'E' &&
		game->collectible.nb == 0)
	{
		game->map.map[game->player.pos.y + 1][game->player.pos.x] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
		ft_printf("You Win :)\n");
		ft_close();
	}
	if (game->map.map[game->player.pos.y + 1][game->player.pos.x] == 'A')
	{
		ft_printf("You Lose :(\n");
		ft_close();
	}
	update_map(game);
}

void	move_right(t_game *game)
{
	if (game->map.map[game->player.pos.y][game->player.pos.x + 1] == 'C')
	{
		game->collectible.nb--;
		game->map.map[game->player.pos.y][game->player.pos.x + 1] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y][game->player.pos.x + 1] == '0')
	{
		game->map.map[game->player.pos.y][game->player.pos.x + 1] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y][game->player.pos.x + 1] == 'E' &&
		game->collectible.nb == 0)
	{
		game->map.map[game->player.pos.y][game->player.pos.x + 1] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
		ft_printf("You Win :)\n");
		ft_close();
	}
	if (game->map.map[game->player.pos.y][game->player.pos.x + 1] == 'A')
	{
		ft_printf("You Lose :(\n");
		ft_close();
	}
	update_map(game);
}

void	move_left(t_game *game)
{
	if (game->map.map[game->player.pos.y][game->player.pos.x - 1] == 'C')
	{
		game->collectible.nb--;
		game->map.map[game->player.pos.y][game->player.pos.x - 1] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y][game->player.pos.x - 1] == '0')
	{
		game->map.map[game->player.pos.y][game->player.pos.x - 1] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	}
	if (game->map.map[game->player.pos.y][game->player.pos.x - 1] == 'E' &&
		game->collectible.nb == 0)
	{
		game->map.map[game->player.pos.y][game->player.pos.x - 1] = 'P';
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
		ft_printf("You Win :)\n");
		ft_close();
	}
	if (game->map.map[game->player.pos.y][game->player.pos.x - 1] == 'A')
	{
		ft_printf("You Lose :(\n");
		ft_close();
	}
	update_map(game);
}

int	key_hook(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (key == 53 || key == 13 || key == 0 || key == 1 || key == 2
		|| key == 126 || key == 125 || key == 124 || key == 123)
	{
		if (key == 13 || key == 126)
			move_up(game);
		if (key == 1 || key == 125)
			move_down(game);
		if (key == 2 || key == 124)
			move_right(game);
		if (key == 0 || key == 123)
			move_left(game);
		if (key == 53)
			ft_close();
		ft_printf("valore di collectible: %d\n", game->collectible.nb);
	}
	return (0);
}
