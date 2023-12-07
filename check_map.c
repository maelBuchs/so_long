/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:48:51 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/07 05:48:51 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_data *data)
{
	t_content	content;

	content.exit = 0;
	content.start = 0;
	content.collectible = 0;
	content.empty = 0;
	content.obstacle = 0;
	check_elements(data, &content);
	check_border(data);
	return (0);
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

void	check_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->w)
	{
		j = 0;
		while (j < data->h)
		{
			if (((i == 0 || j == 0 || i == data->w - 1 || j == data->h - 1))
				&& data->map[i][j] != '1')
				print_error(data, 4);
			j++;
		}
		i++;
	}
}

void	fancy_error(t_data *data, t_content *content)
{
	if (content->exit > 1)
		print_error(data, 1);
	if (content->start > 1)
		print_error(data, 2);
	print_error(data, 0);
}

void	print_error(t_data *data, int error)
{
	if (error == 0 || error == 3)
		ft_putstr_fd("Error\nmissing a map element (0/1/C/E/P)\n", 1);
	if (error == 1)
		ft_putstr_fd("Error\ntoo many exits!! (i know shrek \
is big but he does not need more than 1 exit)\n", 1);
	if (error == 2)
		ft_putstr_fd("Error\ntoo many starting point \
(i cannot split shrek in half !)\n", 1);
	if (error == 3)
		close_window(data);
	if (error == 4)
		ft_putstr_fd("Error\nu didn't close the map, \
shrek ran away...(or the map isnt a rectangle...)\n", 1);
	if (error == 5)
		ft_putstr_fd("Error\nshrek has been slayed by a mysterious character\
(wtf is this input ???)(WAIT YOU KILLED SHREK ??? I HATE YOU FR)", 1);
	exit (0);
}

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while(++i < data->w)
	{
		j = -1;
		while(++j < data->h)
		{
			if (data->map[i][j] == 'P')
			{
				data->player->x = j;
				data->player->y = i;
			}
		}

	}
}


void	bfs(t_data *data, char **map)
{

}