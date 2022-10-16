/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/16 19:32:07 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_sprite	**check_sprite(t_sprite **spr, t_ray *ray, t_info *inf)
{
	// static int	x_grid;
	// static int	y_grid;
	// static int	i;
	t_sprite	**new_spr;

	new_spr = NULL;
	if (key_sprite(inf->data->map[(int)ray->y][(int)ray->x]) == TRUE)
	{
		if (*spr == NULL)
			*spr = malloc(sizeof(t_sprite) * 2);
		else
			new_spr = new_alloc_sprite(spr);
		// dup_values((*(&new[count])), NULL, ray);
	}
	return (NULL);
}
