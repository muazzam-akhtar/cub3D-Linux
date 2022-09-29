/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:05:19 by hawadh            #+#    #+#             */
/*   Updated: 2022/09/29 16:00:06 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws remaining crosshair
**/
void	crosshair_handler(t_info *inf)
{
	int	i;
	int	x;
	int	y;

	i = -20;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	while (i <= -3)
	{
		my_pixel_put(inf, x, y + i, 0x0000FF00);
		i++;
	}
	i = -20;
	while (i <= -3)
	{
		my_pixel_put(inf, x + i, y, 0x0000FF00);
		i++;
	}
}

/**
**	Inits and draws crosshair
**/
void	init_cursor(t_info *inf)
{
	int	i;
	int	x;
	int	y;

	i = 3;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	while (i < 20)
	{
		my_pixel_put(inf, x + i, y, 0x0000FF00);
		i++;
	}
	i = 3;
	while (i < 20)
	{
		my_pixel_put(inf, x, y + i, 0x0000FF00);
		i++;
	}
	crosshair_handler(inf);
}

/**
**	Mouse event trigger manager
*	mouse->flag == 0;		Hide and reposition mouse
*	mouse->flag == 1;		Show and release mouse
**/
int	mouse_move(int x, int y, t_info *info)
{
	init_rays(info);
	if (info->mouse->flag == 0)
	{
		mlx_mouse_get_pos(info->win, &x, &y);
		init_cursor(info);
		mlx_mouse_hide(info->mlx, info->win);
		mlx_mouse_move(info->win, 960, 540);
		if (x < 960)
			rotation(ARROW_L, info);
		else if (x > 960)
			rotation(ARROW_R, info);
	}
	else
		mlx_mouse_show(info->mlx, info->win);
	init_rays(info);
	return (EXIT_SUCCESS);
}

/**
**	Initialises Mouse cursor on start
**/
int	init_mouse(t_info *info)
{
	if (!info->mouse)
		info->mouse = (t_mouse *)ft_calloc(1, sizeof(t_mouse));
	if (!info->mouse)
	{
		free_data(info);
		err_return(4, info);
	}
	info->mouse->flag = 0;
	init_cursor(info);
	mlx_mouse_hide(info->mlx, info->win);
	return (EXIT_SUCCESS);
}
