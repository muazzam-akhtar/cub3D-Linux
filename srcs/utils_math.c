/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:44:02 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/03 16:44:03 by makhtar          ###   ########.fr       */
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
