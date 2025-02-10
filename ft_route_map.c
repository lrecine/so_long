/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:30:55 by lrecine-          #+#    #+#             */
/*   Updated: 2025/02/10 19:24:45 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *game, int x, int y)
{

	if (game->map.route[y][x] == '0' ||
		game->map.route[y][x] == 'C' ||
		game->map.route[y][x] == 'E' ||
		game->map.route[y][x] == 'P' ||
		game->map.route[y][x] == 'T')
	{
		game->map.route[y][x] = 'V';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

int	ft_is_route_valid(t_data *game, char *file)
{
	int	i;
	int	j;

	if (ft_set_route_map_layout(game, file) < 0)
		return (-1);
	ft_init_positions(game, 0, 0);
	flood_fill(game, game->p_pos.x , game->p_pos.y);
	i = 0;
	while (game->map.route[i])
	{
		j = 0;
		while (game->map.route[i][j])
		{
			if (game->map.route[i][j] == 'E' ||
				game->map.route[i][j] == 'C')
			{
				write(1, "Error\nInvalid route\n", 21);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_set_route_map_layout(t_data *game, char *file)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	game->map.route = malloc(sizeof(char *) * (game->map.height + 1));
	game->map.route[game->map.height] = NULL;
	if (!game->map.route)
		return (-1);
	while (i < game->map.height)
	{
		game->map.route[i] = get_next_line(fd);
		i++;
	}
	return (0);
}
