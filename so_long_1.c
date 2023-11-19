/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:39:45 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/18 21:39:45 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data -> background)
		mlx_destroy_image(data->mlx, data->background);
	if (data -> character)
		mlx_destroy_image(data->mlx, data->character);
	if (data -> enemy)
		mlx_destroy_image(data->mlx, data->enemy);
	if (data -> obstacle)
		mlx_destroy_image(data->mlx, data->obstacle);
	if (data -> win)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	init_textures(t_data *data)
{
	int	img_width;
	int	img_height;

	data -> goal = mlx_xpm_file_to_image
		(data -> mlx, "texture/goal.xpm", &img_width, &img_height);
	data -> character = mlx_xpm_file_to_image
		(data -> mlx, "texture/character.xpm", &img_width, &img_height);
	data -> background = mlx_xpm_file_to_image
		(data -> mlx, "texture/background.xpm", &img_width, &img_height);
	data -> enemy = mlx_xpm_file_to_image
		(data -> mlx, "texture/enemy.xpm", &img_width, &img_height);
	data -> obstacle = mlx_xpm_file_to_image
		(data -> mlx, "texture/obstacle.xpm", &img_width, &img_height);
}

void	set_background(int w, int h, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			mlx_put_image_to_window
				(data -> mlx, data -> win, data -> background, 32 * j, 32 * i);
			if (j == 0 || i == 0 || i == w - 1 || j == h - 1)
				mlx_put_image_to_window
					(data -> mlx, data -> win, data -> obstacle, 32 * j, 32 * i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window
					(data -> mlx, data -> win, data -> goal, 32 * 5, 32 * 5);
}

int	redraw(t_data *data)
{
	t_character *player = data->player;

	set_background(data -> w, data -> h, data);
	update_character(data, player, 0);
	return (0);
}

int	check_key(int keycode, t_data *data)
{
	t_character *player = data->player;

	if (keycode == 119) 			//up  0 -1
		update_character(data, player, 1);
	else if (keycode == 100) 			//right +1 0
		update_character(data, player, 2);
	else if (keycode == 115) 			// down 0 +1
		update_character(data, player, 3);
	else if (keycode == 97)				 //left -1 0
		update_character(data, player, 4);
	else if (keycode == 65307)
		close_window(data);
	else 
		return (0);
	data -> moves ++;
	printf("%ld moves, loser\n", data->moves);
	return (0);
}
