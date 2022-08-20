/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/21 19:42:28 by hawadh           ###   ########.fr       */
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
static void	add_xpm(t_info *info, t_xpm *xpm, int x, int y)
{
	int	x_reset;
	int	xpm_y;
	int	xpm_x;
	int	i;

	xpm_y = 0;
	while (xpm_y < xpm->hi - 4)
	{
		x_reset = x;
		xpm_x = 0;
		while (xpm_x < xpm->wi - 4)
		{
			i = 0;
			while (i < 4)
			{
				info->image->addr[((x_reset * 4) + 4 * (WIDTH * y)) + i]
					= xpm->addr[((xpm_x * 4) + 4 * (xpm->wi * xpm_y)) + i];
				i++;
			}
			xpm_x++;
			x_reset++;
		}
		xpm_y++;
		y++;
	}
}

/**
**	Calls xpm struct based on player orientation at start
**/
static void	place_xpm(t_info *info, t_data *data)
{
	int	y;
	int	x;

	x = 640;
	y = 200;
	if (info->player->view == 'N')
		add_xpm(info, &data->xpm[NO], x, y);
	if (info->player->view == 'S')
		add_xpm(info, &data->xpm[SO], x, y);
	if (info->player->view == 'W')
		add_xpm(info, &data->xpm[WE], x, y);
	if (info->player->view == 'E')
		add_xpm(info, &data->xpm[EA], x, y);
}

/**
**	Draws everything include map
*	init_cursor(); to reinitialise crosshair
*	after each redraw
**/
void	draw_map(t_info *info)
{
	find_player(info->data, info->player);
	ceiling_floor(info);
	place_xpm(info, info->data);
	draw_minimap(info, info->mini);
	init_cursor(info);
}
