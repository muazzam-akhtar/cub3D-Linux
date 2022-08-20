/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:28 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/12 18:10:43 by hawadh           ###   ########.fr       */
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
	size_t	rgb;

	rgb = 0x00FFFFFF;
	if (status == 0)
	{
		rgb += data->ceil.red << 16 & rgb;
		rgb += data->ceil.green << 8 & rgb;
		rgb += data->ceil.blue & rgb;
	}
	if (status == 1)
	{
		rgb += data->floor.red << 16 & rgb;
		rgb += data->floor.green << 8 & rgb;
		rgb += data->floor.blue & rgb;
	}
	return (rgb);
}
