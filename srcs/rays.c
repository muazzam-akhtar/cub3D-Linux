/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:42:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/10 13:35:47 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Checks with New Coordinates of the Raycast if it hit the wall.
**/
static int	check_wall(t_info *inf, double x, double y)
{
	int	col;
	int	row;

	if ((y >= 0) && (y < ft_ptrptrlen(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = (int)x;
		col = (int)y;
		if (inf->data->map[col][row] == '1')
			return (1);
		return (0);
	}
	return (1);
}

/**
**	Initialisation of the ray structure before the calculation
**/
static void	init_vars(t_ray *ray, t_info *inf, double *old_x, double *old_y)
{
	ray->x = inf->player->x_pos;
	ray->y = inf->player->y_pos;
	*old_x = ray->x;
	*old_y = ray->y;
	ray->wall = 0;
	ray->grid_x = (int)ray->x;
	ray->grid_y = (int)ray->y;
}

/**
**	Sub Main process which runs the rays for all the scenarios
**	Basic wall hits
**	Edge Cases
**	Direction of wall
**	Getting the height of the wall
**/
static void	hit_wall_check(t_ray *ray, t_info *inf)
{
	double	old_x;
	double	old_y;

	init_vars(ray, inf, &old_x, &old_y);
	while (!ray->wall)
	{
		old_x = ray->x;
		old_y = ray->y;
		ray->x += (cos(ray->angle) * 0.01);
		ray->y += (sin(ray->angle) * 0.01);
		ray->wall = check_wall(inf, ray->x, ray->y);
		if (!ray->wall && (ray->grid_x != (int)ray->x
				&& ray->grid_y != (int)ray->y))
			ray->wall = edge_case(ray->x, ray->y, inf);
	}
	inf->player->rays[RAYS - ray->count].dir_wall
		= wall_hit_direction(ray, old_x, old_y, inf);
	inf->player->rays[RAYS - ray->count].x = ray->x;
	inf->player->rays[RAYS - ray->count].y = ray->y;
	inf->player->rays[RAYS - ray->count].dist = get_dist(inf->player->x_pos,
			inf->player->y_pos, ray->x, ray->y);
	inf->player->rays[RAYS - ray->count].height
		= get_height(inf->player->rays[RAYS - ray->count].dist,
			inf->player->rays[RAYS - ray->count].ang, inf->player->angle);
}
/*
**	// printf("Angle of the player: %f, Height: %f, Angle of the ray: %f\n",
**	// 	(inf->player->angle * (180 / PI)), inf->player->rays[1920
**	// 	- ray->count].height, (inf->player->rays[1920 - ray->count].ang
* (180 / PI)));*/

/**
**	The revised conditions if the angle is negative and the x_co exceeds 1920
**/
static void	revise_ang_x_co(t_ray *ray)
{
	if (ray->angle > 2 * PI)
			ray->angle -= 2 * PI;
	if (ray->x1 > RAYS)
		ray->x1 = RAYS;
}

/**
**	The Main Process of the raycasting which deals with pixel
**	put for ceiling, floor, walls
**/
void	init_rays(t_info *inf)
{
	t_ray	ray;

	ray.angle = inf->player->angle - (35 * RADIAN);
	if (ray.angle < 0)
		ray.angle += 2 * PI;
	ray.count = RAYS;
	ray.x1 = 0;
	ceiling_floor(inf);
	while (ray.count > 0)
	{
		hit_wall_check(&ray, inf);
		ray.y = 540 - (inf->player->rays[RAYS - ray.count].height / 2);
		inf->player->rays[RAYS - ray.count].ang = ray.angle;
		ray.angle += 0.000636318; // (PI / 180) * (60 / RAYS)
		revise_ang_x_co(&ray);
		place_walls(inf, &inf->player->rays[RAYS - ray.count], ray.x1);
		ray.x1 += 1; // 11.6 * (60 / RAYS)
		ray.count--;
	}
	init_cursor(inf);
}
