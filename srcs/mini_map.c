/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:43:20 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/18 22:12:01 by hawadh           ###   ########.fr       */
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
static void	draw_mini_player(t_mini *mini, int x, int y, int rgb)
{
	int	x_reset;

	while (y < 102)
	{
		x_reset = x;
		while (x_reset < 102)
		{
			if (y == 85 || y == 101)
				mini_pixel_put(mini, x_reset, y, 0x000E5227);
			else if (x_reset == 85 || x_reset == 101)
				mini_pixel_put(mini, x_reset, y, 0x000E5227);
			else
				mini_pixel_put(mini, x_reset, y, rgb);
			x_reset++;
		}
		y++;
	}
}

/**
*!	TEMP FUNCTION 
**/
static void	draw_square(t_mini *mini, int x, int y, int rgb)
{
	int	x_reset;

	while (y < 109)
	{
		x_reset = x;
		while (x_reset < 109)
		{
			if (y == 78 || y == 108)
				mini_pixel_put(mini, x_reset, y, rgb);
			else if (x_reset == 78 || x_reset == 108)
				mini_pixel_put(mini, x_reset, y, rgb);
			x_reset++;
		}
		y++;
	}
}

/**
**	Draws closer borders and calls function to draw
**	Outer borders. Calls to draw minimap interior
**/
void	draw_minimap(t_info *info, t_mini *mini)
{
	int	x;
	int	y;

	y = 3;
	while (y < 183)
	{
		x = 3;
		while (x < 183)
		{
			while (x > 85 && x < 102 && y > 85 && y < 102)
				x++;
			mini_pixel_put(mini, x, y, rgb(info->data, 1));
			x++;
		}
		y++;
	}
	draw_mini_player(mini, 85, 85, 0x003D8758);
	draw_square(mini, 78, 78, 0x00FFFFFF);
	mini_interior(info, mini);
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
	info->mini_map = mlx_new_image(info->mlx, 186, 186);
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
