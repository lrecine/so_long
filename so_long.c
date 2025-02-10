/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:29:07 by lrecine-          #+#    #+#             */
/*   Updated: 2025/02/10 19:19:31 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		write(1, "Error\nInvalid number of arguments.\n", 35);
		return (0);
	}
	if (ft_check_error(&game, argv[1]) < 0)
		return (0);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		write(1, "Error\nMissing graphical interface.\n", 35);
		ft_free_map(&game);
		ft_free_enemys(&game);
		return (0);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * PIXEL, \
		game.map.height * PIXEL, "Ravel");
	ft_create_images(&game);
	mlx_loop_hook(game.mlx, &ft_enemy_anim, &game);
	mlx_expose_hook(game.win, &ft_render, &game);
	mlx_key_hook(game.win, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_press_x, &game);
	mlx_loop(game.mlx);
}
