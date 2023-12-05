/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:21:52 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/18 18:21:52 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>			//test purpose only
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_character
{
	void	*img;
	int		y;
	int		x;
}	t_character;

typedef	struct s_data
{
	void			*mlx;
	void			*win;
	void			*character;
	void			*obstacle;
	void			*enemy;
	void			*background;
	void			*goal;
	int				w;
	int				h;
	long			colectibles;
	long			moves;
	char			**map;
	t_character		*player;
}	t_data;

int		close_window(t_data *data);
void	init_textures(t_data *data);
void	set_background(int w, int h, t_data *data);
int		redraw(t_data *data);
int		check_key(int keycode, t_data *data);
int		game(t_data *data);
int		update_character(t_data *data, t_character *player, int option);
int		read_map(char *path, t_data *data);
void	enlarge_tab(t_data *data);
void	free_tab(t_data *data, int len);
void	print_tab(t_data *data);
void	set_pos(t_data *data);
void	put_misc(char c, t_data *data, int i, int j);
void	print_display(t_data *data);
int		check_move(t_data *data);
#endif