/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_coll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:05:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/11 14:24:38 by makhtar          ###   ########.fr       */
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

static void	handle_sprite_coll(t_info *inf)
{
	if (inf->player->wall.row == inf->doors[lookup_door(inf,
				inf->player->wall.row, inf->player->wall.col)].m_x
		&& inf->player->wall.col == inf->doors[lookup_door(inf,
				inf->player->wall.row, inf->player->wall.col)].m_y)
		inf->player->door_collide = 1;
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
		inf->player->wall.x = inf->player->x_pos + (cos(angle) * 0.125);
		inf->player->wall.y = inf->player->y_pos + (sin(angle) * 0.125);
		inf->player->wall.row = (int)inf->player->wall.x;
		inf->player->wall.col = (int)inf->player->wall.y;
		if (!inf->data->map[inf->player->wall.col][inf->player->wall.row]
			|| (inf->data->map[inf->player->wall.col][inf->player->wall.row]
			&& inf->data->map[inf->player->wall.col][inf->player->wall.row]
			== '1'))
			*wall_trigger = 1;
		handle_sprite_coll(inf);
		angle += (10 * PI / 180);
		if (angle > 2 * PI)
			angle -= 2 * PI;
		inf->player->wall.count--;
	}
}

void	handle_wall_collision(t_info *inf)
{
	double	angle;

	wall_coll(inf, &inf->player->wall.wall_front, inf->player->angle);
	angle = inf->player->angle - PI;
	if (angle < 0)
		angle += 2 * PI;
	wall_coll(inf, &inf->player->wall.wall_back, angle);
	angle = inf->player->angle + (PI / 2);
	if (angle > 2 * PI)
		angle -= 2 * PI;
	wall_coll(inf, &inf->player->wall.wall_right, angle);
	angle = inf->player->angle + (3 * PI / 2);
	if (angle > 2 * PI)
		angle -= 2 * PI;
	wall_coll(inf, &inf->player->wall.wall_left, angle);
}
