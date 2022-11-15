/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/15 22:44:25 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	draw_mini_doors(t_mini *mini, int x, int y, int rgb)
{
	int	y_one;
	int	y_brdr;
	int	x_one;
	int	x_rst;

	y += ((MINI_SCALE / 2) / 2);
	y_brdr = y;
	y_one = y + (MINI_SCALE / 2);
	while (y < y_one)
	{
		x_rst = x;
		x_one = x_rst + MINI_SCALE;
		while (x_rst < x_one)
		{
			if (x_rst > 2 && x_rst < MINI_DIM - 3 && y > 2 && y < MINI_DIM - 3)
			{
				if (x_rst == x || x_rst == x_one - 1
					|| y == y_one - 1 || y == y_brdr)
					mini_pixel_put(mini, x_rst, y, 0x00000000);
				else
					mini_pixel_put(mini, x_rst, y, rgb);
			}
			x_rst++;
		}
		y++;
	}
}

/**
**	Draws minimap Enemy symbol
**/
static void	draw_mini_enemy(t_mini *mini, int x, int y, int rgb)
{
	int	y_one;
	int	y_brdr;
	int	x_one;
	int	x_rst;

	y_brdr = y;
	y_one = y + (MINI_SCALE / 2);
	while (y < y_one)
	{
		x_rst = x;
		x_one = x_rst + (MINI_SCALE / 2);
		while (x_rst < x_one)
		{
			if (x_rst > 2 && x_rst < MINI_DIM - 3 && y > 2 && y < MINI_DIM - 3)
			{
				if (x_rst == x || x_rst == x_one - 1
					|| y == y_one - 1 || y == y_brdr)
					mini_pixel_put(mini, x_rst, y, 0x00660000);
				else
					mini_pixel_put(mini, x_rst, y, rgb);
			}
			x_rst++;
		}
		y++;
	}
}

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
			if (y > 2 && x_rst > 2 && y < 177 && x_rst < 177)
				mini_pixel_put(info->mini, x_rst, y, rgb);
			x_rst++;
		}
		y++;
	}
}

static void	draw_mini_interior(t_info *info, char *map_icon, int x, int y)
{
	if (*map_icon == '1')
		draw_mini_walls(info, x, y, 0x00000066);
	if (*map_icon == 'M')
		draw_mini_enemy(info->mini, x + 7, y + 7, 0x00990000);
	if (*map_icon == 'D')
		draw_mini_doors(info->mini, x, y, 0x00454545);
}

/**
**	Draws minimap interior
*	TODO:	Need to adjust subtraction and addition of decimal point
*	TODO:	x_y_values needs completion
**/
void	mini_interior(t_info *info)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = assign_index_values(info->player->y_pos - 3);
	y = x_y_values(i);
	y -= (extract_decimal(info->player, 'y'));
	while (info->data->map[i] && mini_img_limit(info, y, x, 'y'))
	{
		j = assign_index_values(info->player->x_pos - 3);
		x = x_y_values(j);
		x -= (extract_decimal(info->player, 'x'));
		while (info->data->map[i][j] && mini_img_limit(info, y, x, 'x'))
		{
			draw_mini_interior(info, &info->data->map[i][j], x, y);
			j++;
			x += MINI_SCALE;
		}
		i++;
		y += MINI_SCALE;
	}
}
