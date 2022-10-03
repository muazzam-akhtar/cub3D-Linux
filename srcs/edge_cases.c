/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:49 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/03 17:23:59 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	edge_case(double x, double y, int g_x, int g_y, t_info *vars)
{
	int	c_x;
	int	c_y;

	c_x = (int)x;
	c_y = (int)y;
	printf("Check X: %d, Check Y: %d\n", c_x, c_y);
	// printf("Double X: %d, Double Y: %d, Grid_X: %d, Grid_Y: %d\n", (int)x, (int)y, g_x, g_y);
	// printf("Player X: %d, Player Y: %d\n", (int)vars->p.x_co, (int)vars->p.y_co);
	if ((vars->player->x_pos > (int)x) && (vars->player->y_pos > (int)y))
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
	else if (vars->player->x_pos < (int)x && vars->player->y_pos < (int)y)
	{
		if ((c_x - 1 >= 0) && (vars->data->map[c_y][c_x - 1] == '1'))
		{
			if ((c_y - 1 >= 0) && (vars->data->map[c_y - 1][c_x] == '1'))
				return (1);
		}
		return (0);
	}
	else if (vars->player->x_pos < (int)x && vars->player->y_pos > (int)y)
	{
		if ((c_x - 1 >= 0) && (vars->data->map[c_y][c_x - 1] == '1'))
		{
			if ((c_y + 1 < get_2d_len(vars->data->map))
				&& (vars->data->map[c_y + 1][c_x] == '1'))
				return (1);
		}
		return (0);
	}
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
