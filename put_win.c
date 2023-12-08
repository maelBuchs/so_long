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

void	init_textures(t_data *data)
{
	int	img_width;
	int	img_height;

	data->goal = mlx_xpm_file_to_image
		(data->mlx, "texture/goal.xpm", &img_width, &img_height);
	data->character = mlx_xpm_file_to_image
		(data->mlx, "texture/character.xpm", &img_width, &img_height);
	data->background = mlx_xpm_file_to_image
		(data->mlx, "texture/background.xpm", &img_width, &img_height);
	data->enemy = mlx_xpm_file_to_image
		(data->mlx, "texture/enemy.xpm", &img_width, &img_height);
	data->obstacle = mlx_xpm_file_to_image
		(data->mlx, "texture/obstacle.xpm", &img_width, &img_height);
}

void	set_background(int w, int h, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			mlx_put_image_to_window
				(data->mlx, data->win, data->background, 32 * j, 32 * i);
			put_misc(data->map[i][j], data, i, j);
			i++;
		}
		j++;
	}
}

void	put_misc(char c, t_data *data, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window
				(data->mlx, data->win, data->obstacle, 32 * j, 32 * i);
	if (c == 'C')
	{
		if (data->bfs_map[i][j] != 'A')
			print_error(data, 7);
		mlx_put_image_to_window
				(data->mlx, data->win, data->enemy, 32 * j, 32 * i);
	}
	if (c == 'E')
	{
		if (data->bfs_map[i][j] != 'A')
			print_error(data, 7);
		mlx_put_image_to_window
			(data->mlx, data->win, data->goal, 32 * j, 32 * i);
	}
	if (c == 'C' && data->moves == 0)
		data->collectibles++;
}

int	redraw(t_data *data)
{
	t_character	*player;

	player = data->player;
	if (data->moves == 0)
		data->collectibles = 0;
	set_background(data->w, data->h, data);
	update_character(data, player, 0);
	return (0);
}

/*	119 = w
	100 = d
	115 = s
	97 = a
	65307 = escape	*/

int	check_key(int keycode, t_data *data)
{
	t_character	*player;

	player = data->player;
	if (keycode == 119)
		update_character(data, player, 1);
	else if (keycode == 100)
		update_character(data, player, 2);
	else if (keycode == 115)
		update_character(data, player, 3);
	else if (keycode == 97)
		update_character(data, player, 4);
	else if (keycode == 65307)
		close_window(data);
	else
		return (0);
	print_display(data);
	return (0);
}
