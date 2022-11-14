/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/14 14:07:51 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws minimap Enemy symbol
**/
static void	draw_mini_enemy(t_mini *mini, int x, int y, int rgb)
{
	int	y_lmt;
	int	y_brdr;
	int	x_lmt;
	int	x_rst;

	y_brdr = y;
	y_lmt = y + 15;
	while (y < y_lmt)
	{
		x_rst = x;
		x_lmt = x_rst + 15;
		while (x_rst < x_lmt)
		{
			if (x_rst > 2 && x_rst < MINI_DIM - 3 && y > 2 && y < MINI_DIM - 3)
			{
				if (x_rst == x || x_rst == x_lmt - 1
					|| y == y_lmt - 1 || y == y_brdr)
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
	int				y_one;
	int				x_one;
	int				x_rst;
	static int		flag;

	if (flag)
	{
		y_one = y + (extract_decimal(info->player, 'y') * MINI_SCALE);
		y -= (extract_decimal(info->player, 'y') * MINI_SCALE);
	}
	else
		y_one = y - (extract_decimal(info->player, 'y') * MINI_SCALE);
	while (y < y_one - 1)
	{
		x_rst = x;
		if (flag)
		{
			x_one = x + (extract_decimal(info->player, 'x') * MINI_SCALE);
			x_rst = x - (extract_decimal(info->player, 'x') * MINI_SCALE);
		}
		else
			x_one = x - (extract_decimal(info->player, 'x') * MINI_SCALE);
		while (x_rst < x_one - 1)
		{
			if (y > 2 && x_rst > 2 && y < 177 && x_rst < 177)
				mini_pixel_put(info->mini, x_rst, y, rgb);
			x_rst++;
		}
		y++;
	}
	flag = 1;
}

/**
**	Draws minimap interior
**/
void	mini_interior(t_info *info, t_mini *mini)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = info->player->y_pos - 3;
	y = -15;
	if (i < 0)
	{
		y = (i * MINI_SCALE - 15) * -1;
		i = 0;
	}
	while (info->data->map[i] && y < 180)
	{
		j = info->player->x_pos - 3;
		x = -15;
		if (j < 0)
		{
			x = (j * MINI_SCALE -15) * -1;
			j = 0;
		}
		while (info->data->map[i][j] && x < 180)
		{
			if (info->data->map[i][j] == '1')
				draw_mini_walls(info, x, y, 0x00000066);
			if (info->data->map[i][j] == 'M')
				draw_mini_enemy(mini, x + 7, y + 7, 0x00990000);
			j++;
			x += MINI_SCALE;
		}
		i++;
		y += MINI_SCALE;
	}
}
