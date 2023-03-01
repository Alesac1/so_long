/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:48:37 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/01 20:19:59 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	assign_sprites(t_game *game, t_image *image, char *str)
// {
// 	int	i;

// 	i = 64;
// 	game->floor.background = mlx_xpm_file_to_image
// 		(game->mlx, str, &i, &i);
// }

// void	*set_sprites(void *mlx)
// {
// 	assign_sprites(game, &game->floor.img0, "xpm/background.xpm");
// }

t_textures	*put_image(t_game *game)
{
	int			w;
	t_textures	*images;

	w = 64;
	game->images = malloc(1 * sizeof(t_textures));
	game->images->background = mlx_xpm_file_to_image(game->images->mlx,
			"xpm/background.xpm", &w, &w);
	return (game->images);
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
					game->images->background, j * 64, i * 64);
					printf("ci siamoooo\n");	
			}
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->images->background, (game->map.col) * 64,
					(game->map.alt) * 64);
			j++;
		}
		i++;
	}
}

