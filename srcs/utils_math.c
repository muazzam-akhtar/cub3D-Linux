/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:44:02 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/13 14:50:22 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

double	sq(double num)
{
	return (num * num);
}

double	get_dist(double x_one, double y_one, double x_two, double y_two)
{
	double	dist;

	dist = sqrt(sq(x_two - x_one) + sq(y_two - y_one));
	return (dist);
}

double	euclidean(t_ray *ray, double dist)
{
	double		real_dist;
	static int	rays;

	real_dist = 0;
	if ((ray->angle >= 145 * (PI / 180) && ray->angle < 225 * (PI / 180))
		|| (ray->angle >= 0 && ray->angle < 45 * (PI / 180))
		|| (ray->angle >= 315 * (PI / 180) && ray->angle < (2 * PI)))
		real_dist = cos(ray->angle) * dist;
	else
		real_dist = sin(ray->angle) * dist;
	if (real_dist < 0)
		real_dist *= -1;
	// printf("Rays: %d\tHypotenuse: %f\tOpposite: %f\tRayAngle: %f\n", rays + 1, dist, real_dist, ray->angle * (180 / PI));
	rays++;
	if (rays == 1920)
		rays = 0;
	return (real_dist);
}

double	get_height(double dist, double r_ang, double p_ang)
{
	double	height;
	double	c_angle;

	c_angle = r_ang - p_ang;
	if (c_angle < 0)
		c_angle += 2 * PI;
	height = (BLOCK_SIZE * 277) / dist;
	if (height > 1080)
		height = 1080;
	return (height);
}
