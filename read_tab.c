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
		(data->mlx, data->win, data->background,
		32 * player->y, 32 * player->x);
	if (data->map[player->x][player->y] == 'E')
		mlx_put_image_to_window
			(data->mlx, data->win, data->goal,
			32 * player->y, 32 * player->x);
	if (option == 1 && data->map[player->x - 1][player->y] != '1')
		data->player->x -= 1;
	else if (option == 2 && data->map[player->x][player->y + 1] != '1')
		data->player->y += 1;
	else if (option == 3 && data->map[player->x + 1][player->y] != '1')
		data->player->x += 1;
	else if (option == 4 && data->map[player->x][player->y - 1] != '1')
		data->player->y -= 1;
	else
		data->moves--;
	data->moves++;
	check_move(data);
	mlx_put_image_to_window
		(data->mlx, data->win, data->character,
		32 * data->player->y, 32 * data->player->x);
	return (0);
}

int	read_map(char *path, t_data *data)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (-1);
	i = 1;
	data->map = malloc(sizeof(char *) * 2);
	data->map[0] = get_next_line(fd);
	data->map[1] = NULL;
	while (data->map[i - 1])
	{
		enlarge_char_tab(data);
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i - 1);
}

void	enlarge_char_tab(t_data *data)
{
	char	**returned;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (data->map[len])
		len++;
	returned = malloc (sizeof(char *) * (len + 2));
	while (i < len)
	{
		returned[i] = data->map[i];
		i++;
	}
	returned[i] = NULL;
	returned[i + 1] = NULL;
	free(data->map);
	data->map = returned;
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int	check_move(t_data *data)
{
	if (data->map[data->player->x][data->player->y] == 'C' &&
		data->player->x != 0 && data->player->y != 0)
	{
		data->collectibles--;
		data->map[data->player->x][data->player->y] = '0';
	}
	if (data->collectibles == 0 && data->map[data->player->x][data->player
		->y] == 'E' && data->player->x != 0 && data->player->y != 0)
		close_window(data);
	return (0);
}
