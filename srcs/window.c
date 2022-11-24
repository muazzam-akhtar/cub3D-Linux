/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:48:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/24 12:03:52 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Calls image data address to draw into img
**/
static void	get_img_addr(t_info *inf)
{
	t_img	*image;

	image = (t_img *)ft_calloc(1, sizeof(t_img));
	inf->image = image;
	inf->img = mlx_new_image(inf->mlx, WIDTH, HEIGHT);
	if (!inf->image)
	{
		free_data(inf);
		err_return(4, inf);
	}
	image->addr = mlx_get_data_addr(inf->img, &image->bitspix,
			&image->len, &image->end);
	if (!image->addr)
		err_return(4, inf);
}

/**
**	Calls all functions to initialise all
*	init_player();		finds player pos in 2D array
*	init_mouse();		inits mouse and crosshair
*	init_minimap();		Includes struct
*	init_xpm();			all xpm images and their addresses
**/
static void	init_all(t_info *info)
{
	init_player(info);
	init_mouse(info);
	init_minimap(info);
	if (init_xpm(info, info->data))
		err_return(5, info);
}

/**
**	Initialises window, get's img address and hook management
**	mlx_loop();	here
**/
int	init_window(t_info *info)
{
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!info->win)
		return (EXIT_FAILURE);
	get_img_addr(info);
	init_all(info);
	hook_management(info);
	draw_map(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win,
		info->data->gun, (WIDTH / 2) - 75, (HEIGHT / 2));
	mlx_put_image_to_window(info->mlx, info->win, info->mini_map, 30, 30);
	mlx_loop(info->mlx);
	return (EXIT_SUCCESS);
}
