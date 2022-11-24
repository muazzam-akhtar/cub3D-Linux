/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:28 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/23 19:49:42 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Calculates colour based on status
*	status == 0;	ceiling colour
*	status == 1;	floor colour
**/
size_t	rgb(t_data *data, int status)
{
	u_int32_t	rgb;
	u_int32_t	col;

	rgb = 0xFFFFFFFF;
	if (status == 0)
	{
		col = ((rgb >> 16 & data->ceil.red) << 8);
		col += (rgb >> 8 & data->ceil.green);
		col = col << 8;
		col += (data->ceil.blue & rgb);
	}
	if (status == 1)
	{
		col = ((rgb >> 16 & data->floor.red) << 8);
		col += (rgb >> 8 & data->floor.green);
		col = col << 8;
		col += (data->floor.blue & rgb);
	}
	return (col);
}
