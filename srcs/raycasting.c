/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:49:26 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/24 14:49:23 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	init_dda_vars(t_info *inf, t_ray *ray)
{
	ray->cx = cos(ray->angle);
	ray->cy = sin(ray->angle);
	ray->dx = sqrt(1 + (sq(ray->cy / ray->cx)));
	ray->dy = sqrt(1 + (sq(ray->cx / ray->cy)));
	ray->m_x = (int)inf->player->x_pos;
	ray->m_y = (int)inf->player->y_pos;
	ray->wall = 0;
	ray->token = 0;
}

void	init_x_y_steps(t_info *inf, t_ray *ray)
{
	if (ray->cx < 0)
	{
		ray->x_step = -1;
		ray->side_dist_x = (inf->player->x_pos - ray->m_x) * ray->dx;
	}
	else
	{
		ray->x_step = 1;
		ray->side_dist_x = ((int)inf->player->x_pos + 1.0
				- inf->player->x_pos) * ray->dx;
	}
	if (ray->cy < 0)
	{
		ray->y_step = -1;
		ray->side_dist_y = (inf->player->y_pos - ray->m_y) * ray->dy;
	}
	else
	{
		ray->y_step = 1;
		ray->side_dist_y = ((int)inf->player->y_pos + 1.0
				- inf->player->y_pos) * ray->dy;
	}
}

int	handle_sprite_lookups(t_info *inf, t_ray *ray)
{
	int	index;

	index = lookup_door(inf, ray->m_x, ray->m_y);
	if (index >= 0 && inf->doors[index].m_x
		== ray->m_x && inf->doors[index].m_y
		== ray->m_y)
	{
		if (inf->doors[index].open == FALSE)
		{
			ray->token = 6;
			return (TRUE);
		}
	}
	return (FALSE);
}

/*
**	side = 0 or 1 indicates x_coordinate hit or y-coordinate
*/
void	raycasting(t_info *inf, t_ray *ray)
{
	init_dda_vars(inf, ray);
	init_x_y_steps(inf, ray);
	while (!ray->wall)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->dx;
			ray->m_x += ray->x_step;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->dy;
			ray->m_y += ray->y_step;
			ray->side = 1;
		}
		if (inf->data->map[ray->m_y][ray->m_x] == '1')
			ray->wall = 1;
		if (ray->wall != 1)
			ray->wall = handle_sprite_lookups(inf, ray);
	}
	if (ray->side == 0)
		ray->y = new_y_val(inf, ray);
	else
		ray->x = new_x_val(inf, ray);
}
