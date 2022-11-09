/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:33:53 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/09 18:52:53 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	mouse_click(int keycode, int x, int y, t_info *info)
{
	int	counter;
	static int	trig;

	if (keycode == 1)
	{
		if (!trig)
		{
			draw_minimap(info, info->mini);
			mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
			mlx_put_image_to_window(info->mlx, info->win, info->mini_map, 30, 30);
			mlx_put_image_to_window(info->mlx, info->win,
				info->data->gun_anim, WIDTH - HEIGHT, (HEIGHT / 2));
			trig = 1;
		}
		else
		{
			draw_minimap(info, info->mini);
			mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
			mlx_put_image_to_window(info->mlx, info->win, info->mini_map, 30, 30);
			mlx_put_image_to_window(info->mlx, info->win,
				info->data->gun, WIDTH - HEIGHT, (HEIGHT / 2));
			trig = 0;
		}
	}
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
}
