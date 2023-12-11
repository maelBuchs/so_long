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

// # include <stdio.h>			//test purpose only
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

typedef struct s_content
{
	int	exit;
	int	start;
	int	collectible;
	int	empty;
	int	obstacle;

}	t_content;

typedef struct s_data
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
	long			collectibles;
	long			moves;
	int				*bfs_visited;
	int				*collectibles_pos;
	int				*tab;
	char			**map;
	char			**bfs_map;
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
void	enlarge_char_tab(t_data *data);
void	free_tab(char **tab);
void	print_tab(char **tab);
void	put_misc(char c, t_data *data, int i, int j);
void	print_display(t_data *data);
int		check_move(t_data *data);
void	print_error(t_data *data, int error);
void	check_elements(t_data *data, t_content *content);
int		check_map(t_data *data);
void	fancy_error(t_data *data, t_content *content);
void	check_border(t_data *data);
void	get_player_pos(t_data *data);
void	bfs(t_data *data, int x, int y);
char	**dup_tab(t_data *data);
void	close_tabs(t_data *data);
int		ft_strlen_char(const char *s, char c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
int		split_map(t_data *data, char *str);
void init_struct(t_data *data);
void check_exension(char *str);
void	print_error_2(t_data *data, int error);
#endif