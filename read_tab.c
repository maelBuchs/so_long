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
		32 * player->x, 32 * player->y);
	if (data->map[player->y][player->x] == 'E')
		mlx_put_image_to_window
			(data->mlx, data->win, data->goal,
			32 * player->x, 32 * player->y);
	if (option == 4 && data->map[player->y][player->x - 1] != '1')
		data->player->x -= 1;
	else if (option == 3 && data->map[player->y + 1][player->x] != '1')
		data->player->y += 1;
	else if (option == 2 && data->map[player->y][player->x + 1] != '1')
		data->player->x += 1;
	else if (option == 1 && data->map[player->y - 1][player->x] != '1')
		data->player->y -= 1;
	else
		data->moves--;
	data->moves++;
	check_move(data);
	mlx_put_image_to_window
		(data->mlx, data->win, data->character,
		32 * data->player->x, 32 * data->player->y);
	return (0);
}

int	read_map(char *path, t_data *data)
{
	int		fd;
	int		rd_l;
	char	buffer[101];
	char	*str;
	int		i;

	str = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	rd_l = read(fd, buffer, 100);
	if (!rd_l)
		return (0);
	while (rd_l > 0)
	{
		buffer[rd_l] = 0;
		str = ft_strjoin_free(str, buffer);
		rd_l = read(fd, buffer, 100);
	}
	i = split_map(data, str);
	if (str)
		free(str);
	return (i);
}

int	split_map(t_data *data, char *str)
{
	int	i;
	int len;

	i = 0;
	data->map = ft_split(str, '\n');
	len = ft_strlen_char(data->map[0], '\r');
	while (data->map[i])
	{
		if (ft_strlen_char(data->map[i], '\r') !=  len)
			return (0);
		data->map[i][len] = 0;
		i++;
	}
	return (i);
}

int	ft_strlen_char(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	check_move(t_data *data)
{
	if (data->map[data->player->y][data->player->x] == 'C' &&
		data->player->x != 0 && data->player->y != 0)
	{
		data->collectibles--;
		data->map[data->player->y][data->player->x] = '0';
	}
	if (data->collectibles == 0 && data->map[data->player->y][data->player
		->x] == 'E' && data->player->x != 0 && data->player->y != 0)
		close_window(data);
	return (0);
}
