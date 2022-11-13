/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:28 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/13 19:04:23 by makhtar          ###   ########.fr       */
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
	size_t		rgb;
	static int	iter;

	rgb = 0x00FFFFFF;
	// 0X00FFFF00
	if (status == 0)
	{
		rgb = data->ceil.red << 16 & rgb;
		// if (!iter)
		// 	printf("%#x\n", (unsigned int)rgb);
		rgb -= data->ceil.green >> 8 & rgb;
		rgb -= data->ceil.blue & rgb;
	}
	if (status == 1)
	{
		rgb += data->floor.red << 16 & rgb;
		rgb += data->floor.green << 8 & rgb;
		rgb += data->floor.blue & rgb;
	}
	iter++;
	if (iter == 1920)
		iter = 0;
	return (rgb);
}
