/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:49:26 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/14 15:03:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	init_dda_vars(t_info *inf, t_ray *ray)
{
	static int	n;

	ray->cx = cos(ray->angle);
	ray->cy = sin(ray->angle);
	ray->dx = sqrt(1 + (sq(ray->cy) / sq(ray->cx)));
	ray->dy = sqrt(1 + (sq(ray->cx) / sq(ray->cy)));
	ray->m_x = (int)inf->player->x_pos;
	ray->m_y = (int)inf->player->y_pos;
	ray->wall = 0;
	ray->spr = NULL;
	ray->spr_len = 0;
	if (n == 0)
		inf->player->door_flag = 0;
	if (n == 1920)
		n = 0;
	n++;
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

void	handle_sprite_lookups(t_info *inf, t_ray *ray)
{
	int	index;

	index = lookup_door(inf, ray->m_x, ray->m_y);
	if (index >= 0 && inf->doors[index].m_x
		== ray->m_x && inf->doors[index].m_y
		== ray->m_y)
		working_spr(inf, ray, index);
	else if (key_sprite(inf->data->map[ray->m_y][ray->m_x]))
		working_spr(inf, ray, index);
}

void	raycast_door(t_info *inf)
{
	double		x;
	double		y;
	double		ang;
	int			door;
	static int	counter;

	if (!counter)
	{
		door = 0;
		x = inf->player->x_pos;
		y = inf->player->y_pos;
		if (inf->doors[lookup_door(inf, (int)x,
					(int)y)].x_pos == (int)x
			&& inf->doors[lookup_door(inf, (int)x,
					(int)y)].y_pos == (int)y)
		{
			inf->integrate = 0;
			return ;
		}
		ang = inf->player->angle;
		while ((int)x != inf->doors[lookup_door(inf, (int)x, (int)y)].m_x
			&& (int)y != inf->doors[lookup_door(inf, (int)x, (int)y)].m_y)
		{
			x += cos(ang);
			y += sin(ang);
			door++;
			if (door == 3)
			{
				inf->integrate = 0;
				return ;
			}
		}
		if (inf->doors[lookup_door(inf, (int)x, (int)y)].open == 1)
			inf->doors[lookup_door(inf, (int)x, (int)y)].open = 0;
		else if (inf->doors[lookup_door(inf, (int)x, (int)y)].open == 0)
			inf->doors[lookup_door(inf, (int)x, (int)y)].open = 1;
	}
	counter++;
	if (counter == 1920)
		counter = 0;
}

/*
**	side = 0 or 1 indicates x_coordinate hit or y-coordinate
*/
void	raycasting(t_info *inf, t_ray *ray)
{
	init_dda_vars(inf, ray);
	init_x_y_steps(inf, ray);
	if (inf->integrate == 1)
		raycast_door(inf);
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
		handle_sprite_lookups(inf, ray);
	}
	if (ray->side == 0)
		ray->y = new_y_val(inf, ray);
	else
		ray->x = new_x_val(inf, ray);
}
