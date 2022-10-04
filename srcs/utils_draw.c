/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:06:53 by hawadh            #+#    #+#             */
/*   Updated: 2022/10/04 17:20:46 by makhtar          ###   ########.fr       */
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
	while (y < 361)
	{
		x = 0;
		while (x < 1920)
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

	y = 361;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
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
