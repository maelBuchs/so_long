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
	get_player_pos(data);
	check_elements(data, &content);
	check_border(data);
	data->bfs_map = dup_tab(data);
	bfs(data, data->player->x, data->player->y);
	return (0);
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
		ft_putstr_fd("Error\nshrek has been slayed by a mysterious character \
(wtf is this input ?)(WAIT YOU KILLED SHREK ? \
I HATE YOU, YOU SHOULD KYS)\n", 1);
	if (error == 6)
		ft_putstr_fd("Error\nwe're in a dimension where shrek does not exist, life is sad \
(you forgot to put a 'P ')\n", 1);
	if (error == 7)
		ft_putstr_fd("Error\nshrek cannot is stuck by a wall and he cannot take the donkey or \
join the toilets.\nhe's sad\nhope u'r proud of you...\n\
(check if the map is solvable)\n", 1);
	exit (0);
}
