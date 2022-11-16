/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:06:53 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/16 16:06:49 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Loops calls my_pixel_put();
*	rgb();	status 0: call to calculate
*			colour for ceiling
**/
static void	draw_ceiling(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			my_pixel_put(info, x++, y, rgb(info->data, 0));
		y++;
	}
}

/**
**	Loops calls my_pixel_put();
*	rgb();	status 1: call to calculate
*			colour for floor
**/
static void	draw_floor(t_info *info)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_pixel_put(info, x++, y, rgb(info->data, 1));
		y++;
	}
}

/**
**	Loops for drawing Ceiling and Floor
**/
void	ceiling_floor(t_info *info)
{
	draw_ceiling(info);
	draw_floor(info);
}
