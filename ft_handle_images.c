/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:53:06 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/23 15:14:36 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_player_c(t_data *game, int pixel, char dir);
void	ft_change_player(t_data *game, int pixel, char dir);
void	ft_create_images(t_data *game);
void	ft_create_player(t_data *game, int pixel);
void	ft_clear_images(t_data *game);

void	ft_change_player_c(t_data *game, int pixel, char dir)
{
	if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./img/player_r.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./img/player_mr.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./img/player_l.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./img_player_ml.xpm", &pixel, &pixel);
	}
}

void	ft_change_player(t_data *game, int pixel, char dir)
{
	if (game->sock == 1)
		ft_change_player_c(game, pixel, dir);
	else if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./img/player_r.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./img/player_mr.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./img/player_l.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./img_player_ml.xpm", &pixel, &pixel);
	}
}

void	ft_create_images(t_data *game)
{
	int	pixel;

	pixel = PIXEL;
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./img/background1.xpm", \
		&pixel, &pixel);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", \
		&pixel, &pixel);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectible.xpm", &pixel, &pixel);
	game->img.trap = mlx_xpm_file_to_image(game->mlx, "./img_enemy.xpm", \
		&pixel, &pixel);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"./img/exit.xpm", &pixel, &pixel);
	ft_create_player(game, pixel);
}

void	ft_create_player(t_data *game, int pixel)
{
	game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
		"./img/player.xpm", &pixel, &pixel);
	game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
		"./img/player_m1.xpm", &pixel, &pixel);
}

void	ft_clear_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img.player_0);
	mlx_destroy_image(game->mlx, game->img.player_1);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.collectible);
	mlx_destroy_image(game->mlx, game->img.trap);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.exit);
	free(game->t_pos.y);
	free(game->t_pos.x);
}
