/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/28 12:17:06 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Custom pixel put
**/
void	my_pixel_put(t_info *inf, int x, int y, u_int32_t rgb)
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
	int			y;
	t_tex		tex;

	tex.xpm_x = (int)(modf(ray->x, &ray->x) * xpm->wi);
	if (ray->side == 0)
		tex.xpm_x = (int)(modf(ray->y, &ray->y) * xpm->wi);
	if ((ray->side == 0 && cos(ray->ang) > 0)
		|| (ray->side == 1 && sin(ray->ang) < 0))
		tex.xpm_x = xpm->wi - tex.xpm_x - 1;
	tex.start = (HEIGHT / 2) - (ray->height / 2);
	tex.end = (HEIGHT / 2) + (ray->height / 2);
	y = ((HEIGHT - ray->height) / 2);
	if (tex.xpm_x > WIDTH)
		tex.xpm_x = xpm->wi - 1;
	if (y < 0)
		y = 0;
	while (y < HEIGHT && y < tex.end - 4)
	{
		tex.xpm_y = ((1.0 * abs(y - tex.start)) / abs(tex.end - tex.start)
				* xpm->hi);
		if (tex.xpm_y > xpm->hi)
			tex.xpm_y = xpm->hi - 1;
		my_pixel_put(info, x, y, get_color(ray, tex.xpm_x, tex.xpm_y, xpm));
		y++;
	}
}

/*
*/
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
	if (ray->dir_wall == 6)
		add_xpm(inf, &inf->data->xpm[DO], ray, x);
	else if (ray->dir_wall == 0 || ray->dir_wall == 5)
	{
		add_xpm(inf, &inf->data->xpm[old_colour - 1], ray, x);
		return ;
	}
	if (ray->dir_wall != 6)
		old_colour = ray->dir_wall;
}

/**
**	Draws everything include map
*
*	find_player();		Finds initial player position in map
*	
*	static int timer;	For intial finding of player position to not interrupt
*						later player positions by blocking reset
*
*	init_rays(); 		Begins raycaster
*	
*	init_cursor();		to reinitialise crosshair
*						after each redraw
*
*	draw_minimap();		Draws minimap
*
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
