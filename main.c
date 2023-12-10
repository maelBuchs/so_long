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
	data->mlx = mlx_init();
	if (!data->mlx)
		close_tabs(data);
	data->win = mlx_new_window
		(data->mlx, data->h * 32, data->w * 32, "so_long");
	init_textures(data);
	set_background(data->w, data->h, data);
	update_character(data, player, 0);
	mlx_expose_hook(data->win, redraw, data);
	mlx_hook(data->win, 17, 1L << 17, close_window, data);
	mlx_key_hook(data->win, check_key, data);
	mlx_loop(data->mlx);
	return (0);
}

void	init_struct(t_data *data)
{
	data->w = 0;
	data->h = 0;
	data->collectibles = 0;
	data->moves = 0;
}

void	check_exension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 4)
	{
		if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
				&& str[i - 3] == 'b' && str[i - 4] == '.'))
		{
			ft_putstr_fd("Error\nshrek cannot read this dialect, \
sorry (wrong file extension)\n", 1);
			exit (0);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_character	player;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nshrek is lying in an infinite emptiness \
(include a map path pls)\n", 1);
		return (0);
	}
	check_exension(argv[1]);
	data.collectibles = 0;
	data.w = read_map(argv[1], &data);
	if (data.w <= 0)
	{
		ft_putstr_fd("Error\nshrek is lying in an infinite emptiness \
(include a REAL map path pls)\n", 1);
		return (0);
	}
	data.h = ft_strlen(data.map[0]);
	data.player = &player;
	check_map(&data);
	data.moves = 0;
	game(&data);
}
