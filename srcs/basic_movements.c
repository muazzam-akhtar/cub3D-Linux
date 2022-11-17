/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:40:38 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/17 13:01:08 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Raycasting
*	Moving Forward
**/
void	move_frwrd(t_info *inf)
{
	int		row;
	int		col;
	double	x;
	double	y;

	inf->player->dx = cos(inf->player->angle) * inf->player->speed;
	inf->player->dy = sin(inf->player->angle) * inf->player->speed;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < ft_ptrptrlen(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos + inf->player->dx;
		col = inf->player->y_pos + inf->player->dy;
		if (inf->data->map[col][row] == '1' || (inf->player->wall.wall_front))
			return ;
		inf->data->map[(int)inf->player->y_pos][(int)inf->player->x_pos] = '0';
		inf->player->x_pos += inf->player->dx;
		inf->player->y_pos += inf->player->dy;
		inf->data->map[col][row] = 'P';
	}
}

/**
**	Raycasting
*	Moving Backward
**/
void	move_back(t_info *inf)
{
	int		row;
	int		col;
	double	x;
	double	y;

	inf->player->dx = cos(inf->player->angle) * inf->player->speed;
	inf->player->dy = sin(inf->player->angle) * inf->player->speed;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < ft_ptrptrlen(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos - inf->player->dx;
		col = inf->player->y_pos - inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_back)
			return ;
		inf->data->map[(int)inf->player->y_pos][(int)inf->player->x_pos] = '0';
		inf->player->x_pos -= inf->player->dx;
		inf->player->y_pos -= inf->player->dy;
		inf->data->map[col][row] = 'P';
	}
}

/**
**	Raycasting
*	Moving Left
**/
void	move_left(t_info *inf)
{
	int		row;
	int		col;
	double	x;
	double	y;

	inf->player->dx = cos((PI / 2) + (inf->player->angle)) * inf->player->speed;
	inf->player->dy = sin((PI / 2) + (inf->player->angle)) * inf->player->speed;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < ft_ptrptrlen(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos - inf->player->dx;
		col = inf->player->y_pos - inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_left)
			return ;
		inf->data->map[(int)inf->player->y_pos][(int)inf->player->x_pos] = '0';
		inf->player->x_pos -= inf->player->dx;
		inf->player->y_pos -= inf->player->dy;
		inf->data->map[col][row] = 'P';
	}
}

/**
**	Raycasting
*	Moving Right
**/
void	move_right(t_info *inf)
{
	int		row;
	int		col;
	double	x;
	double	y;

	inf->player->dx = cos((PI / 2) + (inf->player->angle)) * inf->player->speed;
	inf->player->dy = sin((PI / 2) + (inf->player->angle)) * inf->player->speed;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < ft_ptrptrlen(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos + inf->player->dx;
		col = inf->player->y_pos + inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_right)
			return ;
		inf->data->map[(int)inf->player->y_pos][(int)inf->player->x_pos] = '0';
		inf->player->x_pos += inf->player->dx;
		inf->player->y_pos += inf->player->dy;
		inf->data->map[col][row] = 'P';
	}
}

/**
**	Raycasting
*	Rotate Left or Right
**/
void	rotation(int hook_num, t_info *inf)
{
	if (hook_num == ARROW_R)
	{
		inf->player->angle += ROT_SPEED;
		if (inf->player->angle > 2 * PI)
			inf->player->angle -= 2 * PI;
	}
	if (hook_num == ARROW_L)
	{
		inf->player->angle -= ROT_SPEED;
		if (inf->player->angle < 0)
			inf->player->angle += 2 * PI;
	}
}
