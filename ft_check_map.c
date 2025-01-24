/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:55:53 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/24 15:41:00 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	ft_init_positions(t_data *game, int i, int j);
int	ft_check_requirements(t_data *game);
int	ft_check_extention(const char *file);
int	ft_set_map_layout(t_data *game, char *file);
void	ft_init_map_layout(t_data *game);
*/

void	ft_init_map_layout(t_data *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player = 0;
	game->map.collectible = 0;
	game->map.enemy = 0;
	game->map.exit = 0;
	game->moves = 0;
	game->gas = 0;
	game->dir = 'r';
}

int	ft_check_requirements(t_data *game)
{
	if (game->map.player != 1)
	{
		write(1, "Error\nNot enough players!, or contains more than one\n", 53);
		return (-1);
	}
	if (game->map.exit != 1)
	{
		write(1, "Error\nNot enough exits!, or contains more than one\n", 51);
		return (-1);
	}
	if (game->map.collectible < 1)
	{
		write(1, "Error\nNot enough collectibles!\n", 31);
		return (-1);
	}
	return (0);
}

int	ft_check_extention(const char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	if (ft_strncmp(&file[i], ".ber", 5) != 0)
	{
		write(1, "Invalid Extention.\n", 19);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nThere's no map with that name.\n", 37);
		return (-1);
	}
	close(fd);
	return (0);
}

int	ft_set_map_layout(t_data *game, char *file)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = ft_calloc(1, 1);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strjoin_gnl(tmp, line);
		i++;
		free(line);
	}
	ft_set_stats(game, tmp);
	if (ft_check_requirements(game) < 0)
	{
		free(tmp);
		return (-1);
	}
	ft_get_map_width(game, tmp);
	ft_write_map(game, tmp);
	free(tmp);
	return (0);
}

int	ft_init_positions(t_data *game, int i, int j)
{
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				game->p_pos.x = j;
				game->p_pos.y = i;
			}
			else if (ft_strchr("1PTEC0", game->map.map[i][j]) == NULL)
			{
				write(1, "Error\nInvalid input on map.\n", 28);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_init_enemys(game) < 0)
		return (-1);
	return (0);
}
