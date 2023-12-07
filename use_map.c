/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 03:26:28 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/01 03:37:40 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos(t_data *data)
{
	int i;
	int j;
	t_character *player = data->player;

	i = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				player->x = i;
				player->y = j;
			}
			j++;
		}
		i++;
	}
}

int		check_move(t_data *data)
{

	if (data->map[data->player->x][data->player->y] == 'C' && data->player->x != 0 && data->player->y != 0)
	{
		data->collectibles--;
		data->map[data->player->x][data->player->y] = '0';
	}
	if (data -> collectibles == 0 && data->map[data->player->x][data->player->y] == 'E' && data->player->x != 0 && data->player->y != 0)
		close_window(data);	
	return 0;
}
void	print_display(t_data *data)
{
		write(1, "\033[H\033[J", 7);
		printf("%ld moves, loser\n", data->moves);
		printf("%ld donkeys left\n", data->collectibles);
}