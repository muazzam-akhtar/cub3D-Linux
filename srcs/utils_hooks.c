/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:28:36 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/24 17:37:24 by hawadh           ###   ########.fr       */
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
		inf->data->pause, WIDTH / 4 - 200, HEIGHT / 3);
		mlx_mouse_show(inf->mlx, inf->win);
		inf->mouse->flag = 1;
	}
	else if (inf->mouse->flag == 1)
	{
		inf->mouse->flag = 0;
		draw_map(inf);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
		mlx_put_image_to_window(inf->mlx, inf->win,
			inf->data->gun, (WIDTH / 2) - 75, (HEIGHT / 2));
		mlx_put_image_to_window(inf->mlx, inf->win, inf->mini_map, 30, 30);
	}
}

int	controls(int keycode)
{
	if (keycode == W)
		return (TRUE);
	if (keycode == A)
		return (TRUE);
	if (keycode == S)
		return (TRUE);
	if (keycode == D)
		return (TRUE);
	if (keycode == ARROW_L)
		return (TRUE);
	if (keycode == ARROW_R)
		return (TRUE);
	if (keycode == SHIFT_KEY)
		return (TRUE);
	if (keycode == E)
		return (TRUE);
	return (FALSE);
}

static void	handle_integration(int hook_num, t_info *inf)
{
	if (hook_num == SHIFT_KEY)
	{
		if (inf->player->speed == SPEED_F)
			inf->player->speed = SPEED_L;
		else
			inf->player->speed = SPEED_F;
	}
	else if (hook_num == E)
	{
		inf->integrate = 1;
	}
}

/**
**	To manage key hooks (presses)
*	hook_num == 53			ESC
*	hook_num == 35			'p' (release mouse)
*	mouse->flag == 0;		Hide and reposition mouse
*	mouse->flag == 1;		Show and release mouse
**/
int	key_hook_manage(int hook_num, t_info *inf)
{
	inf->integrate = 0;
	if (hook_num == ESC)
	{
		esc_win(inf);
		exit(0);
	}
	if (hook_num == P)
		handle_pause(inf);
	if (controls(hook_num) && inf->mouse->flag == 0)
	{
		handle_integration(hook_num, inf);
		moves(hook_num, inf);
		draw_minimap(inf, inf->mini);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
		mlx_put_image_to_window(inf->mlx, inf->win,
			inf->mini_map, 30, 30);
		gun_image(inf);
	}
	return (EXIT_SUCCESS);
}
