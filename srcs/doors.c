/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:09:32 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/28 12:13:14 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	lookup_door(t_info *inf, int x, int y)
{
	int	i;

	i = 0;
	while (i < inf->n_doors)
	{
		if (y == inf->doors[i].m_y && x == inf->doors[i].m_x)
			return (i);
		i++;
	}
	return (-1);
}

/**
**	Resets and re-places door characters on map after player moves
**	through them.
*
*	Closed doors	:	'D'
*	Open doors		:	'O'
*
**/
void	reset_doors(t_info *info)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (i < info->n_doors)
	{
		x = info->doors[i].m_x;
		y = info->doors[i].m_y;
		if (info->data->map[info->doors[i].m_y][info->doors[i].m_x]
			!= 'P')
		{
			if (info->doors[i].open == false)
				info->data->map[y][x] = 'D';
			else
				info->data->map[y][x] = 'O';
		}
		i++;
	}
}
