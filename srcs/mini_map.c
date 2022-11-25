/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:43:20 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/25 19:10:13 by hawadh           ###   ########.fr       */
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
	int	y_one;
	int	x_one;
	int	x_brdr;
	int	y_brdr;

	y_one = (MINI_DIM / 2) + 4;
	x_one = (MINI_DIM / 2) + 4;
	y_brdr = (MINI_DIM / 2) - 4;
	x_brdr = (MINI_DIM / 2) - 4;
	while (y < y_one)
	{
		x_reset = x;
		while (x_reset < x_one)
		{
			if (y == x_brdr || y == (MINI_DIM / 2) + 3
				|| x_reset == y_brdr || x_reset == (MINI_DIM / 2) + 3)
				mini_pixel_put(mini, x_reset, y, 0x000E5227);
			else
				mini_pixel_put(mini, x_reset, y, rgb);
			x_reset++;
		}
		y++;
	}
}

/**
**	Draws minimap interior
**/
static void	mini_interior(t_info *info)
{
	double	y;
	double	x;
	double	temp;
	int		i;
	int		j;

	modf(info->player->y_pos - 3.0, &temp);
	i = temp - 3;
	y = get_values(info, i, 'y');
	i = assign_index(i);
	while (info->data->map[i] && mini_img_limit(y, x, 'y'))
	{
		modf(info->player->x_pos - 3.0, &temp);
		j = temp - 3;
		x = get_values(info, j, 'x');
		j = assign_index(j);
		while (info->data->map[i][j] && mini_img_limit(y, x, 'x'))
		{
			draw_mini_interior(info, &info->data->map[i][j], x, y);
			j++;
			x += MINI_SCALE;
		}
		i++;
		y += MINI_SCALE;
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
	mini_rot(info, mini, MINI_DIM / 2, 0x00A0F0F0);
	mini_interior(info);
	draw_mini_player(mini, (MINI_DIM / 2) - 4, (MINI_DIM / 2) - 4, 0x003D8758);
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
