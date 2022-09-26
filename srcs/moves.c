/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:11 by makhtar           #+#    #+#             */
/*   Updated: 2022/09/26 15:59:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_2d_len(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

/**
**	Raycasting
*	Moving Forward
**/
void	move_frwrd(t_info *inf)
{
	int	row;
	int	col;
	double	x;
	double	y;

	inf->player->dx = cos(inf->player->angle) * 0.0556;
	inf->player->dy = sin(inf->player->angle) * 0.0556;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < get_2d_len(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos + inf->player->dx;
		col = inf->player->y_pos + inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_front)
		{
			// draw_point(vars, (vars->p.x_co * 87) + 700, (vars->p.y_co * 87));
			return ;
		}
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
	int	row;
	int	col;
	double	x;
	double	y;

	inf->player->dx = cos(inf->player->angle) * 0.0556;
	inf->player->dy = sin(inf->player->angle) * 0.0556;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < get_2d_len(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos - inf->player->dx;
		col = inf->player->y_pos - inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_back)
		{
			// draw_point(vars, (vars->p.x_co * 87) + 700, (vars->p.y_co * 87));
			return ;
		}
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
	int	row;
	int	col;
	double	x;
	double	y;

	inf->player->dx = cos((PI / 2) + (inf->player->angle)) * 0.0556;
	inf->player->dy = sin((PI / 2) + (inf->player->angle)) * 0.0556;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < get_2d_len(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos - inf->player->dx;
		col = inf->player->y_pos - inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_left)
		{
			// draw_point(vars, (vars->p.x_co * 87) + 700, (vars->p.y_co * 87));
			return ;
		}
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
	int	row;
	int	col;
	double	x;
	double	y;

	inf->player->dx = cos((PI / 2) + (inf->player->angle)) * 0.0556;
	inf->player->dy = sin((PI / 2) + (inf->player->angle)) * 0.0556;
	y = inf->player->y_pos + inf->player->dy;
	x = inf->player->x_pos + inf->player->dx;
	if ((y >= 0) && (y < get_2d_len(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = inf->player->x_pos + inf->player->dx;
		col = inf->player->y_pos + inf->player->dy;
		if (inf->data->map[col][row] == '1' || inf->player->wall.wall_right)
		{
			// draw_point(vars, (vars->p.x_co * 87) + 700, (vars->p.y_co * 87));
			return ;
		}
		inf->data->map[(int)inf->player->y_pos][(int)inf->player->x_pos] = '0';
		inf->player->x_pos += inf->player->dx;
		inf->player->y_pos += inf->player->dy;
		inf->data->map[col][row] = 'P';
	}
}

/**
**	Raycasting
*	Rotate Left
**/
void	rotation(int hook_num, t_info *inf)
{
	if (hook_num == ARROW_R)
	{
		inf->player->angle += 0.1;
		if (inf->player->angle > 2 * PI)
			inf->player->angle -= 2 * PI;
	}
	if (hook_num == ARROW_L)
	{
		inf->player->angle -= 0.1;
		if (inf->player->angle < 0)
			inf->player->angle += 2 * PI;	
	}
}

double	sq(double num)
{
	return (num * num);
}

double	get_dist(double x_one, double y_one, double x_two, double y_two)
{
	double	dist;

	dist = sqrt(sq(x_two - x_one) + sq(y_two - y_one));
	return (dist);
}

int	check_wall(t_info *inf, double x, double y)
{
	int	col;
	int	row;

	if ((y >= 0) && (y < get_2d_len(inf->data->map))
		&& (x >= 0 && x < ft_strlen(inf->data->map[(int)y])))
	{
		row = (int)x;
		col = (int)y;
		if (inf->data->map[col][row] == '1')
			return (1);
		return (0);
	}
	return (1);
}

void	init_walls_ray(t_ray *ray, t_info *inf)
{
	ray->x = inf->player->x_pos;
	ray->y = inf->player->y_pos;
	ray->wall = 0;
	ray->grid_x = (int)ray->x;
	ray->grid_y = (int)ray->y;
	while (!ray->wall)
	{
		ray->x += (cos(ray->angle) * 0.01);
		ray->y += (sin(ray->angle) * 0.01);
		ray->wall = check_wall(inf, ray->x, ray->y);
		// if (!ray->wall && (ray->grid_x != (int)ray->x && ray->grid_y != (int)ray->y))
		// 	ray.wall = edge_case(ray->x, ray->y, ray->grid_x, ray->grid_y, inf);
	}
	inf->player->rays[120 - ray->count].x = ray->x;
	inf->player->rays[120 - ray->count].y = ray->y;
	inf->player->rays[120 - ray->count].dist = get_dist(inf->player->x_pos, inf->player->y_pos, ray->x, ray->y);
	inf->player->rays[120 - ray->count].height = (BLOCK_SIZE * 1080) / (inf->player->rays[120 - ray->count].dist * 310);
	if (inf->player->rays[120 - ray->count].height > 1080)
		inf->player->rays[120 - ray->count].height = 1080;
	ray->y = 540 - (inf->player->rays[120 - ray->count].height / 2);
}

void	init_rays(t_info *inf)
{
	t_ray	ray;

	ray.angle = inf->player->angle - (33 * RADIAN);
	if (ray.angle < 0)
		ray.angle += 2 * PI;
	ray.count = 120;
	ray.x1 = 0;
	while (ray.count > 0)
	{
		init_walls_ray(&ray, inf);
		if (inf->player->rays[120 - ray.count].height > 1080)
			inf->player->rays[120 - ray.count].height = 1080;
		ray.y = 540 - (inf->player->rays[120 - ray.count].height / 2);
		// make_wall(inf, &ray.x1, &ray.y);
		ray.angle += 0.009603175; // (PI / 180) * (70 / RAYS)
		if (ray.angle > 2 * PI)
			ray.angle -= 2 * PI;
		ray.x1 += 6.38; // 11.6 * (70 / RAYS)
		ray.count--;
	}
}

/**
**	Main Raycasting
*	Handle Moves- W, S, A, D
*	Handle Rotations- Left and Right
**/
void	moves(int hook_num, t_info *inf)
{
	handle_wall_collision(inf);
	if (hook_num == W)
		move_frwrd(inf);
	else if (hook_num == S)
		move_back(inf);
	else if (hook_num == A)
		move_left(inf);
	else if (hook_num == D)
		move_right(inf);
	else if (hook_num == ARROW_L || hook_num == ARROW_R)
		rotation(hook_num, inf);
	handle_wall_collision(inf);
	init_rays(inf);
}