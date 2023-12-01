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

int	update_character(t_data *data, t_character *player, int option)
{
	mlx_put_image_to_window
				(data -> mlx, data -> win, data -> background, 32 * player->y, 32 * player->x);
	if (option == 1)
		data->player->x -= 1;
	if (option == 2)
		data->player->y += 1;
	if (option == 3)
		data->player->x += 1;
	if (option == 4)
		data->player->y -= 1;
	mlx_put_image_to_window
		(data -> mlx, data -> win, data -> character,32 * data->player->y, 32 * data->player->x);
	return (0);
}

int	read_map(char *path, t_data *data)
{
	int fd;
	int i;

	i = 1;
	data->map = malloc(sizeof(char*) * 2);
	fd = open(path, O_RDONLY);
	data->map[0] = get_next_line(fd);
	data->map[1] = NULL;

	while(data->map[i - 1])
	{
		enlarge_tab(data);
		data->map[i] = get_next_line(fd);
		i++;
	}
	print_tab(data);
	return (0);
}

void	enlarge_tab(t_data *data)
{
	char	**returned;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while(data->map[len])
		len++;
	returned = malloc (sizeof(char*) * (len + 2));
	while(i < len)
	{
		returned[i] = data->map[i];
		i++;
	}
	returned[i] = 0;
	returned[i + 1] = 0;
	free_tab(data, len);
	data->map = returned;
}

void	free_tab(t_data *data, int len)
{
	int i;
	
	i = 0;
	if(data -> map)
	{
		while (i < len - 1)
		{
			// if(data->map[i])
			// 	free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void print_tab(t_data *data)
{
	int i;
	i = 0;

	while(data->map[i])
	{
		printf("%s", data->map[i]);
		i++;
	}

}