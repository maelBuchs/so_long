/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 01:12:01 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/10 01:12:01 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_data *data, int error)
{
	if (error == 0 || error == 3){
		ft_putstr_fd("Error\nmissing a map element (0/1/C/E/P)\n", 1);
		free_tab(data->map, 2);
	}
	else if (error == 1)
	{
		ft_putstr_fd("Error\ntoo many exits!! (i know shrek \
is big but he does not need more than 1 exit)\n", 1);
		free_tab(data->map, 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("Error\ntoo many starting point \
(i cannot split shrek in half !)\n", 1);
	free_tab(data->map, 2);
	}
	else if (error == 4){
		ft_putstr_fd("Error\nu didn't close the map, \
shrek ran away...(or the map isnt a rectangle...)\n", 1);
free_tab(data->map, 2);
	}
	else
		print_error_2(data, error);
	if (error == 3)
		close_window(data);
	exit (0);
}

void	print_error_2(t_data *data, int error)
{
	
	if (error == 5){
		ft_putstr_fd("Error\nshrek has been slayed by a mysterious character \
(wtf is this input ?)(WAIT YOU KILLED SHREK ? \
I HATE YOU, YOU SHOULD KYS)\n", 1);
free_tab(data->map, 2);
	}
	if (error == 6){
		ft_putstr_fd("Error\nwe're in a dimension where shrek does not exist, life is sad \
(you forgot to put a 'P ')\n", 1);
free_tab(data->map, 2);
	}
	if (error == 7)
		ft_putstr_fd("Error\nshrek cannot is stuck by a wall and he cannot take the donkey or \
join the toilets.\nhe's sad\nhope u'r proud of you...\n\
(check if the map is solvable)\n", 1);
	if (error == 8)
		ft_putstr_fd("Error\nthe map was too crazy for shrek (invalid map format)\n", 1);
	if (error == 10)
	{
		ft_putstr_fd("Error\nthis isnt a real rectangle or one line is empty1...\n", 1);
		if (data->map)
			free_tab(data->map, 2);
	}
	if (error == 7)
		close_window(data);
	exit (0);
}

// void	print_error_3(t_data *data, int error)