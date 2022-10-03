/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:28:36 by hawadh            #+#    #+#             */
/*   Updated: 2022/09/29 17:17:30 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	To manage red (x) to close window
**/
int	esc_win(t_info *info)
{
	free_data(info);
	exit(0);
	return (EXIT_SUCCESS);
}

/**
**	Handles pause button
**/
static void	handle_pause(t_info *inf)
{
	if (inf->mouse->flag == 0)
	{
		mlx_put_image_to_window(inf->mlx, inf->win, \
		inf->data->pause, WIDTH / 4, HEIGHT / 3);
		mlx_mouse_show(inf->mlx, inf->win);
		inf->mouse->flag = 1;
	}
	else if (inf->mouse->flag == 1)
	{
		inf->mouse->flag = 0;
		draw_map(inf);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
		mlx_put_image_to_window(
			inf->mlx, inf->win, inf->data->gun, WIDTH - HEIGHT, (HEIGHT / 2));
		mlx_put_image_to_window(inf->mlx, inf->win, inf->mini_map, 30, 30);
	}
}

int	controls(int keycode)
{
	if (keycode == W)
		return (TRUE);
	else if (keycode == A)
		return (TRUE);
	else if (keycode == S)
		return (TRUE);
	else if (keycode == D)
		return (TRUE);
	else if (keycode == ARROW_L)
		return (TRUE);
	else if (keycode == ARROW_R)
		return (TRUE);
	return (FALSE);
}

// void	init_wall_coll(t_info *inf)
// {
// 	inf->player->wall.count = 7;
// 	inf->player->wall.row = 0;
// 	inf->player->wall.col = 0;
// 	inf->player->wall.x = 0;
// 	inf->player->wall.y = 0;
// 	inf->player->wall.angle = 0;
// }

// void	wall_coll(t_info *inf, int *wall_trigger, double angle)
// {
// 	init_wall_coll(inf);
// 	*wall_trigger = 0;
// 	inf->player->wall.angle = inf->player->angle - (30 * (PI / 180));
// 	if (inf->player->wall.angle < 0)
// 		inf->player->wall.angle += 2 * PI;
// 	while (inf->player->wall.count > 0)
// 	{
// 		inf->player->wall.x = inf->player->x_pos + (cos(inf->player->wall.angle) * 0.125);
// 		inf->player->wall.y = inf->player->y_pos + (sin(inf->player->wall.angle) * 0.125);
// 		inf->player->wall.row = (int)inf->player->wall.x;
// 		inf->player->wall.col = (int)inf->player->wall.y;
// 		if (!inf->data->map[inf->player->wall.col][inf->player->wall.row]
// 			|| (inf->data->map[inf->player->wall.col][inf->player->wall.row]
// 			&& inf->data->map[inf->player->wall.col][inf->player->wall.row] == '1'))
// 			*wall_trigger = 1;
// 		inf->player->wall.angle += (10 * PI / 180);
// 		if (inf->player->wall.angle > 2 * PI)
// 			inf->player->wall.angle -= 2 * PI;
// 		inf->player->wall.count--;
// 	}
// }

// int	handle_wall_collision(t_info *inf)
// {
// 	double	angle;

// 	angle = inf->player->angle;
// 	wall_coll(inf, &inf->player->wall.wall_front, angle); //wall forward
// 	angle = inf->player->angle - PI;
// 	if (angle < 0)
// 		angle += 2 * PI;
// 	wall_coll(inf, &inf->player->wall.wall_back, angle); //wall back
// 	angle = inf->player->angle += (3 * PI / 2);
// 	if (angle > 2 * PI)
// 		angle -= 2 * PI;
// 	wall_coll(inf, &inf->player->wall.wall_left, angle); //wall left
// 	angle = inf->player->angle += (PI / 2);
// 	if (angle > 2 * PI)
// 		angle -= 2 * PI;
// 	wall_coll(inf, &inf->player->wall.wall_right, angle); //wall right
// 	return (0);
// }

/**
**	To manage key hooks (presses)
*	hook_num == 53			ESC
*	hook_num == 35			'p' (release mouse)
*	mouse->flag == 0;		Hide and reposition mouse
*	mouse->flag == 1;		Show and release mouse
**/
int	key_hook_manage(int hook_num, t_info *inf)
{
	if (hook_num == ESC)
	{
		esc_win(inf);
		exit(0);
	}
	if (hook_num == P)
		handle_pause(inf);
	if (controls(hook_num))
	{
		moves(hook_num, inf);
		draw_minimap(inf, inf->mini);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
		mlx_put_image_to_window(inf->mlx, inf->win,
			inf->data->gun, WIDTH - HEIGHT, (HEIGHT / 2));
		mlx_put_image_to_window(inf->mlx, inf->win, inf->mini_map, 30, 30);
	}
	printf("\n");
	printf("Degree Angle: %f\n", inf->player->angle * (180 / PI));
	printf("Radian Angle: %f\n", inf->player->angle);
	return (EXIT_SUCCESS);
}
