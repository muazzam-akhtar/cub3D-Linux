/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/04 18:06:32 by hawadh           ###   ########.fr       */
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

static void	find_start(t_info *info, t_mini *mini)
{
	int	i;
	int	j;
	int	y;
	int	x;

	y = 94 - ((MINI_SCALE + 5) * 3);
	x = 94 - ((MINI_SCALE + 5) * 3);
	i = info->player->y_pos;
	j = info->player->x_pos;
	while ()
		y -= MINI_SCALE;
	while ()
		x -= MINI_SCALE;
	mini->y_pos = y;
	mini->x_pos = x;
}

/**
**	Draws minimap interior
**/
void	mini_interior(t_info *info, t_mini *mini)
{
	float	y;
	float	x;
	int		i;
	int		j;


	find_start(info, mini);
	i = 0;
	y = mini->y_pos;
	while (info->data->map[i] && y < 183)
	{
		j = 0;
		x = mini->x_pos;
		while (info->data->map[i][j] && x < 183)
		{
			if (x >= 0 && y >= 0) {
				if (info->data->map[i][j] == '1')
					draw_mini_walls(info, x, y, 0x00000032);
				else if (info->data->map[i][j] == 'M')
					draw_mini_enemy(mini, x + 7, y + 7, 0x00990000);
				x += MINI_SCALE;
			}
			j++;
		}
		if (x >= 0 && y >= 0)
			y += MINI_SCALE;
		i++;
	}
}
