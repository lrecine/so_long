/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:56:11 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/24 15:30:47 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	ft_check_rectangle(t_data *game);
int	ft_middle_walls(t_data *game, int y);
int	ft_first_last_walls(t_data *game, int y, int x);
int	ft_check_walls(t_data *game);
int	ft_check_error(t_data *game, char *file);
*/

int	ft_check_rectangle(t_data *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if (ft_strlen(game->map.map[y]) != (size_t)game->map.width)
		{
			write(1, "Error\nMap's not rectangle.\n", 27);
			return (-1);
		}
		if ((size_t)game->map.height > (size_t)game->map.width)
		{
			write(1, "Error\nMap's not rectangle.\n", 27);
			return (-1);
		}
		else if ((size_t)game->map.height == (size_t)game->map.width)
		{
			write(1, "Error\nMap's not rectangle.\n", 27);
			return (-1);
		}
		y++;
	}
	return (0);
}

int	ft_middle_walls(t_data *game, int y)
{
	if (game->map.map[y][0] != '1')
	{
		write(1, "Error\nMap's walls are not closed.\n", 34);
		return (-1);
	}
	if (game->map.map[y][game->map.width - 1] != '1')
	{
		write(1, "Error\nMap's walls are not closed.\n", 34);
		return (-1);
	}
	return (0);
}

int	ft_first_last_walls(t_data *game, int y, int x)
{
	while (game->map.map[y][x])
	{
		if (game->map.map[y][x] != '1')
		{
			write(1, "Error\nMap's walls are not closed.\n", 34);
			return (-1);
		}
		x++;
	}
	return (0);
}

int	ft_check_walls(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y])
	{
		if (y == 0 || y == (game->map.height - 1))
		{
			if (ft_first_last_walls(game, y, x) < 0)
				return (-1);
		}
		else
		{
			if (ft_middle_walls(game, y) < 0)
				return (-1);
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_check_error(t_data *game, char *file)
{
	if (ft_check_extention(file) < 0)
		return (-1);
	ft_init_map_layout(game);
	ft_count_map_rows(game, file);
	if (ft_set_map_layout(game, file) < 0)
		return (-1);
	if (ft_check_rectangle(game) < 0 || ft_check_walls(game) < 0)
	{
		ft_free_map(game);
		return (-1);
	}
	if (ft_init_positions(game, 0, 0) < 0)
	{
		ft_free_map(game);
		free(game->t_pos.x);
		free(game->t_pos.y);
		return (-1);
	}
	return (0);
}
