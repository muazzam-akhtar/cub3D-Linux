/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:45:56 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/25 19:11:58 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	check_open(char *map_icon)
{
	if (*map_icon == 'O')
		return (0x0039FF14);
	return (0x00FF0000);
}

/**
**	Draws minimap doors vertically
**/
void	draw_mini_doors_vertical(t_info *info, int x, int y, char *map_icon)
{
	int	y_brdr;
	int	y_one;
	int	x_one;
	int	x_rst;

	y_brdr = y;
	y_one = y + MINI_SCALE;
	while (y < y_one - 1)
	{
		x_rst = x;
		x_one = x_rst + (MINI_SCALE / 2);
		while (x_rst < x_one)
		{
			if (x_rst > 2 && x_rst < MINI_DIM - 3 && y > 2 && y < MINI_DIM - 3)
			{
				if (x_rst == x_one - 1 || y == y_one - 2
					|| x_rst == x || y == y_brdr)
					mini_pixel_put(info->mini, x_rst, y, check_open(map_icon));
				else
					mini_pixel_put(info->mini, x_rst, y, 0x00454545);
			}
			x_rst++;
		}
		y++;
	}
}

/**
**	Draws minimap doors horizontally
**/
void	draw_mini_doors_horizontal(t_info *info, int x, int y, char *map_icon)
{
	int	y_brdr;
	int	y_one;
	int	x_one;
	int	x_rst;

	y_brdr = y;
	y_one = y + (MINI_SCALE / 2);
	while (y < y_one)
	{
		x_rst = x;
		x_one = x_rst + MINI_SCALE;
		while (x_rst < x_one - 1)
		{
			if (x_rst > 2 && x_rst < MINI_DIM - 3 && y > 2 && y < MINI_DIM - 3)
			{
				if (x_rst == x_one - 2 || y == y_one - 1
					|| x_rst == x || y == y_brdr)
					mini_pixel_put(info->mini, x_rst, y, check_open(map_icon));
				else
					mini_pixel_put(info->mini, x_rst, y, 0x00454545);
			}
			x_rst++;
		}
		y++;
	}
}

/**
**	Resets index to 0
**/
int	assign_index(int index)
{
	if (index < 0)
		index = 0;
	return (index);
}

/**
**	Calculates value of XY in `mini_interior();`
**/
double	x_y_values(int index, double pos)
{
	double	x_y;

	x_y = 0.0;
	if (index < 0)
		x_y = (index * -1) * MINI_SCALE;
	if (pos > 0.0)
		x_y -= MINI_SCALE;
	return (x_y - (MINI_SCALE * 2));
}
