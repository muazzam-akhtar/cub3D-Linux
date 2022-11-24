/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/24 21:21:39 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws walls on minimap
**/
static void	draw_mini_walls(t_info *info, int x, int y, int rgb)
{
	int	y_one;
	int	x_one;
	int	x_rst;

	y_one = y + MINI_SCALE;
	while (y < y_one)
	{
		x_one = x + MINI_SCALE;
		x_rst = x;
		while (x_rst < x_one)
		{
			if (y > 2 && x_rst > 2 && y < MINI_DIM - 3 && x_rst < MINI_DIM - 3)
				mini_pixel_put(info->mini, x_rst, y, rgb);
			x_rst++;
		}
		y++;
	}
}

/**
**	Determines which character is found and draws on minimap.
*
*	map_icon == '1'		draw_mini_walls()
*	map_icon == 'M'		draw_mini_enemy()
*	map_icon == 'D'		draw_mini_doors()
*
**/
void	draw_mini_interior(t_info *info, char *map_icon, int x, int y)
{
	if (*map_icon == '1')
		draw_mini_walls(info, x, y, 0x00000066);
	if (*map_icon == 'D')
	{
		if (*(map_icon - 1) == '1' && *(map_icon + 1) == '1')
		{
			y += (MINI_SCALE / 2) / 2;
			draw_mini_doors_horizontal(info, x, y, 0x00454545);
		}
		else
		{
			x += (MINI_SCALE / 2) / 2;
			draw_mini_doors_vertical(info, x, y, 0x00454545);
		}
	}
}

/**
**	Assigns loop limits and returns false if value y is still less than y_one
*	To exit loop condition this function is placed in, value of y must be >= y_one
**/
int	mini_img_limit(int y, int x, char status)
{
	int	y_one;
	int	x_one;

	y_one = y + MINI_DIM;
	if (status == 'y' && y < y_one)
		return (EXIT_FAILURE);
	x_one = x + MINI_DIM;
	if (status == 'x' && x < x_one)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
