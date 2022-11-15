/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:45:56 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/15 22:40:24 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	mini_img_limit(t_info *info, int y, int x, char status)
{
	int	y_one;
	int	x_one;

	y = y - MINI_DIM + extract_decimal(info->player, 'y');
	y_one = MINI_DIM + extract_decimal(info->player, 'y');
	if (status == 'y' && !(y < y_one))
		return (0);
	x = x - MINI_DIM + extract_decimal(info->player, 'x');
	x_one = MINI_DIM + extract_decimal(info->player, 'x');
	if (status == 'x' && !(x < y_one))
		return (0);
	return (1);
}

/**
**	Extracts x & y values
**/
int	x_y_values(int index)
{
	if (index < 0)
		return ((index * MINI_SCALE - 15) * -1);
	return (MINI_SCALE - 15);
}

int	assign_index_values(int index)
{
	if (index < 0)
		return (0);
	return (index);
}
