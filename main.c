/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/21 17:35:52 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_mlx	mlx;
	t_image	image;
	int		width;
	int		height;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "Titolo della finestra");
	width = 50;
	height = 50;
	mlx_put_image_to_window (mlx.mlx, mlx.win, "./2.xpm.xpm", 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}