/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:50:25 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/22 18:54:46 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_img(t_vars **vars)
{
	int			img_w;
	int			img_h;

	(*vars)->e_vars.imgs[0] = "./img/enemy.xpm";
	(*vars)->e_vars.imgs[1] = "./img/enemy_b.xpm";
	(*vars)->e_vars.imgs[2] = "./img/enemy_l.xpm";
	(*vars)->e_vars.imgs[3] = "./img/enemy_r.xpm";
	(*vars)->e_vars.imgs[4] = "./img/enemy_m.xpm";
	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx, "./img/background1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx, (*vars)->win, (*vars)->img,
		(*vars)->e_vars.x_e * 50, (*vars)->e_vars.y_e * 50);
	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx, (*vars)->e_vars.imgs[(*vars)->e_vars.x],
			&img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx, (*vars)->win, (*vars)->img,
		(*vars)->e_vars.x_e * 50, (*vars)->e_vars.y_e * 50);
}

void	move_enemy(t_vars **vars)
{
	int			img_w;
	int			img_h;

	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx, "./img/background1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx, (*vars)->win, (*vars)->img,
		(*vars)->e_vars.x_e * 50, (*vars)->e_vars.y_e * 50);
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 0)
		(*vars)->e_vars.x_e++;
	else
		(*vars)->e_vars.path_to_move = 1;
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 1)
		(*vars)->e_vars.x_e--;
	else
		(*vars)->e_vars.path_to_move = 0;
}

static void	ft_lose(t_vars **v, char *err)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	printf("%s", err);
	exit(0);
}

int	animation(t_vars *vars)
{
	if (get_position_for_enemy(&vars) != 0)
	{
		if (vars->e_vars.sleep-- <= 0)
		{
			vars->e_vars.x++;
			vars->e_vars.sleep = 5;
		}
		if (vars->e_vars.x == 3)
			vars->e_vars.x = 0;
		if (vars->e_vars.sleep_for_move-- <= 0)
		{
			move_enemy(&vars);
			vars->e_vars.sleep_for_move = 30;
		}
		if ((vars->e_vars.y_e == vars->y_p / 50)
			&& (vars->e_vars.x_e == vars->x_p / 50))
		{
			ft_lose(&vars, "You Lose :(");
		}
		render_img(&vars);
	}
	if (vars->collect <= 0)
		open_exit(&vars);
	return (0);
}
