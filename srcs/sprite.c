/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/09 20:22:47 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	working_spr(t_info *inf, t_ray *ray)
{
	(void)inf;
	(void)ray;
	if (ray->spr == NULL)
	{
		ray->spr_len++;
		ray->spr = (t_sprite *)malloc(sizeof(t_sprite) * 2);
		ray->spr->next = NULL;
		ray->spr->prev = NULL;
	}
}
