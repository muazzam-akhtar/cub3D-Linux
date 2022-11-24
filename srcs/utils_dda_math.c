/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dda_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:45 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/24 19:04:55 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static double	dda_x(double new_x, double old_x, double old_y, double ang)
{
	double	y;
	double	diff;

	diff = new_x - old_x;
	y = ((diff) * tan(ang)) + old_y;
	return (y);
}

static double	dda_y(double new_y, double old_y, double old_x, double ang)
{
	double	x;
	double	diff;

	diff = new_y - old_y;
	x = (diff / tan(ang)) + old_x;
	return (x);
}

double	new_y_val(t_info *inf, t_ray *ray)
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
	return (ray->y);
}

double	new_x_val(t_info *inf, t_ray *ray)
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
	return (ray->x);
}

int	calc_digits(int num)
{
	int	count;

	count = 0;
	if (num < 10)
		return (1);
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
