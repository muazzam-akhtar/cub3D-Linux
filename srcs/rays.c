/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:42:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/14 20:46:32 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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
**	The revised conditions if the angle is negative and the x_co exceeds 1920
**	calculating the adjacent side when wall hits
**/
static void	revise_calc(t_rays *rays, t_ray *ray, t_info *inf,
	int calc_height)
{
	if (calc_height == 0)
	{
		ray->angle += 0.000636318;
		ray->angle = fix_angle(ray->angle);
		if (ray->x1 > RAYS)
			ray->x1 = RAYS;
	}
	else
	{
		rays->dist = euclidean(ray,
				get_dist(inf->player->x_pos,
					inf->player->y_pos, ray->x, ray->y), inf->player->angle);
		rays->height
			= get_height(rays->dist,
				rays->ang, inf->player->angle);
	}
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
	double		old_x;
	double		old_y;

	init_vars(ray, inf, &old_x, &old_y);
	while (!ray->wall)
	{
		old_x = ray->x;
		old_y = ray->y;
		raycasting(inf, ray);
	}
	inf->player->rays[RAYS - ray->count].dir_wall
		= wall_hit_direction(ray);
	inf->player->rays[RAYS - ray->count].x = ray->x;
	inf->player->rays[RAYS - ray->count].y = ray->y;
	inf->player->rays[RAYS - ray->count].side = ray->side;
	revise_calc(&inf->player->rays[RAYS - ray->count], ray, inf, 1);
}

static void	reverse_list(t_ray *ray)
{
	// if (!ray->spr && ray->spr->next != NULL)
	// 	ray->spr = ray->spr->prev;
	// while (ray->spr && ray->spr->prev != NULL)
	// {
		// ray->spr = ray->spr->prev;
	// }
	// printf("check\n");
}

static void	place_door(t_info *inf, t_xpm *xpm, t_ray *ray, int x)
{
	int			xpm_x;
	int			xpm_y;
	int			start;
	int			end;
	int			y;

	xpm_x = (int)(modf(ray->spr->x_pos, &ray->spr->x_pos) * xpm->wi);
	if (ray->spr->side == 0)
		xpm_x = (ray->spr->y_pos * xpm->wi);
	if (ray->spr->side == 1 && sin(ray->spr->ang) < 0)
		xpm_x = WIDTH - xpm_x - 1;
	start = (HEIGHT / 2) - (ray->spr->height / 2);
	end = (HEIGHT / 2) + (ray->spr->height / 2);
	y = ((HEIGHT - ray->spr->height) / 2);
	if (y < 0)
		y = 0;
	while (y < HEIGHT && y < end - 4)
	{
		xpm_y = ((1.0 * abs(y - start)) / abs(end - start) * xpm->hi);
		if (xpm_y > xpm->hi)
			xpm_y = xpm->hi - 1;
		my_pixel_put(inf, x, y, get_color(NULL, xpm_x, xpm_y, xpm));
		y++;
	}
}

/**
**	The Main Process of the raycasting which deals with pixel
**	put for ceiling, floor, walls
**/
void	init_rays(t_info *inf)
{
	t_ray		ray;
	static int	iter;

	ray.angle = inf->player->angle - (35 * RADIAN);
	ray.angle = fix_angle(ray.angle);
	ray.count = RAYS;
	ray.x1 = 0;
	ceiling_floor(inf);
	while (ray.count > 0)
	{
		inf->player->rays->spr = NULL;
		hit_wall_check(&ray, inf);
		if (inf->player->door_collide == 1 && inf->player->door_flag == 1
			&& inf->integrate == 1)
			inf->integrate = 1;
		else
			inf->integrate = 0;
		inf->player->rays[RAYS - ray.count].ang = ray.angle;
		revise_calc(NULL, &ray, inf, 0);
		place_walls(inf, &inf->player->rays[RAYS - ray.count],
			ray.x1);
		if (ray.token == 5)
		{
			inf->player->rays[RAYS - ray.count].spr = ray.spr;
			reverse_list(&ray);
			if (ray.spr && ray.spr != NULL)
				place_door(inf, &inf->data->xpm[DO], &ray, ray.x1);
			if (ray.spr && ray.spr != NULL)
				free_spr(ray.spr);
		}
		ray.x1 += 1;
		ray.count--;
	}
	init_cursor(inf);
}
