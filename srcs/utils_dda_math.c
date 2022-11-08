/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_math_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:48:02 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/08 19:31:31 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

double	dda_x(double new_x, double old_x, double old_y, double ang)
{
	double	y;
	double	diff;

	diff = new_x - old_x;
	y = ((diff) * tan(ang)) + old_y;
	return (y);
}

double	dda_y(double new_y, double old_y, double old_x, double ang)
{
	double	x;
	double	diff;

	diff = new_y - old_y;
	x = (diff / tan(ang)) + old_x;
	return (x);
}
