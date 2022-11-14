/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:20:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/14 13:35:53 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

uint32_t	get_color(t_rays *ray, int tex_x, int tex_y, t_xpm *xpm)
{
	uint32_t		color;
	unsigned char	addr[5];
	unsigned int	j;

	j = 0;
	color = 0;
	while (j < 4)
	{
		addr[j] = *(xpm->addr + ((tex_y * xpm->len)
					+ (tex_x * (xpm->bitspix / 8)) + j));
		j++;
	}
	color = addr[0]
		| addr[1] << 8
		| addr[2] << 16
		| addr[3] << 24;
	(void)ray;
	// j = (int)ray->dist;
	// while (j > 0)
	// {
	// 	j--;
	// }
	// color = (color >> 1 & 0);
	return (color);
}
