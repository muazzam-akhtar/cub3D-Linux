/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:20:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/14 19:00:38 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static uint32_t	get_gradient(uint32_t color, t_rays *ray)
{
	if (ray->dist > 22.0)
		color = 0;
	else if (ray->dist > 21.0)
		color = 10;
	else if (ray->dist > 20.0)
		color = 15;
	return (color);
}

uint32_t	get_color(t_rays *ray, int tex_x, int tex_y, t_xpm *xpm)
{
	uint32_t		color;
	unsigned char	addr[5];
	int				j;

	j = 0;
	while (j < 4)
	{
		addr[j] = *(xpm->addr + ((tex_y * xpm->len)
					+ (tex_x * (xpm->bitspix / 8)) + j));
		j++;
	}
	color = (addr[0])
		| (addr[1] << 8)
		| (addr[2] << 16)
		| (addr[3] << 24);
	color = get_gradient(color, ray);
	return (color);
}
