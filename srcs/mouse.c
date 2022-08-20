/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:05:19 by hawadh            #+#    #+#             */
/*   Updated: 2022/08/14 19:32:46 by makhtar          ###   ########.fr       */
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
	x = 960;
	y = 540;
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
	x = 960;
	y = 540;
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
	mlx_mouse_get_pos(info->mlx, info->win, &x, &y);
	if (info->mouse->flag == 0)
	{
		init_cursor(info);
		mlx_mouse_move(info->mlx, info->win, x, 540);
		mlx_mouse_hide(info->mlx, info->win);
	}
	else
		mlx_mouse_show(info->mlx, info->win);
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
