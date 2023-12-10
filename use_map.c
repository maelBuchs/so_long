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

void	print_display(t_data *data)
{
	write(1, "\033[H\033[J", 7);
	ft_putnbr_fd(data->moves, 1);
	ft_putstr_fd(" moves, loser\n", 1);
	ft_putnbr_fd(data->collectibles, 1);
	ft_putstr_fd(" donkeys left\n", 1);
}

int	close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->background)
		mlx_destroy_image(data->mlx, data->background);
	if (data->goal)
		mlx_destroy_image(data->mlx, data->goal);
	if (data->character)
		mlx_destroy_image(data->mlx, data->character);
	if (data->enemy)
		mlx_destroy_image(data->mlx, data->enemy);
	if (data->obstacle)
		mlx_destroy_image(data->mlx, data->obstacle);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	close_tabs(data);
	exit(0);
}

void	close_tabs(t_data *data)
{
	if (data->map)
		free_tab(data->map, 2);
	if (data->bfs_map)
		free_tab(data->bfs_map, 2);
}

void	free_tab(char **tab, int len)
{
	int	i;
	(void) len;
	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
