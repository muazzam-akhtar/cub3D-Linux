/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:45:56 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/16 20:55:44 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	rgb_door_status(t_info *info)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = assign_index_values(info->player->y_pos - 3);
	while (info->data->map[i])
	{
		y = info->player->y_pos;
		x = info->player->x_pos;
		j = assign_index_values(info->player->x_pos - 3);
		while (info->data->map[i][j])
		{
			if (info->data->map[i][j] == 'D')
				return (0x00660000);
			else if (info->data->map[i][j] == 'O')
				return (0x03D8758);
			j++;
		}
		i++;
	}
	return (0x03D8758);
}

/**
**	Draws minimap doors vertically
**/
void	draw_mini_doors_vertical(t_info *info, int x, int y, int rgb)
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
					mini_pixel_put(info->mini, x_rst, y, rgb_door_status(info));
				else
					mini_pixel_put(info->mini, x_rst, y, rgb);
			}
			x_rst++;
		}
		y++;
	}
}

/**
**	Draws minimap doors horizontally
**/
void	draw_mini_doors_horizontal(t_info *info, int x, int y, int rgb)
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
				if (x_rst == x_one - 2 || y == y_one -1
					|| x_rst == x || y == y_brdr)
					mini_pixel_put(info->mini, x_rst, y, rgb_door_status(info));
				else
					mini_pixel_put(info->mini, x_rst, y, rgb);
			}
			x_rst++;
		}
		y++;
	}
}

/**
**	Extracts x & y values
**/
int	x_y_values(int index)
{
	if (index < 0)
		return ((index * MINI_SCALE - 7));
	return (7);
}

/**
**	Sets index value to 0 if index < 0
**/
int	assign_index_values(int index)
{
	if (index < 0)
		return (0);
	return (index);
}
