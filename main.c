/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:09:08 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/27 16:31:00 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	void print_matrix(char **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
	t_game	game;
	t_image	image;
	int		width;
	int		height;

	// game.mlx = mlx_init();
	// game.win = mlx_new_window(game.mlx, 1000, 1000, "stocazzo");
	// width = 50;
	// height = 50;
	// game.img = mlx_xpm_file_to_image(game.mlx, "./2.xpm.xpm", &width, &height);
	// mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	// mlx_loop(game.mlx);
	game.exit.nb = 0;
	game.collectible.nb = 0;
	game.player.nb = 0;
	map_init(&game, "/Map/map_0.ber");
	print_matrix(game.map.map, game.b, game.h);
	printf("Il valore di player: %d\n", game.player.nb);
	printf("Il valore di collectible: %d\n", game.collectible.nb);
	printf("Il valore di exit: %d\n", game.exit.nb);
	return (0);
}