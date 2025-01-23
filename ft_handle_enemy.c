/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:52:44 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/23 18:42:26 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int		ft_init_enemys(t_data *game);
int		ft_enemy_anim(t_data *game);
void	ft_set_enemys(t_data *game);
void	ft_free_enemys(t_data *game);
*/

void	ft_set_enemys(t_data *game)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (game->map.map[i] && z < game->map.enemy)
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'T')
			{
				game->t_pos.x[z] = j;
				game->t_pos.y[z] = i;
				z++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_init_enemys(t_data *game)
{
	game->t_pos.x = malloc((game->map.enemy + 1) * sizeof(int));
	game->t_pos.y = malloc((game->map.enemy + 1) * sizeof(int));
	if (!game->t_pos.x || !game->t_pos.y)
		return (-1);
	game->t_pos.x[game->map.enemy] = 0;
	game->t_pos.y[game->map.enemy] = 0;
	ft_set_enemys(game);
	return (0);
}

int	ft_enemy_anim(t_data *game)
{
	static int	x;
	int			pixel;

	pixel = PIXEL;
	if (x <= 20000)
	{
		if (x == 10000)
		{
			mlx_destroy_image(game->mlx, game->img.enemy);
			game->img.enemy = mlx_xpm_file_to_image(game->mlx, \
			"./img/enemy.xpm", &pixel, &pixel);
			ft_render(game);
		}
		else if (x == 20000)
		{
			mlx_destroy_image(game->mlx, game->img.enemy);
			game->img.enemy = mlx_xpm_file_to_image(game->mlx, \
				"./img/enemy_m.xpm", &pixel, &pixel);
			ft_render(game);
			x = 0;
		}
		x++;
	}
	ft_move_enemy(game);
	return (0);
}

void	ft_free_enemys(t_data *game)
{
	free(game->t_pos.y);
	free(game->t_pos.x);
}

void	ft_change_enemy(t_data *game, int pixel, char dir)
{
	if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.enemy);
		game->img.enemy = mlx_xpm_file_to_image(game->mlx, \
			"./img/enemy_mr.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.enemy);
		game->img.enemy = mlx_xpm_file_to_image(game->mlx, \
			"./img/enemy_ml.xpm", &pixel, &pixel);
	}
	else if (dir == 'u')
	{
		mlx_destroy_image(game->mlx, game->img.enemy);
		game->img.enemy = mlx_xpm_file_to_image(game->mlx, \
			"./img/enemy_m.xpm", &pixel, &pixel);
	}
	else if (dir == 'd')
	{
		mlx_destroy_image(game->mlx, game->img.enemy);
		game->img.enemy = mlx_xpm_file_to_image(game->mlx, \
			"./img/enemy_mb.xpm", &pixel, &pixel);
	}
}
