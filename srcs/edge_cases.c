/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:49 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/04 15:31:20 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	top_left(t_info *vars, int c_x, int c_y)
{
	if ((c_x + 1 < ft_strlen_int(vars->data->map[c_y]))
		&& (vars->data->map[c_y][c_x + 1] == '1'))
	{
		if ((c_y + 1 < get_2d_len(vars->data->map))
			&& (vars->data->map[c_y + 1][c_x] == '1'))
			return (1);
	}
	return (0);
}

static int	bot_right(t_info *vars, int c_x, int c_y)
{
	if ((c_x - 1 >= 0) && (vars->data->map[c_y][c_x - 1] == '1'))
	{
		if ((c_y - 1 >= 0) && (vars->data->map[c_y - 1][c_x] == '1'))
			return (1);
	}
	return (0);
}

static int	top_right(t_info *vars, int c_x, int c_y)
{
	if ((c_x - 1 >= 0) && (vars->data->map[c_y][c_x - 1] == '1'))
	{
		if ((c_y + 1 < get_2d_len(vars->data->map))
			&& (vars->data->map[c_y + 1][c_x] == '1'))
			return (1);
	}
	return (0);
}

int	edge_case(double x, double y, t_info *vars)
{
	int	c_x;
	int	c_y;

	c_x = (int)x;
	c_y = (int)y;
	if ((vars->player->x_pos > (int)x) && (vars->player->y_pos > (int)y))
		return (top_left(vars, c_x, c_y));
	else if (vars->player->x_pos < (int)x && vars->player->y_pos < (int)y)
		return (bot_right(vars, c_x, c_y));
	else if (vars->player->x_pos < (int)x && vars->player->y_pos > (int)y)
		return (top_right(vars, c_x, c_y));
	else if (vars->player->x_pos > (int)x && vars->player->y_pos < (int)y)
	{
		if ((c_x + 1 < ft_strlen_int(vars->data->map[c_y]))
			&& (vars->data->map[c_y][c_x + 1] == '1'))
		{
			if ((c_y - 1 >= 0) && (vars->data->map[c_y - 1][c_x] == '1'))
				return (1);
		}
		return (0);
	}
	return (0);
}
