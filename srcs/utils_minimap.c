/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/23 16:53:20 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws minimap Enemy symbol
*!	DEPRECATED
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

	if (!flag)
	{
		y_one = y + (extract_decimal(info->player, 'y') * MINI_SCALE);
		y -= (extract_decimal(info->player, 'y') * MINI_SCALE);
	}
	else
		y_one = y - (extract_decimal(info->player, 'y') * MINI_SCALE);
	while (y < y_one - 1)
	{
		x_rst = x;
		if (!flag)
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

void	print_red_wall(t_mini *mini, int x, int y)
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
		j--;
	}
}

void	print_player(t_info *info, t_mini *mini, int x, int y)
{
	int	y_one;
	int	x_one;
	int	x_rst;

	y_one = y + MINI_SCALE;
	while (y < y_one - 1)
	{
		x_one = x + MINI_SCALE;
		x_rst = x;
		while (x_rst < x_one - 1)
		{
			if (y > 2 && x_rst > 2 && y < MINI_DIM - 3 && x_rst < MINI_DIM - 3)
				mini_pixel_put(info->mini, x_rst, y, rgb);
			x_rst++;
		}
		j--;
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
	if (*map_icon == 'M')
		draw_mini_enemy(info->mini, x + 7, y + 7, 0x00990000);
	if (*map_icon == 'D' || *map_icon == 'O')
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
int	mini_img_limit(t_info *info, int y, int x, char status)
{
	int	y_one;
	int	x_one;

	y = y - MINI_DIM + extract_decimal(info->player->y_pos) * MINI_SCALE;
	y_one = y + MINI_DIM + extract_decimal(info->player->y_pos) * MINI_SCALE;
	if (status == 'y' && y < y_one)
		return (EXIT_FAILURE);
	x = x - MINI_DIM + extract_decimal(info->player->x_pos) * MINI_SCALE;
	x_one = x + MINI_DIM + extract_decimal(info->player->x_pos) * MINI_SCALE;
	if (status == 'x' && x < y_one)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
