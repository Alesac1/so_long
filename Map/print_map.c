/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:48:37 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/07 17:18:09 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprite_assign(t_game *game, t_image *image, char *str)
{
	int	smokey;

	smokey = 32;
	image->reference = mlx_xpm_file_to_image
		(game->mlx, str, &smokey, &smokey);
}

void	setup_sprites(t_game *game)
{
	sprite_assign(game, &game->floor.img0, "xpm/background.xpm");
	sprite_assign(game, &game->wall.img0, "xpm/wall.xpm");
	sprite_assign(game, &game->player.img0, "xpm/pg.xpm");
	sprite_assign(game, &game->player.img1, "xpm/dxplayer.xpm");
	sprite_assign(game, &game->player.img2, "xpm/sxplayer.xpm");
	sprite_assign(game, &game->collectible.img0, "xpm/collectible.xpm");
	sprite_assign(game, &game->exit.img0, "xpm/exit.xpm");
	sprite_assign(game, &game->enemy.img0, "xpm/enemy.xpm");
	sprite_assign(game, &game->exit.img2, "xpm/closedexit.xpm");
}

void	get_animation(t_game *game)
{
	
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall.img0.reference, j * 32, i * 32);
			}
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->floor.img0.reference, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_obj(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible.img0.reference, j * 32, i * 32);
			if (game->map.map[i][j] == 'E' && game->collectible.nb > 0)
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit.img2.reference, j * 32, i * 32);
			if (game->map.map[i][j] == 'E' && game->collectible.nb == 0)
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit.img0.reference, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_pg(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->player.img0.reference, j * 32, i * 32);
				game->player.pos.x = j;
				game->player.pos.y = i;
			}
			if (game->map.map[i][j] == 'A')
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy.img0.reference, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
