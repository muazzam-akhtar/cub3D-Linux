/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:33:53 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/25 18:57:05 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	gun_animation(t_info *info)
{
	draw_minimap(info, info->mini);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win,
		info->mini_map, 30, 30);
	mlx_put_image_to_window(info->mlx, info->win,
		info->data->gun, (WIDTH / 2) - 75, (HEIGHT / 2));
}

int	mouse_click(int keycode, int x, int y, t_info *info)
{
	static int	trig;

	(void)x;
	(void)y;
	if (keycode == 1 && info->mouse->flag == 0)
	{
		if (!trig)
		{
			draw_minimap(info, info->mini);
			mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
			mlx_put_image_to_window(info->mlx, info->win,
				info->mini_map, 30, 30);
			info->fire = 1;
			gun_image(info);
			trig = 1;
		}
		else
		{
			info->fire = 0;
			gun_animation(info);
			trig = 0;
		}
	}
	return (EXIT_SUCCESS);
}

static void	get_door(t_info *info, double *x, double *y)
{
	int	index;

	index = 0;
	while ((int)(*x) == (int)info->player->x_pos
		&& (int)(*y) == (int)info->player->y_pos)
	{
		*x += cos(info->player->angle) * 0.1;
		*y += sin(info->player->angle) * 0.1;
		index++;
		if (index == 8)
		{
			info->integrate = 0;
			return ;
		}
	}
}

static int	animate(t_info *info)
{
	double		x;
	double		y;
	int			index;

	if (info->integrate == 1)
	{
		x = info->player->x_pos;
		y = info->player->y_pos;
		index = lookup_door(info, (int)x, (int)y);
		if (index == -1)
		{
			get_door(info, &x, &y);
			index = lookup_door(info, (int)x, (int)y);
			if (index >= 0 && info->integrate == 1)
			{
				info->doors[index].open = !info->doors[index].open;
				key_hook_manage(E, info);
			}
		}
		info->integrate = 0;
	}
	reset_doors(info);
	return (EXIT_SUCCESS);
}

/**
**	Manages Key and Mouse hook events
**/
void	hook_management(t_info *info)
{
	mlx_hook(info->win, 2, (1L << 0), key_hook_manage, info);
	mlx_hook(info->win, 17, (1L << 17), esc_win, info);
	mlx_hook(info->win, 6, (1L << 6), mouse_move, info);
	mlx_hook(info->win, 4, (1L << 0), mouse_click, info);
	mlx_hook(info->win, 5, (1L << 0), mouse_click, info);
	mlx_loop_hook(info->mlx, animate, info);
}
