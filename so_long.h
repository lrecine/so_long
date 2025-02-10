/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:25:08 by lrecine-          #+#    #+#             */
/*   Updated: 2025/02/10 19:24:15 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define PIXEL	96
# define ESC	65307

// for moving with the keyboard arrows:
# define UP		0xff52
# define DOWN	0xff54
# define LEFT	0xff51
# define RIGHT	0xff53

typedef struct s_enemy
{
	int	*x;
	int	*y;
}	t_enemy;

typedef struct s_map
{
	char	**map;
	char	**route;
	int		width;
	int		height;
	int		player;
	int		collectible;
	int		enemy;
	int		exit;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_image
{
	void	*player_0;
	void	*player_1;
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*enemy;
	void	*exit;
}	t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	p_pos;
	t_map		map;
	t_image		img;
	t_enemy		t_pos;
	int			moves;
	int			gas;
	char		dir;
}	t_data;

//functions for checking input errors
int		ft_check_rectangle(t_data *game);
int		ft_middle_walls(t_data *game, int y);
int		ft_first_last_walls(t_data *game, int y, int x);
int		ft_check_walls(t_data *game);
int		ft_check_error(t_data *game, char *file);
int		ft_check_requirements(t_data *game);
int		ft_check_extention(const char *file);

//functions for layout inicialization or release
int		ft_init_positions(t_data *game, int i, int j);
int		ft_set_map_layout(t_data *game, char *file);
void	ft_init_map_layout(t_data *game);
void	ft_count_map_rows(t_data *game, char *file);
void	ft_set_stats(t_data *game, char *tmp);
void	ft_get_map_width(t_data *game, char *tmp);
void	ft_write_map(t_data *game, char *tmp);
void	ft_free_map(t_data *game);

//functions that handles the player
void	ft_move_up(t_data *game);
void	ft_move_down(t_data *game);
void	ft_move_right(t_data *game);
void	ft_move_left(t_data *game);
void	ft_move(int key, t_data *game);

//functions that handles the enemys
int		ft_init_enemys(t_data *game);
int		ft_enemy_anim(t_data *game);
int		ft_move_enemy_down(t_data *game, int i);
int		ft_move_enemy_left(t_data *game, int i);
int		ft_move_enemy_right(t_data *game, int i);
int		ft_move_enemy_up(t_data *game, int i);
int		ft_move_enemy(t_data *game);
void	ft_set_enemys(t_data *game);
void	ft_free_enemys(t_data *game);
void	ft_change_enemy(t_data *game, int pixel, char dir);

//functions that handles drawing
int		ft_render(t_data *game);
void	ft_create_player(t_data *game, int pixel);
void	ft_draw_map(t_data *game, int x, int y);
void	ft_open_exit(t_data *game, int pixel);
void	ft_change_player_c(t_data *game, int pixel, char dir);
void	ft_change_player(t_data *game, int pixel, char dir);
void	ft_create_images(t_data *game);
void	ft_clear_images(t_data *game);

//functions that handles events
int		ft_press_x(t_data *game);
int		ft_key_press(int key, t_data *game);
void	ft_game_over(t_data *game);
void	ft_check_winner(t_data *game);

//functions that handles the route
void	flood_fill(t_data *game, int x, int y);
int		ft_is_route_valid(t_data *game, char *file);
int		ft_set_route_map_layout(t_data *game, char *file);

#endif