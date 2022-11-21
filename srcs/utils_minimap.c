/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/21 21:26:15 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws minimap Enemy symbol
*!	DEPRECATED
**/
// static void	draw_mini_enemy(t_mini *mini, int x, int y, int rgb)
// {
// 	int	y_lmt;
// 	int	y_brdr;
// 	int	x_lmt;
// 	int	x_rst;

// 	y_brdr = y;
// 	y_lmt = y + 15;
// 	while (y < y_lmt)
// 	{
// 		x_rst = x;
// 		x_lmt = x_rst + 15;
// 		while (x_rst < x_lmt)
// 		{
// 			if (x_rst > 2 && x_rst < MINI_DIM - 3 && y > 2 && y < MINI_DIM - 3)
// 			{
// 				if (x_rst == x || x_rst == x_lmt - 1
// 					|| y == y_lmt - 1 || y == y_brdr)
// 					mini_pixel_put(mini, x_rst, y, 0x00660000);
// 				else
// 					mini_pixel_put(mini, x_rst, y, rgb);
// 			}
// 			x_rst++;
// 		}
// 		y++;
// 	}
// }

/**
**	Draws walls on minimap
**/
// static void	draw_mini_walls(t_info *info, int x, int y, int rgb)
// {
// 	int				y_one;
// 	int				x_one;
// 	int				x_rst;
// 	static int		flag;

// 	if (!flag)
// 	{
// 		y_one = y + (extract_decimal(info->player, 'y') * MINI_SCALE);
// 		y -= (extract_decimal(info->player, 'y') * MINI_SCALE);
// 	}
// 	else
// 		y_one = y - (extract_decimal(info->player, 'y') * MINI_SCALE);
// 	while (y < y_one - 1)
// 	{
// 		x_rst = x;
// 		if (!flag)
// 		{
// 			x_one = x + (extract_decimal(info->player, 'x') * MINI_SCALE);
// 			x_rst = x - (extract_decimal(info->player, 'x') * MINI_SCALE);
// 		}
// 		else
// 			x_one = x - (extract_decimal(info->player, 'x') * MINI_SCALE);
// 		while (x_rst < x_one - 1)
// 		{
// 			if (y > 2 && x_rst > 2 && y < 177 && x_rst < 177)
// 				mini_pixel_put(info->mini, x_rst, y, rgb);
// 			x_rst++;
// 		}
// 		y++;
// 	}
// 	flag = 1;
// }

void	print_red_wall(t_mini *mini, int x, int y)
{
	int				i;
	int				j;

	j = 30;
	while (j > 0)
	{
		i = 30;
		while (i > 0)
		{
			mini_pixel_put(mini, x + i, y + j, 0X00FF0000);
			i--;
		}
		j--;
	}
}

void	print_player(t_info *info, t_mini *mini, int x, int y)
{
	int				i;
	int				j;
	double			r_x;
	double			r_y;
	double			ang;

	j = 20;
	// r_x = modf(info->player->x_pos, &r_x);
	// r_y = modf(info->player->y_pos, &r_y);
	// x = x + (x * r_x);
	// y = y + (y * r_y);
	while (j > 0)
	{
		i = 20;
		while (i > 0)
		{
			mini_pixel_put(mini, x + i + 5, y + j + 5, 0X0000FF00);
			i--;
		}
		j--;
	}
	r_x = (1.0 * x) + 0;
	r_y = (1.0 * y) + 15;
	j = 70;
	ang = info->player->angle - (35 * (PI / 180)) + PI;
	while (j > 0)
	{
		i = 20;
		r_x = (1.0 * x) + 15;
		r_y = (1.0 * y) + 15;
		while (i > 0)
		{
			r_x += cos(ang);
			r_y += sin(ang);
			if ((r_x && r_y > 0) && (r_x && r_y < 180))
				mini_pixel_put(mini, r_x, r_y, 0X00FFFFFFF);
			i--;
		}
		ang += (PI / 180);
		j--;
	}
}

void	print_door(t_info *info, t_mini *mini, int x, int y, int index)
{
	int				i;
	int				j;
	int				col;

	j = 30;
	if (info->doors[index].open)
		col = 0X009000;
	else
		col = 0X000000;
	while (j > 0)
	{
		i = 30;
		while (i > 0)
		{
			mini_pixel_put(mini, x + i, y + j, col);
			i--;
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
void	draw_mini_interior(t_info *info, t_mini *mini)
{
	int	x;
	int	y;
	int	count_y;
	int	count_x;
	int	draw_x;
	int	draw_y;

	x = (int)info->player->x_pos - 3;
	y = (int)info->player->y_pos - 3;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	count_y = 6;
	draw_x = 0 - extract_decimal(info->player->x_pos);
	draw_y = 0 - extract_decimal(info->player->y_pos);
	while (count_y > 0)
	{
		count_x = 6;
		while (count_x > 0)
		{
			if (info->data->map[y + count_y][x + count_x] == '1')
				print_red_wall(mini, draw_x, draw_y);
			else if (info->data->map[y + count_y][x + count_x] == 'P')
				print_player(info, mini, draw_x, draw_y);
			else if (lookup_door(info, x + count_x, y + count_y) >= 0)
				print_door(info, mini, draw_x, draw_y,
					lookup_door(info, x + count_x, y + count_y));
			count_x--;
			draw_x += 30;
		}
		draw_y += 30;
		count_y--;
	}
}

/**
 * 
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
*/
