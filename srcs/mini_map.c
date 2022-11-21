/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:43:20 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/21 21:25:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Custom Pixel Put for Minimap
**/
void	mini_pixel_put(t_mini *mini, int x, int y, int rgb)
{
	char	*draw;

	draw = mini->addr + (y * mini->len + x * (mini->bitspix / 8));
	*(unsigned int *)draw = rgb;
}

/**
**	Draws Player at centre of minimap 
**/
// static void	draw_mini_player(t_mini *mini, int x, int y, int rgb)
// {
// 	int	x_reset;
// 	int	y_one;
// 	int	x_one;
// 	int	x_brdr;
// 	int	y_brdr;

// 	y_one = (MINI_DIM / 2) + 4;
// 	x_one = (MINI_DIM / 2) + 4;
// 	y_brdr = (MINI_DIM / 2) - 4;
// 	x_brdr = (MINI_DIM / 2) - 4;
// 	while (y < y_one)
// 	{
// 		x_reset = x;
// 		while (x_reset < x_one)
// 		{
// 			if (y == x_brdr || y == (MINI_DIM / 2) + 3
// 				|| x_reset == y_brdr || x_reset == (MINI_DIM / 2) + 3)
// 				mini_pixel_put(mini, x_reset, y, 0x000E5227);
// 			else
// 				mini_pixel_put(mini, x_reset, y, rgb);
// 			x_reset++;
// 		}
// 		y++;
// 	}
// }

/**
**	Draws minimap interior
*	TODO:	Fix index value issues when approaching index 0 of i or j
**/
// static void	mini_interior(t_info *info)
// {
// 	double	x;
// 	double	y;
// 	int		i;
// 	int		j;

// 	i = assign_index_values(info->player->y_pos - 3);
// 	y = x_y_values(i) - extract_decimal(info->player->y_pos) * MINI_SCALE;
// 	while (info->data->map[i] && mini_img_limit(info, y, x, 'y'))
// 	{
// 		j = assign_index_values(info->player->x_pos - 3);
// 		x = x_y_values(j) - extract_decimal(info->player->x_pos) * MINI_SCALE;
// 		while (info->data->map[i][j] && mini_img_limit(info, y, x, 'x'))
// 		{
// 			draw_mini_interior(info, &info->data->map[i][j], x, y);
// 			j++;
// 			x += MINI_SCALE;
// 		}
// 		i++;
// 		y += MINI_SCALE;
// 	}
// }

/**
**	Draws closer borders and calls function to draw
**	Outer borders. Calls to draw minimap interior
**/
void	draw_minimap(t_info *info, t_mini *mini)
{
	int	x;
	int	y;

	y = 3;
	while (y < MINI_DIM - 3)
	{
		x = 3;
		while (x < MINI_DIM - 3)
		{
			mini_pixel_put(mini, x, y, 0X00000048);
			x++;
		}
		y++;
	}
	draw_mini_interior(info, mini);
	// draw_mini_player(mini, 80, 80, 0x003D8758);
}

/**
**	Initialises struct mini and creates new image for
**	mini-map
**/
void	init_minimap(t_info *info)
{
	t_mini	*mini;

	mini = (t_mini *)ft_calloc(1, sizeof(t_mini));
	info->mini = mini;
	info->mini_map = mlx_new_image(info->mlx, MINI_DIM, MINI_DIM);
	if (!info->mini_map)
	{
		free_data(info);
		err_return(4, info);
	}
	mini->addr = mlx_get_data_addr(info->mini_map, &mini->bitspix,
			&mini->len, &mini->end);
	if (!mini->addr)
		err_return(4, info);
}
