/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/18 18:47:01 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_sprite(t_ray *ray, t_info *inf)
{
	static int		x_grid;
	static int		y_grid;
	static double	ang;
	static int		i;
	t_sprite		**new_spr;

	new_spr = NULL;
	if (ang != ray->angle)
		ang = ray->angle;
	if (((int)ray->x == x_grid) && ((int)ray->y == y_grid)
		&& (ang == ray->angle))
		return ;
	if (key_sprite(inf->data->map[(int)ray->y][(int)ray->x]) == TRUE)
	{
		if (inf->spr == NULL)
			inf->spr = (t_sprite **)malloc(sizeof(t_sprite *) * 2);
		printf("Sprite check\n");
		x_grid = (int)ray->x;
		y_grid = (int)ray->y;
		inf->spr[i + 1] = NULL;
	}
}
