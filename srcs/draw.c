/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/09/27 16:38:09 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Custom pixel put
**/
void	my_pixel_put(t_info *inf, int x, int y, int rgb)
{
	char	*draw;

	draw = inf->image->addr
		+ (y * inf->image->len + x * (inf->image->bitspix / 8));
	*(unsigned int *)draw = rgb;
}

/**
**	Function to calculate size of xpm and add them to image
**/
static void	add_xpm(t_info *info, t_xpm *xpm, t_rays *ray, int x)
{
	int	xpm_y;
	int	y;
	int	wall_height;
	int	i;

	xpm_y = 0;
	y = ray->height;
	wall_height = HEIGHT - ray->height;
	while (xpm_y < wall_height && y < wall_height)
	{
		i = 0;
		while (i < 4)
		{
			info->image->addr[((x * 4) + 4 * (WIDTH * y)) + i]
				= xpm->addr[((x * 4) + 4 * (xpm->wi * xpm_y)) + i];
			i++;
		}
		xpm_y++;
		y++;
	}
}

/**
**	Calls xpm struct based on player orientation
**/
void	place_walls(t_info *inf, t_rays *ray, int x)
{
	if (ray->ang >= ((270 - 45) * RADIAN) && ray->ang < ((270 + 45) * RADIAN))
		add_xpm(inf, &inf->data->xpm[NO], ray, x);
	if (ray->ang >= ((180 - 45) * RADIAN) && ray->ang < ((180 + 45) * RADIAN))
		add_xpm(inf, &inf->data->xpm[SO], ray, x);
	if (ray->ang >= ((90 - 45) * RADIAN) && ray->ang < ((90 + 45) * RADIAN))
		add_xpm(inf, &inf->data->xpm[WE], ray, x);
	if (ray->ang >= 0 && ray->ang < ((0 + 45) * RADIAN))
		add_xpm(inf, &inf->data->xpm[EA], ray, x);
	else if (ray->ang >= ((360 - 45) * RADIAN) && ray->ang < (360 * RADIAN))
		add_xpm(inf, &inf->data->xpm[EA], ray, x);
}

/**
**	Draws everything include map
*	init_cursor(); to reinitialise crosshair
*	after each redraw
**/
void	draw_map(t_info *info)
{
	find_player(info->data, info->player);
	init_rays(info);
	draw_minimap(info, info->mini);
	init_cursor(info);
}
