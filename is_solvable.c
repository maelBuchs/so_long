/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:56:48 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/08 22:45:32 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->w)
	{
		j = -1;
		while (++j < data->h)
		{
			if (data->map[i][j] == 'P')
			{
				data->player->x = j;
				data->player->y = i;
				return ;
			}
		}
	}
	print_error(data, 6);
}

char	**dup_tab(t_data *data)
{
	char	**returned;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (data->map[len])
		len++;
	returned = malloc (sizeof(char *) * (len + 1));
	while (i < len)
	{
		returned[i] = ft_strdup(data->map[i]);
		i++;
	}
	returned[i] = 0;
	return (returned);
}

void	bfs(t_data *data, int y, int x)
{
	if (data->bfs_map[x][y] != '1' && data->bfs_map[x][y] != 'A')
		data->bfs_map[x][y] = 'A';
	if (data->bfs_map[x + 1][y] != '1' && data->bfs_map[x + 1][y] != 'A')
		bfs(data, y, x + 1);
	if (data->bfs_map[x - 1][y] != '1' && data->bfs_map[x - 1][y] != 'A')
		bfs(data, y, x - 1);
	if (data->bfs_map[x][y + 1] != '1' && data->bfs_map[x][y + 1] != 'A')
		bfs(data, y + 1, x);
	if (data->bfs_map[x][y - 1] != '1' && data->bfs_map[x][y - 1] != 'A')
		bfs(data, y - 1, x);
}

void	check_elements(t_data *data, t_content *content)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->w)
	{
		j = -1;
		while (++j < data->h)
		{
			if (data->map[i][j] == 'E')
				content->exit++;
			else if (data->map[i][j] == 'P')
				content->start++;
			else if (data->map[i][j] == '0')
				content->empty++;
			else if (data->map[i][j] == 'C')
				content->collectible++;
			else if (data->map[i][j] != '1')
				print_error(data, 5);
		}
	}
	if (content->exit == 1 && content->start == 1
		&& content->collectible > 0)
		return ;
	fancy_error(data, content);
}
