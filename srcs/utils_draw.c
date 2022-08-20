/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:06:53 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/12 18:12:59 by hawadh           ###   ########.fr       */
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
	while (y < 541)
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

	y = 541;
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
