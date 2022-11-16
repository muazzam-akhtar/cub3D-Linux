/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_coll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:05:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/16 19:59:15 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_wall_coll(t_wall *inf)
{
	inf->count = 7;
	inf->row = 0;
	inf->col = 0;
	inf->x = 0;
	inf->y = 0;
	inf->angle = 0;
}

static void	handle_sprite_coll(t_info *inf, int *wall_trigger)
{
	int	index;

	index = lookup_door(inf, inf->player->wall.row, inf->player->wall.col);
	if (index >= 0 && inf->player->wall.row == inf->doors[index].m_x
		&& inf->player->wall.col == inf->doors[index].m_y)
	{
		if (inf->doors[index].open == 0)
			*wall_trigger = 1;
	}
}

void	wall_coll(t_info *inf, int *wall_trigger, double angle)
{
	init_wall_coll(&inf->player->wall);
	*wall_trigger = 0;
	angle -= (30 * RADIAN);
	if (angle < 0)
		angle += 2 * PI;
	inf->player->door_collide = 0;
	while (inf->player->wall.count > 0)
	{
		inf->player->wall.x = inf->player->x_pos + (cos(angle) * 0.25);
		inf->player->wall.y = inf->player->y_pos + (sin(angle) * 0.25);
		inf->player->wall.row = (int)inf->player->wall.x;
		inf->player->wall.col = (int)inf->player->wall.y;
		if (!inf->data->map[inf->player->wall.col][inf->player->wall.row]
			|| (inf->data->map[inf->player->wall.col][inf->player->wall.row]
			&& inf->data->map[inf->player->wall.col][inf->player->wall.row]
			== '1'))
			*wall_trigger = 1;
		else
			handle_sprite_coll(inf, wall_trigger);
		angle += (10 * PI / 180);
		angle = fix_angle(angle);
		inf->player->wall.count--;
	}
}

void	handle_wall_collision(t_info *inf)
{
	double	angle;
	int		collider;

	wall_coll(inf, &inf->player->wall.wall_front, inf->player->angle);
	collider = inf->player->door_collide;
	angle = inf->player->angle - PI;
	angle = fix_angle(angle);
	wall_coll(inf, &inf->player->wall.wall_back, angle);
	angle = inf->player->angle + (PI / 2);
	angle = fix_angle(angle);
	wall_coll(inf, &inf->player->wall.wall_right, angle);
	angle = inf->player->angle + (3 * PI / 2);
	angle = fix_angle(angle);
	wall_coll(inf, &inf->player->wall.wall_left, angle);
	inf->player->door_collide = collider;
}
