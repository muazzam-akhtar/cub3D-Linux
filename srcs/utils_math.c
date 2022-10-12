/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:44:02 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/12 14:09:58 by hawadh           ###   ########.fr       */
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

double	euclidean(t_ray *ray, t_info *inf, double dist)
{
	double	real_dist;

	(void)inf;
	real_dist = sin(ray->angle) * dist;
	if (real_dist < 0)
		real_dist = sin(ray->angle) / dist;
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
