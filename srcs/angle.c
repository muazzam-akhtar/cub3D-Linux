/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:29:35 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/28 15:45:50 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Sets angle to correct value if angle is
**	<0 or angle is >360
**/
double	fix_angle(double ang)
{
	if (ang < 0)
		return (ang + (2 * PI));
	else if (ang > (2 * PI))
		return (ang - (2 * PI));
	return (ang);
}
