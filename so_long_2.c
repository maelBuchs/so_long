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
		player->x -= 1;
	if (option == 2)
		player->y += 1;
	if (option == 3)
		player->x += 1;
	if (option == 4)
		player->y -= 1;
	mlx_put_image_to_window
		(data -> mlx, data -> win, data -> character,32 * player->y, 32 * player->x);
	return (0);
}