/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:49:26 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/09 20:08:44 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_dda_vars(t_info *inf, t_ray *ray)
{
	ray->cx = cos(ray->angle);
	ray->cy = sin(ray->angle);
	ray->dx = sqrt(1 + (sq(ray->cy) / sq(ray->cx)));
	ray->dy = sqrt(1 + (sq(ray->cx) / sq(ray->cy)));
	ray->m_x = (int)inf->player->x_pos;
	ray->m_y = (int)inf->player->y_pos;
	ray->wall = 0;
	ray->spr = NULL;
	ray->spr_len = 0;
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

void	new_y_val(t_info *inf, t_ray *ray)
{
	if (ray->cx < 0)
	{
		ray->x = ray->m_x + 1;
		ray->y = dda_x(ray->x, inf->player->x_pos,
				inf->player->y_pos, ray->angle);
	}
	else
	{
		ray->x = ray->m_x;
		ray->y = dda_x(ray->x, inf->player->x_pos,
				inf->player->y_pos, ray->angle);
	}
}

void	new_x_val(t_info *inf, t_ray *ray)
{
	if (ray->cy < 0)
	{
		ray->y = ray->m_y + 1;
		ray->x = dda_y(ray->y, inf->player->y_pos,
				inf->player->x_pos, ray->angle);
	}
	else
	{
		ray->y = ray->m_y;
		ray->x = dda_y(ray->y, inf->player->y_pos,
				inf->player->x_pos, ray->angle);
	}
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
		else if (key_sprite(inf->data->map[ray->m_y][ray->m_x]))
			working_spr(inf, ray);
	}
	if (ray->side == 0)
		new_y_val(inf, ray);
	else
		new_x_val(inf, ray);
}
