/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:20:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/14 18:28:04 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

uint32_t	get_color(t_rays *ray, int tex_x, int tex_y, t_xpm *xpm)
{
	uint32_t		color;
	unsigned char	addr[5];
	unsigned int	j;
	int				iter;
	int				col;
	int				intensity;

	j = 0;
	color = 0;
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
	(void)ray;
	j = (int)ray->dist;
	col = color;
	iter = 10;
	intensity = 0.0;
	if (ray->dist > 6.0)
		intensity = 0;
	if (ray->dist > 22.0)
		color = col * intensity;
	else if (ray->dist > 21.0)
		color = 10;
	else if (ray->dist > 19.0)
		color -= 1;
	return (color);
}
