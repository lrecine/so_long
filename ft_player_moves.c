/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:50:25 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/23 16:22:25 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	ft_move_up(t_data *game);
void	ft_move_down(t_data *game);
void	ft_move_right(t_data *game);
void	ft_move_left(t_data *game);
void	ft_move(int key, t_data *game);
*/

void	ft_move_up(t_data *game)
{
	if (game->map.map[game->p_pos.y - 1][game->p_pos.x] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'C'\
		|| game->map.map[game->p_pos.y - 1][game->p_pos.x] == '0')
		{
			if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'C')
			{
				game->map.collectible--;
				game->gas = 1;
				ft_change_player(game, PIXEL, game->dir);
			}
			game->map.map[game->p_pos.y - 1][game->p_pos.x] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.y--;
			ft_render(game);
		}
		else if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'T')
			ft_game_over(game);
		else if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'E')
			ft_check_winner(game);
	}
}

void	ft_move_down(t_data *game)
{
	if (game->map.map[game->p_pos.y + 1][game->p_pos.x] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'C'\
		|| game->map.map[game->p_pos.y + 1][game->p_pos.x] == '0')
		{
			if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'C')
			{
				game->map.collectible--;
				game->gas = 1;
				ft_change_player(game, PIXEL, game->dir);
			}
			game->map.map[game->p_pos.y + 1][game->p_pos.x] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.y++;
			ft_render(game);
		}
		else if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'T')
			ft_game_over(game);
		else if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'E')
			ft_check_winner(game);
	}
}

void	ft_move_right(t_data *game)
{
	ft_change_player(game, PIXEL, 'r');
	if (game->map.map[game->p_pos.y][game->p_pos.x + 1] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'C'\
		|| game->map.map[game->p_pos.y][game->p_pos.x + 1] == '0')
		{
			if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'C')
			{
				game->map.collectible--;
				game->gas = 1;
				ft_change_player(game, PIXEL, game->dir);
			}
			game->map.map[game->p_pos.y][game->p_pos.x + 1] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.x++;
			ft_render(game);
		}
		else if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'T')
			ft_game_over(game);
		else if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'E')
			ft_check_winner(game);
	}
}

void	ft_move_left(t_data *game)
{
	ft_change_player(game, PIXEL, 'l');
	if (game->map.map[game->p_pos.y][game->p_pos.x - 1] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'C'\
		|| game->map.map[game->p_pos.y][game->p_pos.x - 1] == '0')
		{
			if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'C')
			{
				game->map.collectible--;
				game->gas = 1;
				ft_change_player(game, PIXEL, game->dir);
			}
			game->map.map[game->p_pos.y][game->p_pos.x - 1] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.x--;
			ft_render(game);
		}
		else if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'T')
			ft_game_over(game);
		else if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'E')
			ft_check_winner(game);
	}
}

void	ft_move(int key, t_data *game)
{
	if (key == 'w' || key == UP)
		ft_move_up(game);
	else if (key == 's' || key == DOWN)
		ft_move_down(game);
	else if (key == 'd' || key == RIGHT)
	{
		game->dir = 'r';
		ft_move_right(game);
	}
	else if (key == 'a' || key == LEFT)
	{
		game->dir = 'l';
		ft_move_left(game);
	}
}
