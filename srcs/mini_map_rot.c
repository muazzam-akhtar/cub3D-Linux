/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:19 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/25 18:10:07 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws Cone of view in minimap starting from player spot.
**/
void	mini_rot(t_info *info, t_mini *mini, int start, u_int32_t rgb)
{
	double	y;
	double	x;
	double	ang;
	int		iter;
	int		ang_iter;

	x = start * 1.0;
	y = start * 1.0;
	iter = 70;
	ang = info->player->angle - (35 * (PI / 180));
	while (iter > 0)
	{
		ang_iter = 40;
		x = start * 1.0;
		y = start * 1.0;
		while (ang_iter > 0)
		{
			x += cos(ang);
			y += sin(ang);
			mini_pixel_put(mini, x, y, rgb);
			ang_iter--;
		}
		ang += PI / 180;
		iter--;
	}
}
