/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:29:35 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/19 19:29:36 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

double	fix_angle(double ang)
{
	if (ang < 0)
		return (ang + (2 * PI));
	else if (ang > (2 * PI))
		return (ang - (2 * PI));
	return (ang);
}
