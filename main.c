/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/22 17:10:51 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_game	game;
	t_image	image;
	int		width;
	int		height;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 1000, "stocazzo");
	width = 50;
	height = 50;
	game.img = mlx_xpm_file_to_image(game.mlx, "./2.xpm.xpm", &width, &height);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}