/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:44:02 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/08 18:48:44 by makhtar          ###   ########.fr       */
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

double	euclidean(t_ray *ray, double dist, double p_ang)
{
	double		real_dist;
	static int	rays;

	real_dist = 0;
	real_dist = cos(ray->angle - p_ang) * dist;
	if (real_dist < 0)
		real_dist *= -1;
	rays++;
	if (rays == RAYS)
		rays = 0;
	return (real_dist);
}

/**
*	
**/
double	get_height(double dist, double r_ang, double p_ang)
{
	double	height;
	double	c_angle;

	c_angle = r_ang - p_ang;
	if (c_angle < 0)
		c_angle += 2 * PI;
	height = (BLOCK_SIZE * 277) / dist;
	return (height);
}
