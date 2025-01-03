/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:25:08 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/03 14:19:11 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy_vars;

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
	t_enemy_vars	e_vars;
}	t_vars;

typedef struct s_vars_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_vars;

char	**get_map(char *fmap);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_join_strings(char const *s1, char const *s2);
int		animation(t_vars *vars);
int		get_height(char **map);
int		get_position_for_enemy(t_vars **vars);
void	to_left(t_vars **v);
void	to_right(t_vars **v);
void	to_up(t_vars **v);
void	to_down(t_vars **v);
void	put_image(t_vars ***v, int x, int y, char *img);
void	put_text(t_vars ***v);
void	put_image_to_map(char p, int x1, int y1, t_vars **v);
void	check_map_valid(t_vars *vars);
void	check_file_is_valid(char *file_line);
void	check_elements(t_vars **vars);
void	ft_error(t_vars ***v, char *err);
void	open_exit(t_vars **vars);
void	exit_door(t_vars ***v);

#endif