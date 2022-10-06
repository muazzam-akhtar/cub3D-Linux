/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/10/06 17:57:27 by makhtar          ###   ########.fr       */
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
	int	xpm_x;
	int	y;
	int	i;

	xpm_y = 0;
	xpm_x = x;
	y = (HEIGHT / 2) - (ray->height / 2);
	while (xpm_y < xpm->hi && y < ray->height)
	{
		i = 0;
		while (i < 4 && y >= 0 && y < 1080 && xpm_y < 1080)
		{
			info->image->addr[((x * 4) + 4 * (WIDTH * y)) + i]
				= xpm->addr[(((xpm_x) * 4) + 4 * (xpm->wi * xpm_y)) + i];
			i++;
		}
		y++;
		xpm_y++;
	}
}

/**
**	Calls xpm struct based on player orientation
**/
void	place_walls(t_info *inf, t_rays *ray, int x)
{
	static int	old_colour;

	if (!old_colour && ray->dir_wall != 5)
		old_colour = ray->dir_wall;
	if (ray->dir_wall == 1)
		add_xpm(inf, &inf->data->xpm[NO], ray, x);
	if (ray->dir_wall == 2)
		add_xpm(inf, &inf->data->xpm[SO], ray, x);
	if (ray->dir_wall == 3)
		add_xpm(inf, &inf->data->xpm[WE], ray, x);
	if (ray->dir_wall == 4)
		add_xpm(inf, &inf->data->xpm[EA], ray, x);
	else if (ray->dir_wall == 0 || ray->dir_wall == 5)
	{
		add_xpm(inf, &inf->data->xpm[old_colour - 1], ray, x);
		return ;
	}
	old_colour = ray->dir_wall;
}

/**
**	Draws everything include map
*	init_cursor(); to reinitialise crosshair
*	after each redraw
**/
void	draw_map(t_info *info)
{
	static int	timer;

	if (!timer)
	{
		find_player(info->data, info->player);
		timer = 1;
	}
	init_rays(info);
	draw_minimap(info, info->mini);
	init_cursor(info);
}
