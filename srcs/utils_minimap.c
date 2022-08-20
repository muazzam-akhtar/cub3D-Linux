/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/18 22:08:31 by hawadh           ###   ########.fr       */
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
			if (x_rst > 2 && x_rst < 183 && y > 2 && y < 183)
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
	int	y_one;
	int	x_one;
	int	x_rst;
	int	y_strt;

	y_strt = y;
	y_one = y + MINI_SCALE - 1;
	while (y < y_one)
	{
		x_one = x + MINI_SCALE - 1;
		x_rst = x;
		while (x_rst < x_one)
		{
			if (x_rst > 2 && x_rst < 183 && y > 2 && y < 183)
				mini_pixel_put(info->mini, x_rst, y, rgb);
			x_rst++;
		}
		y++;
	}
}

/**
**	Draws minimap interior
*	TODO:	Draw miniature version of file map
**/
void	mini_interior(t_info *info, t_mini *mini)
{
	float	y;
	float	x;
	int		i;
	int		j;

	i = info->player->y_pos - 3;
	y = 94 - ((MINI_SCALE + 5) * 3);
	while (i >= 0 && info->data->map[i] && y < 183)
	{
		j = info->player->x_pos - 3;
		x = 94 - ((MINI_SCALE + 5) * 3);
		while (j >= 0 && info->data->map[i][j] && x < 183)
		{
			if (info->data->map[i][j] == '1')
				draw_mini_walls(info, x, y, 0x00000032);
			else if (info->data->map[i][j] == 'M')
				draw_mini_enemy(mini, x + 7, y + 7, 0x00990000);
			x += MINI_SCALE;
			j++;
		}
		y += MINI_SCALE;
		i++;
	}
}
