/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:09:32 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/10 18:05:24 by makhtar          ###   ########.fr       */
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
	return (EXIT_FAILURE);
}
