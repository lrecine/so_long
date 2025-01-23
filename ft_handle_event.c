/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:54:26 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/23 15:09:45 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_press_x(t_data *game);
int		ft_key_press(int key, t_data *game);
void	ft_game_over(t_data *game);
void	ft_check_winner(t_data *game);

void	ft_check_winner(t_data *game)
{
	if (game->map.collectible == 0)
	{
		write(1, "Congratilations! You win!\n", 26);
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_game_over(t_data *game)
{
	write(1, "You lose.\n", 10);
	ft_clear_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_FAILURE);
}

int	ft_key_press(int key, t_data *game)
{
	if (key == ESC)
	{
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else
		ft_move(key, game);
	return (0);
}

int	ft_press_x(t_data *game)
{
	ft_key_press(ESC, game);
	return (0);
}
