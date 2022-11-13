/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/13 20:09:47 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	place_vals_spr(t_info *inf, t_ray *ray)
{
	int	index;

	ray->spr->x_grid = ray->m_x;
	ray->spr->y_grid = ray->m_y;
	ray->spr->token = inf->data->map[ray->m_y][ray->m_x];
	if (ray->side == 0)
	{
		ray->spr->y_pos = new_y_val(inf, ray);
		ray->spr->x_pos = ray->x;
	}
	else
	{
		ray->spr->x_pos = new_x_val(inf, ray);
		ray->spr->y_pos = ray->y;
	}
	ray->spr->ang = ray->angle;
	ray->spr->dist = get_dist(ray->spr->x_pos, ray->spr->y_pos,
			inf->player->x_pos, inf->player->y_pos);
	ray->spr->height = get_height(ray->spr->dist, ray->spr->ang,
			inf->player->angle);
	index = lookup_door(inf, ray->spr->x_grid, ray->spr->y_grid);
	if (index >= 0 && (inf->doors[index].x_pos == ray->spr->x_grid)
		&& (inf->doors[index].y_pos == ray->spr->y_grid))
	{
		ray->spr->index = lookup_door(inf, ray->m_x, ray->m_y);
		ray->spr->open = inf->doors[ray->spr->index].open;
	}
}

void	working_spr(t_info *inf, t_ray *ray)
{
	t_sprite	*old;

	ray->spr_len++;
	if (ray->spr == NULL)
	{
		ray->spr = (t_sprite *)malloc(sizeof(t_sprite) * 2);
		ray->spr->next = NULL;
		ray->spr->prev = NULL;
	}
	else
	{
		ray->spr->next = (t_sprite *)malloc(sizeof(t_sprite) * 2);
		old = ray->spr;
		ray->spr = ray->spr->next;
		ray->spr->prev = old;
		ray->spr->next = NULL;
	}
	ray->token = 6;
	place_vals_spr(inf, ray);
}

/*
**	static int	iter;
**	if (!iter)
**		printf("X: %f, Y: %f\n", ray->spr->x_pos, ray->spr->y_pos);
**	iter++;
**	if (iter == 1920)
**		iter = 0;
*/