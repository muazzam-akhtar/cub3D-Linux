/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:43:20 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/15 22:03:14 by hawadh           ###   ########.fr       */
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

	while (y < 97)
	{
		x_reset = x;
		while (x_reset < 97)
		{
			if (y == 82 || y == 96 || x_reset == 82 || x_reset == 96)
				mini_pixel_put(mini, x_reset, y, 0x000E5227);
			else
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
	while (y < MINI_DIM - 3)
	{
		x = 3;
		while (x < MINI_DIM - 3)
		{
			mini_pixel_put(mini, x, y, rgb(info->data, 1));
			x++;
		}
		y++;
	}
	mini_interior(info);
	draw_mini_player(mini, 82, 82, 0x003D8758);
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
