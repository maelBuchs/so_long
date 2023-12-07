/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:00:25 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/18 19:00:25 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game(t_data *data)
{
	t_character	*player;
	player = data->player;

	data -> mlx = mlx_init();
	data -> win = mlx_new_window
		(data -> mlx, data -> h * 32, data -> w * 32, "so_long");
	set_pos(data);
	init_textures(data);
	set_background(data -> w, data -> h, data);
	update_character(data, player, 0);
	mlx_expose_hook(data -> win, redraw, data);
	mlx_hook(data -> win, 17, 1L << 17, close_window, data);
	mlx_key_hook(data -> win, check_key, data);
	mlx_loop(data -> mlx);
	return (0);
}

int	main(int argc, char *argv[]) 
{
	t_data	data;
	t_character	player;

	if(argc != 2)
	{
		ft_putstr_fd("Error\nshrek is lying in an infinite emptiness \
(include a map path pls)\n", 1);
		return (0);
	}
	data.w = read_map(argv[1], &data);
	data.h = ft_strlen(data.map[0]) - 2;
	data.player = &player;
	check_map(&data);
	player.x = 0;
	player.y = 0;
	data.moves = 0;
	game(&data);
}

    // if (data.img == NULL)
    // {
    //     printf("Impossible de charger l'image.\n");
    //     return 1;
    // }
