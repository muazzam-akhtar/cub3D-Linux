/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/08 15:08:17 by hawadh           ###   ########.fr       */
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
**/
void	find_end(t_info *info)
{
	info->mini->y_pos = 93 + 14;
	while (info->mini->y_pos < 183)
	{
		info->mini->y_pos += MINI_SCALE;
	}
	info->mini->x_pos = 93 + 14;
	while (info->mini->x_pos < 183)
		info->mini->x_pos += MINI_SCALE;
}

/**
**	Draws minimap interior
*	TODO:	Needto fix i and j to start from correct position
**/
static void	mini_interior(t_info *info, t_mini *mini)
{
	float	y;
	float	x;
	int		i;
	int		j;

	find_end(mini);
	i = info->player->y_pos;
	y = 183;
	while (info->data->map[i] && y > 3)
	{
		j = info->player->x_pos;
		x = 183;
		while (info->data->map[i][j] && x > 3)
		{
			if (info->data->map[i][j] == '1')
				draw_mini_walls(info, x, y, 0x00000032);
			else if (info->data->map[i][j] == 'M')
				draw_mini_enemy(mini, x + 7, y + 7, 0x00990000);
			x -= MINI_SCALE;
			j--;
		}
		y -= MINI_SCALE;
		i--;
	}
}
