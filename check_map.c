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

	return 0;
}

void	check_elements(t_data *data, t_content *content)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->w)
	{
		j = 0;
		while (j < data->h)
		{
			if (data->map[i][j] == 'E')
				content->exit++;
			if (data->map[i][j] == 'P')
				content->start++;
			if (data->map[i][j] == '0')
				content->empty++;
			if (data->map[i][j] == 'C')
				content->collectible++;
			j++;
		}
		i++;
	}
	if (content->exit == 1 && content->start == 1 && content->collectible > 0)
		return;
	fancy_error(data, content);
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
	if(error == 0 || error == 3)
		ft_putstr_fd("Error\nmissing a map element (0/1/C/E/P)\n", 1);
	if(error == 1)
		ft_putstr_fd("Error\ntoo many exits!! (i know shrek is big but he does not need more than 1 exit)\n", 1);
	if(error == 2)
		ft_putstr_fd("Error\ntoo many starting point (i cannot split shrek in half !)\n", 1);
	if(error == 3)
		close_window(data);
	exit (0);
}