/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:42:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/03 17:12:36 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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

static void	init_walls_ray(t_ray *ray, t_info *inf)
{
	ray->x = inf->player->x_pos;
	ray->y = inf->player->y_pos;
	ray->wall = 0;
	ray->grid_x = (int)ray->x;
	ray->grid_y = (int)ray->y;
	while (!ray->wall)
	{
		ray->x += (cos(ray->angle) * 0.01);
		ray->y += (sin(ray->angle) * 0.01);
		ray->wall = check_wall(inf, ray->x, ray->y);
		// if (!ray->wall && (ray->grid_x != (int)ray->x
		// 		&& ray->grid_y != (int)ray->y))
		// 	ray->wall = edge_case(ray->x, ray->y, ray->grid_x,
		// 			ray->grid_y, inf);
	}
	inf->player->rays[1920 - ray->count].x = ray->x;
	inf->player->rays[1920 - ray->count].y = ray->y;
	inf->player->rays[1920 - ray->count].dist = get_dist(inf->player->x_pos,
			inf->player->y_pos, ray->x, ray->y);
	inf->player->rays[1920 - ray->count].height = (BLOCK_SIZE * 277)
		/ inf->player->rays[1920 - ray->count].dist;
	if (inf->player->rays[1920 - ray->count].height > 1080)
		inf->player->rays[1920 - ray->count].height = 1080;
	ray->y = 540 - (inf->player->rays[1920 - ray->count].height / 2);
}

void	init_rays(t_info *inf)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray.angle = inf->player->angle - (35 * RADIAN);
	if (ray.angle < 0)
		ray.angle += 2 * PI;
	ray.count = 1920;
	ray.x1 = 0;
	ceiling_floor(inf);
	while (ray.count > 0)
	{
		init_walls_ray(&ray, inf);
		if (inf->player->rays[1920 - ray.count].height < 370)
			inf->player->rays[1920 - ray.count].height = 370;
		ray.y = 540 - (inf->player->rays[1920 - ray.count].height / 2);
		inf->player->rays[1920 - ray.count].ang = ray.angle;
		ray.angle += 0.000636318; // (PI / 180) * (60 / RAYS)
		if (ray.angle > 2 * PI)
			ray.angle -= 2 * PI;
		if (ray.x1 > 1920)
			ray.x1 = 1920;
		while (x < ray.x1 || (ray.x1 == 0 && x == 0))
			place_walls(inf, &inf->player->rays[1920 - ray.count], x++);
		ray.x1 += 1; // 11.6 * (60 / RAYS)
		ray.count--;
	}
	init_cursor(inf);
}
