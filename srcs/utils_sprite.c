/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:02:45 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/18 18:35:46 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_sprite(int c)
{
	if (c == 'U')
		return (TRUE);
	else if (c == 'V')
		return (TRUE);
	else if (c == 'W')
		return (TRUE);
	else if (c == 'D')
		return (TRUE);
	return (FALSE);
}

void	dup_values(t_sprite *new_spr, t_sprite *old_spr, t_ray *ray)
{
	if (old_spr != NULL)
	{
		new_spr->ang = old_spr->ang;
		new_spr->dist = old_spr->dist;
		new_spr->height = old_spr->height;
		new_spr->x_grid = old_spr->x_grid;
		new_spr->x_pos = old_spr->x_pos;
		new_spr->y_grid = old_spr->y_grid;
		new_spr->y_pos = old_spr->y_pos;
	}
	else
	{
		new_spr->ang = ray->angle;
		new_spr->x_grid = (int)ray->x;
		new_spr->x_pos = ray->x;
		new_spr->y_grid = (int)ray->y;
		new_spr->y_pos = ray->y;
	}
}

// t_sprite	**new_alloc_sprite(t_sprite **old_spr, t_info *inf)
// {
// 	int			count;
// 	t_sprite	**new;

// 	count = 0;
// 	while (old_spr[count] != NULL)
// 		count++;
// 	new = (t_sprite **)malloc(sizeof(t_sprite *) * (count + 1));
// 	if (new == NULL)
// 		return (NULL);
// 	count = 0;
// 	while (old_spr[count] != NULL)
// 	{
// 		dup_values((*(&new[count])), (*(&old_spr[count])), NULL);
// 		count++;
// 	}
// 	new[count] = NULL;
// 	return (new);
// }
